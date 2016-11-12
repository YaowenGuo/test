all:main1

main1: main.o mytool1.o mytool2.o 			
	cc -o main1 main.o mytool1.o mytool2.o

main2:main2.o mytool1.o mytool2.o
	cc -o main2 main2.o mytool1.o mytool2.o  

main.o: main.c mytool1.h mytool2.h 	

main2.o:main2.c mytool2.h mytool1.h	

main2.o:main2.c mytool1.h mytool2.h

mytool1.o: mytool1.c mytool1.h 
mytool2.o: mytool2.c mytool2.h 