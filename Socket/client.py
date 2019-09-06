from socket import *;
serverPort = 12000
serverName = 'DESKTOP-9CJQB77'
clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
file_1 = input("Ënter file name:")
clientSocket.send(file_1.encode())
readfile = clientSocket.recv(1024)
print("From Server:",readfile.decode())
clientSocket.close()
