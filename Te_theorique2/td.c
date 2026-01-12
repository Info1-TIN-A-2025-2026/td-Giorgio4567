
#if 0

double test(const double apport)
{
	double taux = 0.02;

	taux += apport < 10000 ? 0.01 : 0.005;

	return taux;
}

#endif

#if 0
#include <math.h>
int main(void) 
{
	double c = 0.;
	return ((c <= 5 * pow(10, -6) * 1.1) && (c >= 5 * pow(10, -6) * 0.9));
}

#endif

#if 0
#include <stdio.h>
void test(void)
{
	int result = 1;

	for(int i=12;i>=2;i--)
		result *= i;
    // ne pas modifier le code ci-dessous
    printf("%d",result);
    return;
}

#endif

#if 0

#include <stdio.h>
#include <stdlib.h>

double test(const unsigned int N);
int main(int argc, char* argv[])
{
	unsigned int a = atoi(argv[1]);

	double r = test(a);

	printf("%lf\n", r);
}

double test(const unsigned int N)
{
	double e = 1.;
	double k = 1.;
	for (int i = 1; i <= N; i++)
	{
		k *= i;
		e += (1. / k);
	}
	return e;
}

#endif



#include <stdio.h>
#include <stdlib.h>

void test(const unsigned int N);
int main(int argc, char* argv[])
{
	unsigned int a = atoi(argv[1]);

	test(a);
}

void test(const unsigned int N)
{
	for (int i = 1; i <= N; i++)
	{
		if (i%2)
		{
			for (int j = 1; j <= N; j++)
			{
				putchar('X');
			}
			putchar('\n');

			for (int j = 1; j < N; j++)
			{
				putchar('.');
			}
			putchar('X');
			putchar('\n');
		}
		else
		{
			for (int j = 1; j <= N; j++)
			{
				putchar('X');
			}
			putchar('\n');
			putchar('X');
			for (int j = 1; j < N; j++)
			{
				putchar('.');
			}
			
			putchar('\n');
		}
	}
	for (int i = 1; i <= N; i++)
	{
		putchar('X');
	}
		putchar('\n');
}