from socket import *
servername = '10.124.7.95'
serverport = 12000
clientsocket = socket(AF_INET,SOCK_DGRAM)
file1 = input("Enter file name")
clientsocket.sendto(file1.encode(),(servername,serverport))
file2,serveraddr = clientsocket.recvfrom(2048)
print(file2.decode())
clientsocket.close
