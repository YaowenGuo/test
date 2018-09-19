#include <stdio.h>
#include <counter.h>

int main( int argc, char ** argv )
{
	int quantity[4];
	counter( quantity );
	printf("%d %d %d %d \n", quantity[0], quantity[1] 
		, quantity[2], quantity[3] );
	return 0;
}