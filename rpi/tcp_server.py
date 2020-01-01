import socket
import sys

IP_ADDR = "192.168.1.19"
TCP_PORT = 10000

if __name__ == "__main__":
    # Create TCP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Associate the socket with the server address
    server_address = (IP_ADDR, TCP_PORT)
    print("Start TCP server at address {} on port {} ".format(server_address[0], server_address[1]))
    sock.bind(server_address)

    # Mode TCP server
    sock.listen(1)

    while True:
        connection, client_address = sock.accept()
        print(type(connection))
        if type(connection) == "socket":
            while True :
                print("Connection from {} ".format(client_address))
                data = connection.recv(16)
                print("Data : ".format(data))
            else:
                connection.close()