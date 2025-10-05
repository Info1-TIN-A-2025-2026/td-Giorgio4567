#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("Calculateur de force gravitationnelle (unités SI): \n");
	double m1 = 0;
	double m2 = 0;
	double dist = 0;
	const double G = 6.67e-11;
	printf("Mass 1 [kg]: ");
	scanf("%lf", &m1);
	printf("Mass 2 [kg]: ");
	scanf("%lf", &m2);
	printf("Distance [m]: ");
	scanf("%lf", &dist);


	if (m1 < 0) //condition 1 less than 0
	{ 
		puts("Error, the mass 1 must be greater than 0 "); // 
	}
	else if (m2 < 0) //condition 2 less than 0
	{ 
		puts("Error, the mass 2 must be greater than 0 "); // 
	}
	else if (dist < 0) //condition 3 less than 0
	{ 
		puts("Error, the distance must be greater than 0 "); // 
	}
	else if (m1 > 1.7e308) //condition 1 overflow
	{ 
		puts("Error Overflow, the mass 1 must be less than 1.7e308 "); // 
	}
	else if (m2 > 1.7e308) //condition 2 overflow
	{ 
		puts("Error Overflow, the mass 2 must be less than 1.7e308 "); // 
	}
	else if (dist > 1.7e308) //condition 3 overflow
	{ //Bloc 1
		puts("Error Overflow, the distance must be less than 1.7e308 "); // 
	}
	else //Calculation résultat
	{
		double Fg = 0;

		Fg = (G * m1 *m2) / (dist * dist);

		printf("Force gravitationnelle en [N] : %.2e\n",Fg);
	}
}