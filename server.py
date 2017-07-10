import socket
import sys


# Create a socket (Connect two computers)
def socket_create():
    try:
        global host
        global port
        global s

        host = ''
        port = 8888
        s = socket.socket()

    except socket.error as msg:
        print('Socket Creation Error: ' + str(msg))


# Bind socket to Port and listen to connection
def socket_bind():
    try:
        global host
        global port
        global s

        print("Binding to the Port " + str(port))

        s.bind((host, port))
        s.listen(5)

    except socket.error as msg:
        print('Socket Binding Error: ' + str(msg) + '\n' + 'Retrying...')
        socket_bind()


# Establish a connection with the client (socket must be listening)
def socket_accept():
    conn, address = s.accept()
    print("Connection has been established | " + "IP " + address[0] + " | Port " + str(address[1]))

    send_commands(conn)
    s.close()


# Send commands to the client
def send_commands(conn):
    while True:
        cmd = input()

        if cmd == 'quit':
            conn.close()
            s.close()
            sys.exit()

        if len(str.encode(cmd)) > 0:
            conn.send(str.encode(cmd))
            client_response = str(conn.recv(1024), 'utf-8')
            print(client_response, end="")


# Main function
def main():
    socket_create()
    socket_bind()
    socket_accept()


main()
