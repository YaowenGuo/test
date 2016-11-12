#include "mytool1.h"
#include "mytool2.h"

int main(int argc,char **argv)
{
	char *str="hello";
	mytool1_print(str);
	mytool2_print(str);
	return 0;
}