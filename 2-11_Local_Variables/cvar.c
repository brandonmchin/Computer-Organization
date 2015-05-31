#include "stdio.h"

int global_var = 20;

foo(int x, int y)
{
	printf("%d",x);
	printf("\t%d",y);
}

main()
{
	foo(5,10);
	printf("\t%d",global_var);
}