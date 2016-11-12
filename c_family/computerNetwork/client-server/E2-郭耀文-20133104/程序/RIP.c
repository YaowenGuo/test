#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RIP.h"

void copyRip(RipPoint to,RipPoint from,const int length)
{
	for(int i = 0;i < length;i++)
	{
		strncpy(to[i].destintion,from[i].destintion,4);
		to[i].distance = from[i].distance;
		strncpy(to[i].next,from[i].next,4);
	}
}

RipPoint initSer( int * lenth)
{
	RipPoint rp = (RipPoint)malloc(sizeof(Rip) * RIP_SIZE);
	bzero(rp,sizeof(Rip) * RIP_SIZE);
	Rip tempRP = {"N2",3,"R4"};
	rp[0] = tempRP;
	Rip tempRP2 = {"N3",4,"R5"};
	rp[1] = tempRP2;
	Rip tempRP3 = {"N4",4,"R5"};
	rp[2] = tempRP3;
	*lenth = 3;
	return rp; 
}

RipPoint initCli( int * lenth)
{
	RipPoint rp = (RipPoint)malloc(sizeof(Rip) * RIP_SIZE);
	bzero(rp,sizeof(Rip) * RIP_SIZE);
	Rip tempRP = {"N1",3,"R1"};
	rp[0] = tempRP;
	Rip tempRP1 = {"N2",4,"R2"};
	rp[1] = tempRP1;
	Rip tempRP2 = {"N3",1,"-"};
	rp[2] = tempRP2;
	Rip tempRP3 = {"N4",6,"R6"};
	rp[3] = tempRP3;
	*lenth = 4;
	return rp;
}

void change(RipPoint rp, int lenth, char * from)
{
	for(int i = 0; i < lenth; i++)
	{
		rp[i].distance += 1;
		strncpy(rp[i].next,from,4);
	}
	return;
}

int addOneItem(RipPoint rp, int * length, RipPoint oneRp)
{
	rp[*length] = *oneRp;
	*length += 1;
	return *length;
}

int getTargetPosition(RipPoint rp, int length, char * destintion)
{
	int index = -1;
	for ( int i = 0; i < length; i++)
	{
		if( 0 == strncmp(rp[i].destintion, destintion, 4) )
		{
			index = i;
			break;
		}
	}
	return index;
}

int merge(RipPoint ownRP,int ownLen,RipPoint getRP,int getLen)
{
	int length = ownLen;
	int position = -1;
	for( int i = 0; i < getLen; i++)
	{	
		position = getTargetPosition(ownRP,ownLen,getRP[i].destintion);
		if(-1 == position)
		{
			copyRip(&ownRP[length], &getRP[i],1);
			length++; 
		}
		else if( 0 == strncmp(ownRP[position].next,getRP[i].next,4) )
		{
			copyRip(&ownRP[position] , &getRP[i],1);
		}else
		{
			if(getRP[i].distance < ownRP[position].distance )
				copyRip(&ownRP[position] , &getRP[i], 1);
		}
	}
	return length;
}

void showRipTable(RipPoint rp,int length)
{
	char tableboder[50] = "+---------------+---------------+---------------+\n";
	printf("%s",tableboder);
	printf("|%15s|%15s|%15s|\n","DestintionNet","Distance","NextStep" );
	printf("%s",tableboder );
	for(int i = 0; i < length; i++)
	{
		printf("|%15s|%15d|%15s|\n",rp[i].destintion,rp[i].distance,rp[i].next );

	}
	printf("%s",tableboder);
	return;
}