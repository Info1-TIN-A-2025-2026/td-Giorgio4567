#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	srand(time(NULL));
	int n = rand();
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", RAND_MAX);
		n = rand();
	}
	return 0;
}