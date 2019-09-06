from socket import *;
serverPort = 12000
serverName = 'DESKTOP-9CJQB77'
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print("The server is ready to receive")
while 1:
    connectionSocket,addr = serverSocket.accept()
    file_1 = connectionSocket.recv(1024)
    file = open(file_1,'r')
    file2 = file.read(1024)
    connectionSocket.send(file2)
    file.close()
    connectionSocket.close()
