#if 0
// 1 Nombre premier
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
	printf("Enter a valeur max : ");
	int max_value = 0;
	scanf("%d", &max_value);
	if (max_value < 2)
	{
		printf("Valeur max trop petite\n");
		return 1;
	}
	bool premier = false;
	for (int i = 2; i <= max_value; i++)
	{
		premier = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				premier = false;
				break;
			}
		}
		if (premier)
			printf("%d\n", i);
	}
}

// 2

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Bad arguments\n");
		return 1;
	}
	int n = atoi(argv[1]);
	int w = 0;
	do
	{
		w *= 10;
		w += n % 10;
		n /= 10;
	} while (n > 0);

	printf("%d\n", w);
}


// 3 vider scanf

#include <stdio.h>

int main(void)
{
	printf("valeur 1 : ");
	int a = 0, b = 0;
	scanf("%d", &a);
	while(getchar()!='\n');
	printf("valeur 2 : ");
	scanf("%d", &b);
	printf("\nvaleur a = %d\n", a);
	printf("valeur b = %d\n", b);
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		puts("Bad Arguments");
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 1)
	{
		puts("Bad Arguments");
		return 1;
	}
	printf("%*c\n", n, '+');
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < (n - i); j++)
		{
			putchar(' ');
		}
		for (int j = 0; j < (i*2 - 1); j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
	printf("%*c\n", n, '|');
	printf("%*c\n", n, '|');
	printf("%*c", n-1, '-');
	putchar('-');
	putchar('-');
	putchar('\n');
}


#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("Entrer une chaine de caractère (max 50) : ");
	char chaine[50];
	scanf("%s", chaine);

	int droite = 0, gauche = 0;

	while (chaine[droite] != '\0')
	{
		droite++;
	}
	droite--;

	while(gauche < droite)
	{
		char valeur = chaine[droite];
		chaine[droite] = chaine[gauche];
		chaine[gauche] = valeur;
		droite--;
		gauche++;
	}
	printf("%s\n", chaine);
}

#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		puts("Bad Arguments");
		return 1;
	}
	double conductance = 0.;
	for (int i = 1; i < argc; i++)
	{
		conductance += 1 / (atof(argv[i]));
	}
	printf("resistance de folie = %08.3lf\n", 1.0 / conductance);
}