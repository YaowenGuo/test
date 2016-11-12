#include <stdio.h>
#include <counter.h>

extern int fee_count, fie_count, foe_count, fum_count;
extern int yylex( void );

int main( int argc, char ** argv )
{
	int quantity[4];
	counter( quantity );
	printf("%d %d %d %d \n", quantity[0], quantity[1] 
		, quantity[2], quantity[3] );
	return 0;
}