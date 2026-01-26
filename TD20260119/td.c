#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void)
{
	const double M_0 = 750000., M_F = 90000., SPEED_FIRE = 4000., CONSOMMATION = 4000., DELTA_T = 0.001;

	printf("\n| TEMPS |  MASSE  |      VITESSE       | MASSE CARBURANT CONSOM. |   ALTITUDE   |\n");
	printf("|  [s]  |  [kg]   |  [m/s]  |  [km/h]  |          [kg]           |      [m]     |\n");
	printf("-----------------------------------------------------------------------------\n");

	double m = 0., t = 0., v_ms = 0., v_km_h = 0., m_cons = 0., alt = 0., v_prev = 0., t_affichage = 1.;

	do
	{
		m = (M_0 - CONSOMMATION * t);
		v_ms = SPEED_FIRE * log((M_0 / m));
		v_km_h = v_ms * 3.6;
		m_cons = CONSOMMATION * t;
		alt += 0.5 * (v_ms + v_prev) * DELTA_T;
		if (t_affichage >= 1)
		{
			t_affichage = 0;
			printf("|%6.0lf |%8.0lf |%8.2lf |%9.2lf |%24.2lf |%13.2lf |\n", t, m, v_ms, v_km_h, m_cons, alt);
		}
		t_affichage += DELTA_T;
		t = t + DELTA_T;
		v_prev = v_ms;
	} while (m > M_F);

	putchar('\n');

	return 0;
}
