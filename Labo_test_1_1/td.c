// 1
#if 0
#include <stdio.h>

int main(void)
{
	const double accel = 1.7, time_accel = 4., dist_max = 100.;
	int T = 0;
	double high = 0., speed = 0.;
	printf("Enter a value for the time total : ");
	scanf("%d", &T);

	if (T <= 0)
	{
		printf("Error, the time must be greather than 0\n");
		return 1;
	}
	printf("|  t  |   speed   |   high  |\n\n");
	for (int t = 0; (t <= T) && (high <= dist_max); t++)
	{
		if (t <= time_accel)
		{
			high = 0.5 * t * t * accel;
			speed = t * accel;
		}
		else
		{
			high = 0.5 * time_accel * time_accel * accel + (t - time_accel) * time_accel * accel;
			speed = time_accel * accel;
		}

		printf("|%3d  |%9.3lf  |%8.3lf |\n", t, speed, high);
	}
	if (high > dist_max)
	{
		double t_real = (dist_max + 0.5 * time_accel * time_accel * accel) / (time_accel * 1.7);
		printf("______TIME_REAL______\n");
		printf("Time real value : %lf s\n", t_real);
	}
	return 0;
}
#endif

#if 1
//2 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	if (argc != 3)
	{
		printf("Error, the fonction must avec 2 arguments\n");
		return 1;
	}

	for (volatile int i = 1; i <= 2; i++)
	{
		if (argv[i][0] == '\0')
		{
			printf("Error, the arguments can't be empty\n");
			return 1;
		}
		for (volatile int j = 0; argv[i][j] != '\0';j++)
		{
			char c = argv[i][j];
			if (((c < '0') || (c >'9')) && (argv[i][j] != '-') && (c != '.'))
			{
				printf("Error, the format of the enter must be without letter, without +, without e\n");
				return 1;
			}
		}
	}

	double a = atof(argv[1]);
	double b = atof(argv[2]);

	if (b == 0)
	{
		printf("Division by zero.\n");
		return 2;
	}

	printf("Result = %.3lf\n", a / b);
	return 0;
}

#endif

//3

#if 0 
#include <stdio.h>

int main(void)
{
	int N = 0;
	printf("Entrer un nombre entier : ");
	scanf("%d", &N);
	if ((N < 1) || (N > 15))
	{
		printf("Error, 1 >= N >= 15\n");
		return 1;
	}
	printf("| x | x<<1 | x>>1 | ~x |\n");
	for (volatile int i = 0; i <= N; i++)
	{
		printf("|%2d |%5d |%5d |%3d |\n",i , i<<1,i>>1,~i);
	}
	return 0;
}
#endif

//4

#if 0
#include <stdio.h>
#include <math.h>

int main(void)
{
	double R = 0., angle_degre = 0., angle_radian = 0., corde = 0.;
	printf("____Calculation de la corde____\n");
	printf("Entrez la valeur du rayon [m] : ");
	scanf("%lf",&R);
	printf("Entrez la valeur de l'angle en degrées : ");
	scanf("%lf",&angle_degre);

	if ((R <= 0) || (angle_degre <= 0) || (angle_degre >= 360))
	{
		printf("Erreur d'entrée, le rayon doit être plus grand que 0 et l'angle entre 0 et 360\n");
		return 1;
	}

	angle_radian = (angle_degre * M_PI) / 180;
	corde = 2 * R * sin((angle_radian / 2));

	printf("Résultat : la corde vaut %.4lf m\n", corde);
	return 0;
}
#endif

//5
#if 0
#include <stdio.h>

int main(void)
{
	int n = 0;
	printf("Entrer un valeur entière positive pour la grandeur du tableau : ");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("Erreur, la valeur de la grandeur du tableau doit être supérieur à 0\n");
		return 1;
	}
	int tableau[n];
	printf("__________Remplissage du tableau avec des entiers__________\n");

	for (volatile int i = 0; i < n;i++)
	{
		printf("valeur %d : ", i + 1);
		scanf("%d", &tableau[i]);
	}
	int plus_grande_valeur = 0, somme_valeurs_paires = 0, nombre_valeurs_negatives = 0;
	for (volatile int i = 0; i < n; i++)
	{
		if (tableau[i] > plus_grande_valeur)
			plus_grande_valeur = tableau[i];
		if (tableau[i]%2 == 0)
			somme_valeurs_paires += tableau[i];
		if (tableau[i] < 0)
			nombre_valeurs_negatives++;
	}

	printf("La plus grande grande valeur du tableau : %d\n", plus_grande_valeur);
	printf("La somme des valeurs paires : %d\n", somme_valeurs_paires);
	printf("Le nombres de valeurs negatives : %d\n", nombre_valeurs_negatives);
	return 0;
}
#endif