#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define ERROR -1
#define MAX_CLIENTS 2
#define MAX_DATA 1024

int main(int argc, int **argv){
	int sockfd, clientfd;					// File descriptors
	struct sockaddr_in server, client;		// Sockaddr_in structure
	int len;								// length of sockaddr_in structure
	char data[MAX_DATA];
	char msg[] = "Hello! This is an Assassin\n";
	int bytes_sent;							// No of bytes sent
	int tr=1;								// Integer for setsockopt

    // Creating Socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR){
		perror("Socket error");
		exit(ERROR);
	}

	// Assigning addresses
	server.sin_family = AF_INET;			// IPv4
	server.sin_port = htons(atoi(argv[1])); // Port in network bytes
	server.sin_addr.s_addr = INADDR_ANY;	// All available interfaces
	bzero(&server.sin_zero, 8);				// Zero padding

	len = sizeof(struct sockaddr_in);

	// Kill "Address already in use" error message
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &tr, sizeof(int)) == ERROR) {
    	perror("setsockopt");
    	exit(ERROR);
	}

	// Bind to the address
	if((bind(sockfd, (struct sockaddr *)&server, len)) == ERROR){
		perror("Bind error");
		exit(ERROR);
	}

	//Listen for connections
	if((listen(sockfd, MAX_CLIENTS)) == ERROR){
		perror("Listen error");
		exit(ERROR);
	}

	// Start listening to the clients 
	while(1){

		// Accept connection from a client and return the new socket
		if((clientfd = accept(sockfd, (struct sockaddr *)&client, &len)) == ERROR){
			perror("Accept error");
			exit(ERROR);
		}

		// Print the connection information
		printf("New client connected from port no %d and IP %s\n", 
			ntohs(client.sin_port), inet_ntoa(client.sin_addr));

		// Send the message after connection completes
		if((bytes_sent = send(clientfd, msg, strlen(msg), 0)) == ERROR){
			perror("Send error");
			exit(ERROR);
		}

		printf("Sent %d bytes to Client %s\n", 
			bytes_sent, inet_ntoa(client.sin_addr));

		int data_len = 1;

		// Keep sending the same data till no response from client
		while(data_len){
			data_len = recv(clientfd, data, MAX_DATA , 0);

			if(data_len){
				send(clientfd, data, data_len, 0);
				data[data_len] = '\0';
				printf("Sent message: %s\n", data);
			}
		}

		printf("Client disconnected");

		// Close the connection
		close(clientfd);
	}
}