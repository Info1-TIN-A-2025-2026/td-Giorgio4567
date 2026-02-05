#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PARTIE_ENTIERE 10
#define PARTIE_DECIMALE 20

void rle(const char *signal, const unsigned long num_samples) 
{
	
	if (!num_samples)
	{
		puts("Aucune chaine donnée");
		return;
	}

	printf("rle : %c",signal[0]);
	const char *p = signal;
	unsigned long ct = 1, nb_rle = 1;
	if (num_samples == 1)
	{
		printf(",1\n");
		nb_rle++;
		printf("Number of symbols in rle : %lu\n", nb_rle);
		printf("Compression rate : x%1.1lf\n", (double)num_samples/nb_rle);
	}
	else
	{
		for (unsigned long i = 1; i < num_samples; i++)
		{
			if(*(p + i) == *(p + i - 1))
			{
				ct++;
			}
			else
			{
				printf(",%lu", ct);
				nb_rle++;
				ct = 1;
			}
		}
		printf(",%lu\n", ct);
		nb_rle++;
		printf("Number of symbols in rle : %lu\n", nb_rle);
		printf("Compression rate : x%1.1lf\n", (double)num_samples/nb_rle);
	}
}
void divide(long a, long b, unsigned char* q)
{
	long val_ent = a / b;
	for (long i = PARTIE_ENTIERE - 1; i >=0 ; i--)
	{
		if ((val_ent == 0) && (i != PARTIE_ENTIERE - 1))
		{
			q[i] = ' ';
			continue;
		}
		q[i] = val_ent % 10 + '0';
		val_ent /= 10;
	}
	q[PARTIE_ENTIERE] = '.';
	long rest = a % b;
	for (long i = PARTIE_ENTIERE + 1; i < PARTIE_ENTIERE + PARTIE_DECIMALE; i++)
	{
		rest *= 10;
		q[i] = rest / b + '0';
		rest %= b;
	}
}

int main(int argc, const char *argv[])
{
	//rle(argv[1], strlen(argv[1]));
	unsigned char result[32] = "";
	divide(atoi(argv[1]),atoi(argv[2]),result);
	printf("%s\n", result);
	return 0;
}