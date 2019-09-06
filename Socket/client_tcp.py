from socket import *
serverport = 12000
serverName = '10.124.7.97'
clientsocket = socket(AF_INET,SOCK_STREAM)
clientsocket.connect((serverName,serverport))
sentence = input("Enter file name")
clientsocket.send(sentence.encode())
modfile = clientsocket.recv(1024).decode()
print("From server",modfile)
clientsocket.close()
