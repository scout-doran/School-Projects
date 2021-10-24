#By: Scout Doran
#Date: 11/10/2020
import socket
import select
import sys
import datetime

HOST = socket.gethostname()
IP_address = socket.gethostbyname(HOST)
PORT = 5000
name = "Server"
print("IP address on server is " + IP_address)
currTime = datetime.datetime.now()
print(currTime)
print("waiting for a connection...")


#server creates a listening socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((HOST, PORT))
s.listen()
conn, address = s.accept() #address of the client
client = (conn.recv(1000)).decode()
print("Connection accepted from " + address[0]) 

print("Enter your server messages one by one and press the return key")
print("To terminate the program print bye and press the return key")

conn.send(name.encode())
while True:
    currTime = datetime.datetime.now().strftime("%m/%d/%Y, %H:%M:%S")
    server_msg = input("Server - " + currTime + ": ")
    conn.send(server_msg.encode())
    if server_msg == "bye": 
        break
    client_msg = conn.recv(1000)
    client_msg = client_msg.decode()
    currTime = datetime.datetime.now().strftime("%m/%d/%Y, %H:%M:%S")
    print("Client - " + currTime + ": " + client_msg)
    if client_msg == "bye": 
        break
conn.close()
s.close()

print("Goodbye!")