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
#define BUFFER 1024

int main(int argc, char **argv){
	struct sockaddr_in server;
	int sockfd, len, bytes_recv;
	char input[BUFFER], output[BUFFER];

	len = sizeof(struct sockaddr_in);

	// Creating Socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR){
		perror("Socket error");
		exit(ERROR);
	}

	// Assigning addresses
	server.sin_family = AF_INET;					// IPv4
	server.sin_port = htons(atoi(argv[2])); 		// Port in network bytes
	server.sin_addr.s_addr = inet_addr(argv[1]);	// All available interfaces
	bzero(&server.sin_zero, 8);						// Zero padding

	// Connect to server
	if((connect(sockfd, (struct sockaddr *)&server, len)) == ERROR){
		perror("Connect error");
		exit(ERROR);
	}

	while(1){
		fgets(input, BUFFER, stdin);
		send(sockfd, input, strlen(input), 0);

		bytes_recv = recv(sockfd, output, BUFFER, 0);
		output[bytes_recv] = '\0';
		printf("%s\n", output);
	}

	close(sockfd);




}