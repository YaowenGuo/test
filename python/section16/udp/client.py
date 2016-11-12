#!/usr/bin/env python

from socket import *

HOST = 'localhost'
PORT = 2016
BUFSIZ = 1024


print 'Press ^c once or twice to quit.'
HOST = raw_input("Please input target ip: ")
PORT = int(raw_input("Please input match port:"))
ADDR = (HOST, PORT)
try:
	
	udpCliSock = socket(AF_INET, SOCK_DGRAM)
	while True:
		data = raw_input('> ')
		if not data:
			break
		udpCliSock.sendto(data, ADDR)
		data, ADDR = udpCliSock.recvfrom(BUFSIZ)
		if not data:
			break
		print data
except KeyboardInterrupt:
	udpCliSock.close()