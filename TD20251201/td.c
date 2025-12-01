#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if 0

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	if (n%2 !=1)
	{
		printf("Erreur, le facteur de hauteur du sapin doit être impaire");
		return 1;
	}
	printf("%*c",(n-1),'0');
	for (int i = (n-2); i > 0; i--)
	{
		printf("%*c",i,'o');
		for (int j = 0; j > (n - i);j++ )
		{
			putchar('*');
		}
		printf("\n");
	}
}

#endif

#if 0
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("one argument is missing\n");
		return 1;
	}
	int n = atoi(argv[1]);
	if (n%2 != 1)
	{
		printf("Erreur, le facteur de hauteur du sapin doit être impaire");
		return 1;
	}
	for (int l = 1; l<=n; l++)
	{
		for (int c = 0; c < n - l;c++)
			putchar(' ');
		for (int c = 0; c <(2*l-1);c++)
			putchar('*');
		putchar('\n');
	}
	for (int l = 0; l<2; l++)
	{
		for (int c = 1; c < n - l;c++)
			putchar(' ');
		putchar('|');
		putchar('\n');
	}
}

#endif

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("one argument is missing\n");
		return 1;
	}
	int n = atoi(argv[1]);
	double a = 0.;
	for (int i = 0; i <= n; i++)
	{
		double f = (pow(-1, i)) / (2 * i + 1);
		a += f;
	}
	double p = 4 * a;

	printf("Valeur calculé de PI : %.9lf\n", p);
	printf("Valeur reel de PI : %.9lf\n", M_PI);

	long i = 0;
	p = 0;
	a = 0;
	while (fabs(M_PI - p) > 0.000000001)
	{
	
		double f = (pow(-1, i)) / (2 * i + 1);
		a += f;
		p = 4 * a;
		i++;
	}
	printf("nombre d'essai necessaire : %ld\n", i);
}
