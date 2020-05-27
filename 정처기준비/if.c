#include <stdio.h>
main()
{
	int a = 10, even = 0, odd = 0;
	for (int i = 1; i <= a; ++i)
	{
		if (i % 2 == 0)
			even += i;
		else
			odd += i;
	}
	printf("%d, %d\n", even, odd);
}