#include <stdio.h>
main()
{
	int a = 10, b = 20, c, d;
	c = a > b ? a : b;
	d = a > b ? a - b : b - a;
	printf("%d, %d\n", c, d);
}