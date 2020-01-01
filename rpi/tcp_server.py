import socket
import sys
import os
import subprocess

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
        while True :
            print("Connection from {} ".format(client_address))
            data = connection.recv(16)
            print("Data : %s" % data)
            if data == "Musique":
                proc = subprocess.Popen(['ls', '/home/pi/Music'], stdout=subprocess.PIPE)
                list_playlist = proc.stdout.read().split()
                print(list_playlist)
                connection.sendall(";".join(list_playlist))
        else:
            connection.close()
