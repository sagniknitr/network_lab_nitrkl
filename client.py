#!/usr/bin/env python

import socket


TCP_IP = '127.0.0.1'
TCP_PORT = 5021
BUFFER_SIZE = 1024
#MESSAGE = "Hello!"
MESSAGE = raw_input('Type: ')
m=list(MESSAGE)
m1=[]
i=0
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
while i<len(m):
	
	s.send(m[i])
	
	data = s.recv(BUFFER_SIZE)
	m1.append(data)
	i=i+1
	print "received data:", data
	
i=0
print "correction packets"
print m1

while i<len(m1):
	
	if m1[i] == '0':
		s.send(m[i])
		data = s.recv(BUFFER_SIZE)
	i=i+1
	print "received data:", data

s.close()


#print "received data:", data
