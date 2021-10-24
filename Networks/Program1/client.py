#By: Scout Doran
#Date: 11/10/2020
import socket
import select
import sys
import datetime

#Make sure that the user enters 2 arguments
#if len(sys.argv) != 2:
#    print("Correct usage: script, IP address")
#    exit()

#HOST = str(sys.argv[1])
#IP_address = socket.gethostbyname(HOST)
SPORT = 5000
SHOST = socket.gethostname() 
IP_address = socket.gethostbyname(SHOST)
FriendName = "Server" 

print("IP Address on client is " + IP_address)
currTime = datetime.datetime.now()
print(currTime)

s = socket.socket()
s.connect((SHOST, SPORT))

print("Enter your client messages one by one and press the return key")
print("To terminate the program print bye and press the return key")

s.send(FriendName.encode())
server_name = s.recv(1000)
server_name = server_name.decode()

while True:
    server_msg = (s.recv(1000)).decode()
    currTime = datetime.datetime.now().strftime("%m/%d/%Y, %H:%M:%S")
    print("Server - " + currTime + ": " + server_msg)
    if server_msg == "bye": 
        break

    currTime = datetime.datetime.now().strftime("%m/%d/%Y, %H:%M:%S")
    client_msg = input("Client - " + currTime + ": ")
    s.send(client_msg.encode())
    if client_msg == "bye":
        break

s.close
print("Goodbye!")
