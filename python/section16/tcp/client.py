#!/usr/bin/env python

from socket import *

HOST = 'localhost'
PORT = 2016
BUFSIZE = 1024

print 'Press ^c once or twice to quit.'
try:
	HOST = raw_input("Please input target ip: ")
	PORT = int(raw_input("Please input match port:"))
	ADDR = (HOST, PORT)
	tcpCliSock = socket(AF_INET, SOCK_STREAM)
	tcpCliSock.connect(ADDR)

	while True:
		data = raw_input('> ')
		if not data:
			break

		tcpCliSock.send(data)
		data = tcpCliSock.recv(BUFSIZE)
		if not data:
			break
		print data
except KeyboardInterrupt:
	tcpCliSock.close()