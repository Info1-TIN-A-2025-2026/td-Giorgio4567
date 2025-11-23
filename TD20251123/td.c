#include <stdio.h>
#include <math.h>

int main(void)
{
	const double ACCEL_TR_A = 1.33, ACCEL_TR_B = 0.52, TIME_ACCEL_TR_A = 10., TIME_ACCEL_TR_B = 20., delta_t = 1.;
	const int precision_real_digit = 3;
	double t = 0., pA = 0., vA = 0., pB = 0., vB = 0., delta_AB = 0., delta_TR = 0., speed_max_TR_A = 0., speed_max_TR_B = 0.;

	printf("Distance entre gares D (km) : ");
	scanf("%lf", &delta_AB);
	delta_AB *= 1000;
	printf("\n  t        pA(m)    vA(m/s)        pB(m)    vB(m/s)     ecart(m)\n");
	speed_max_TR_A = ACCEL_TR_A * TIME_ACCEL_TR_A;
	speed_max_TR_B = ACCEL_TR_B * TIME_ACCEL_TR_B;

	do
	{
		if (t <= TIME_ACCEL_TR_A)
		{
			pA = 0.5 * ACCEL_TR_A * t * t;
			vA = ACCEL_TR_A * t;
		}
		else
		{
			pA = 0.5 * speed_max_TR_A * TIME_ACCEL_TR_A + speed_max_TR_A * (t - TIME_ACCEL_TR_A);
			vA = speed_max_TR_A;			
		}

		if (t <= TIME_ACCEL_TR_B)
		{
			pB = 0.5 * ACCEL_TR_B * t * t;
			vB = ACCEL_TR_B * t;
		}
		else
		{
			pB = 0.5 * speed_max_TR_B * TIME_ACCEL_TR_B + speed_max_TR_B * (t - TIME_ACCEL_TR_B);
			vB = speed_max_TR_B;			
		}

		delta_TR = delta_AB - pA - pB;

		printf("%3.0lf %10.1lf %10.2lf %12.1lf %10.2lf %12.1lf\n", t, pA, vA, pB, vB, delta_TR);

		t += delta_t;

	} while (delta_TR > 0);

	t = t - 2 * delta_t;
	do
	{
		if (t <= TIME_ACCEL_TR_A)
		{
			pA = 0.5 * ACCEL_TR_A * t * t;
			vA = ACCEL_TR_A * t;
		}
		else
		{
			pA = 0.5 * speed_max_TR_A * TIME_ACCEL_TR_A + speed_max_TR_A * (t - TIME_ACCEL_TR_A);
			vA = speed_max_TR_A;			
		}

		if (t <= TIME_ACCEL_TR_B)
		{
			pB = 0.5 * ACCEL_TR_B * t * t;
			vB = ACCEL_TR_B * t;
		}
		else
		{
			pB = 0.5 * speed_max_TR_B * TIME_ACCEL_TR_B + speed_max_TR_B * (t - TIME_ACCEL_TR_B);
			vB = speed_max_TR_B;			
		}

		delta_TR = delta_AB - pA - pB;

		t += pow(10.0,-(precision_real_digit));

	} while (delta_TR > 0);

	printf("\n=== RENCONTRE ===\n");
	printf("t =%8.3lf\n",t);	
	printf("Positions: pA =%8.2lf m, pB =%8.2lf m\n", pA, pB);
}