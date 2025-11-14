#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double ACCEL_TRAIN_A = 1.33;
const double ACCEL_TRAIN_B = 0.52;
const unsigned int TEMPS_ACCEL_TRAIN_A = 10;
const unsigned int TEMPS_ACCEL_TRAIN_B = 20;
const unsigned int TEMPS_DELTA = 1;

int main(void)
{
    bool croisement_effectuee = false;
    double pA = 0;
    double vA = 0;
    double pB = 0;
    double vB = 0;
    double delta_d = 0;
    double t_precis = 0;
    double distance_A_precis = 0;
    double distance_B_precis = 0;
    double ecart = 0;

    unsigned int t = 0;
    printf("\nDistance entre gares D (km) : ");
    scanf("%lf",&delta_d);
    delta_d = 1000*delta_d;
    printf("\n t        pA(m)    vA(m/s)        pB(m)    vB(m/s)     ecart(m)\n");

    while(croisement_effectuee == false)
    {
        if (t<=TEMPS_ACCEL_TRAIN_A)
        {
            pA = 0.5 * ACCEL_TRAIN_A * pow(t,2);
            vA = t * ACCEL_TRAIN_A;
        }
        else 
        {
            pA = (0.5 * ACCEL_TRAIN_A * pow((TEMPS_ACCEL_TRAIN_A),2)) + TEMPS_ACCEL_TRAIN_A * ACCEL_TRAIN_A * (t-TEMPS_ACCEL_TRAIN_A);
            vA = TEMPS_ACCEL_TRAIN_A * ACCEL_TRAIN_A;
        }
        if (t<=TEMPS_ACCEL_TRAIN_B)
        {
            pB = 0.5 * ACCEL_TRAIN_B * pow(t,2);
            vB = t * ACCEL_TRAIN_B;
        }
        else 
        {
            pB = (0.5 * ACCEL_TRAIN_B * pow((TEMPS_ACCEL_TRAIN_B),2)) + TEMPS_ACCEL_TRAIN_B * ACCEL_TRAIN_B * (t-TEMPS_ACCEL_TRAIN_B);
            vB = TEMPS_ACCEL_TRAIN_B * ACCEL_TRAIN_B;
        }
        ecart = delta_d - pA - pB;
        if (ecart < 0)
            croisement_effectuee = true;

        printf("%4u %10.1lf %10.2lf %10.1lf %10.2lf %10.1lf\n",t,pA,vA,pB,vB,ecart);

		t = t + TEMPS_DELTA;
	}

	if ((t<TEMPS_ACCEL_TRAIN_A) && (t<TEMPS_ACCEL_TRAIN_B))
	{
		t_precis = sqrt((2 * delta_d) / (ACCEL_TRAIN_A + ACCEL_TRAIN_B));
		distance_A_precis = 0.5 * ACCEL_TRAIN_A * pow(t_precis,2);
		distance_B_precis = 0.5 * ACCEL_TRAIN_B * pow(t_precis,2);
	}
	else if ((t>TEMPS_ACCEL_TRAIN_A) && (t<TEMPS_ACCEL_TRAIN_B))
	{
		double a = 0, b = 0, c = 0;
		a = 0.5 * ACCEL_TRAIN_B;
		b = ACCEL_TRAIN_A * TEMPS_ACCEL_TRAIN_A;
		c = -delta_d + (0.5 * ACCEL_TRAIN_A * pow((TEMPS_ACCEL_TRAIN_A), 2)) - ACCEL_TRAIN_A * TEMPS_ACCEL_TRAIN_A * TEMPS_ACCEL_TRAIN_A;
		t_precis = (-b + sqrt((b * b - 4 * a * c))) / (2 * a);
		distance_A_precis = (0.5 * ACCEL_TRAIN_A * pow((TEMPS_ACCEL_TRAIN_A), 2)) + TEMPS_ACCEL_TRAIN_A * ACCEL_TRAIN_A * (t_precis - TEMPS_ACCEL_TRAIN_A);
		distance_B_precis = 0.5 * ACCEL_TRAIN_B * pow(t_precis,2);
	}
	else if ((t<TEMPS_ACCEL_TRAIN_A) && (t>TEMPS_ACCEL_TRAIN_B))
	{
		double a = 0, b = 0, c = 0;
		a = 0.5 * ACCEL_TRAIN_A;
		b = ACCEL_TRAIN_B * TEMPS_ACCEL_TRAIN_B;
		c = -delta_d + (0.5 * ACCEL_TRAIN_B * pow((TEMPS_ACCEL_TRAIN_B), 2)) - ACCEL_TRAIN_B * TEMPS_ACCEL_TRAIN_B * TEMPS_ACCEL_TRAIN_B;
		t_precis = (-b + sqrt((b * b - 4 * a * c))) / (2 * a);
		distance_A_precis = 0.5 * ACCEL_TRAIN_A * pow(t_precis,2);
		distance_B_precis = (0.5 * ACCEL_TRAIN_B * pow((TEMPS_ACCEL_TRAIN_B), 2)) + TEMPS_ACCEL_TRAIN_B * ACCEL_TRAIN_B * (t_precis - TEMPS_ACCEL_TRAIN_B);
	}

	else if ((t>TEMPS_ACCEL_TRAIN_A) && (t>TEMPS_ACCEL_TRAIN_B))
	{
		t_precis = (delta_d - (0.5 * ACCEL_TRAIN_A * pow((TEMPS_ACCEL_TRAIN_A), 2)) - (0.5 * ACCEL_TRAIN_B * pow((TEMPS_ACCEL_TRAIN_B), 2)) 
		+ TEMPS_ACCEL_TRAIN_A * ACCEL_TRAIN_A * TEMPS_ACCEL_TRAIN_A + TEMPS_ACCEL_TRAIN_B * ACCEL_TRAIN_B * TEMPS_ACCEL_TRAIN_B) 
		/ (TEMPS_ACCEL_TRAIN_A * ACCEL_TRAIN_A + TEMPS_ACCEL_TRAIN_B * ACCEL_TRAIN_B);
		distance_A_precis = (0.5 * ACCEL_TRAIN_A * pow((TEMPS_ACCEL_TRAIN_A), 2)) + TEMPS_ACCEL_TRAIN_A * ACCEL_TRAIN_A * (t_precis - TEMPS_ACCEL_TRAIN_A);
		distance_B_precis = (0.5 * ACCEL_TRAIN_B * pow((TEMPS_ACCEL_TRAIN_B), 2)) + TEMPS_ACCEL_TRAIN_B * ACCEL_TRAIN_B * (t_precis - TEMPS_ACCEL_TRAIN_B);
	}
	printf("\n\n=== RENCONTRE ===");
    printf("\n t = %.3lf s\n",t_precis);
	printf("Positions: pA = %.2lf m, pB = %.2lf m\n", distance_A_precis, distance_B_precis);

	return 0;
}
