#!/usr/bin/env python

from socket import *
from time import ctime

HOST = '192.168.198.1'
PORT = 2016
BUFSIZ = 1024
ADDR = (HOST, PORT)
print 'Press ^c once or twice to quit.'
print "This host's ip is:", HOST
print "This sevice's port is:", PORT
try:
	udpSerSock = socket(AF_INET,SOCK_DGRAM)
	udpSerSock.bind(ADDR)

	while True:
		print 'waiting for message...'
		data,addr = udpSerSock.recvfrom(BUFSIZ)
		udpSerSock.sendto('[%s] %s' % (ctime(), data),addr)
		print '...received from and return to',addr

except KeyboardInterrupt:
	udpSerSock.close()