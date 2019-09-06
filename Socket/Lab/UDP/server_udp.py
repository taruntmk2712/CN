from socket import *
serverPort = 12000
serverName = '10.124.7.95'
client = '10.124.7.96'
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind((serverName,serverPort))
print("The server is ready to receive")
while 1:
    f1,client = serverSocket.recvfrom(2048)
    file = open(f1,'r')
    file2 = file.read(2048)
    serverSocket.sendto(file2.encode(),client)
    file.close()
