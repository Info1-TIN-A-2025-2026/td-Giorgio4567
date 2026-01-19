
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void divide(long a, long b, unsigned char *q);

int main(int argc, const char *argv[])
{
	long a = atoi(argv[1]);
	long b = atoi(argv[2]);

	unsigned char chaine[32] = " ";

	divide(a, b, chaine);
	printf("%s\n", chaine);
}
#define PARTIE_ENTIERE 10
#define PARTIE_DECIMALE 20

void divide(long a, long b, unsigned char* q)
{
    long valeur_entier = a/b;
    for(long i = 9; i >= 0; i--)
    {
        if (valeur_entier > 0)
        {
            q[i] = '0' + valeur_entier%10;
            valeur_entier /= 10;
        }
		else 
		{
			q[i] = ' ';
		}
	}
	if (a/b == 0) 
	{
		q[9] = '0';
	}
	long r = a%b;
    for (long i = 10; i <= 29; i++)
    {
        r *= 10;
        q[i] = '0' + r/b;
        r %= b;
    }
	q[31] = '\0';
	q[10] = '.';
}
