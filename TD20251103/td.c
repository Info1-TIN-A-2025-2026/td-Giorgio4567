#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	/*const unsigned int BASE = 10;
	unsigned int n = 0;
	unsigned int w = n == 0 ? 1 : 0;
	printf("Entrez la valeur de n :   ");
	scanf("%u",&n);

	while (n>0)
	{
		n /= BASE;
		w++;
	}

	printf(" W: %u\n",w);*/
	unsigned int n = atoi(argv[1]);
	unsigned int w = 0;

	do {
		w *= 10;
		w += n % 10;
		n /= 10;
	} while (n > 0);
	printf("%u\n",w);
}
