#!/usr/bin/env python

from socket import *
from time import ctime
import threading


def con(connect,bufsiz):
	while True:
		data = connect.recv(bufsiz)
		if not data:
			break
		connect.send('[%s] %s' % (ctime(), data))

	connect.close()
	print 'end connect'

def main():
	HOST = '192.168.198.1' # it can empoty lake ''
	PORT = 2016
	BUFSIZE = 1024
	ADDR = (HOST, PORT)
	print "This host's ip is:", HOST
	print "This sevice's port is:", PORT
	try:
		print "Press ^c once or twice to quit."
		tcpSerSock = socket(AF_INET, SOCK_STREAM)
		tcpSerSock.bind(ADDR)
		tcpSerSock.listen(5)
		conPool = []
		while True:
			print 'waiting for connection...'
			tcpConnect, addr = tcpSerSock.accept()
			print '...connected from:', addr

			thrd = threading.Thread(target=con,args=(tcpConnect,BUFSIZE))
			thrd.start()
			thrd.join()
			conPool.append(thrd)
			for th in conPool:
				if not th.isAlive():
					conPool.remove(th);
					del th;
	except KeyboardInterrupt:
		tcpSerSock.close()
if __name__ == '__main__':
	main()