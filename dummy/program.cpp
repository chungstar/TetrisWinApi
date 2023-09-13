#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", rand());
	}
	return 0;
}