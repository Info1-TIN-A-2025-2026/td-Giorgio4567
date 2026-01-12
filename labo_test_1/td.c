#include <stdlib.h>
#include <stdio.h>
#define NORD 0
#define SUD 1
#define OUEST 2
#define EST 3
int main(int argc, char *argv[])
{
	srand(0);
	unsigned int N = atoi(argv[1]);
	unsigned int x0 = atoi(argv[2]);
	unsigned int y0 = atoi(argv[3]);
	unsigned int xt = atoi(argv[4]);
	unsigned int yt = atoi(argv[5]);
	unsigned int max_step = atoi(argv[6]);

	printf("Taille de la grille N : %u\n", N);
	printf("Position initiale x,y : %u,%u\n", x0, y0);
	printf("Position cible xt,yt  : %u,%u\n", xt, yt);
	printf("Nombre maximal de pas : %u\n", max_step);
	unsigned int x = 0, y = 0;

	x = x0;
	y = y0;

	char direction_symbole = ' ', rebond_symbole = ' ';
	int decision = 0, Nb_rebonds = 0;
	unsigned int i = 0;
	printf("%3u :  %c %3u,%3u %c (position initiale) \n",i,direction_symbole,x,y,rebond_symbole);
	for (i = 1; i <= max_step; i++)
	{
		decision = rand() % 4;

		switch (decision)
		{
		case NORD:
			direction_symbole = 'N';
			if ((y - 1) != 0)
			{
				y--;
				rebond_symbole = ' ';
			}
			else
			{
				Nb_rebonds++;
				rebond_symbole = '*';
			}

			break;
		case SUD:

			direction_symbole = 'S';
			if ((y + 1) != 11)
			{
				y++;
				rebond_symbole = ' ';
			}
			else
			{
				Nb_rebonds++;
				rebond_symbole = '*';
			}

			break;
		case OUEST:
			direction_symbole = 'O';
			if ((x - 1) != 0)
			{
				x--;
				rebond_symbole = ' ';
			}
			else
			{
				Nb_rebonds++;
				rebond_symbole = '*';
			}
			break;
		case EST:
			direction_symbole = 'E';
			if ((x + 1) != 11)
			{
				x++;
				rebond_symbole = ' ';
			}
			else
			{
				Nb_rebonds++;
				rebond_symbole = '*';
			}
			break;
		}
		printf("%3u :  %c %3u,%3u %c\n",i,direction_symbole,x,y,rebond_symbole);
		if ((x == xt) && (y == yt))
		{
			printf("\nCIBLE ATTEINTE en %u pas !\n", i);
			printf("Rebonds : %u\n", Nb_rebonds);
			break;
		}

		if(i == max_step)
		{
			printf("\nCIBLE NON ATTEINTE après %u pas.\n", i);
			printf("Position finale : (%u,%u)\n",x,y);
			printf("Rebonds : %u\n", Nb_rebonds);
		}
	}
}