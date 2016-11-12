all:server client

server:server.o RIP.o
	cc server.o RIP.o -o server

client:client.o RIP.h
	cc client.o RIP.o -o client

client.o:client.c RIP.h
	cc -c client.c

RIP.o:RIP.c RIP.h
	cc -c RIP.c 

clean:
	rm *.o

