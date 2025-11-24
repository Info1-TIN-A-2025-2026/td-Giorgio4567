#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void c2p(const double x, const double y , double *rho, double *theta);
int main(int argc, const char *argv[])
{
	double x = 0, y = 0, rho = 0, theta = 0;
	x = atof(argv[1]);
	y = atof(argv[2]);	
	c2p(x, y, &rho, &theta);
	printf("notation polaire = %.3lf , %.3lf °\n", rho, theta);
}	

void c2p(const double x, const double y, double *rho, double *theta)
{
	*theta = atan2(y, x) /3.14159265359 * 180;
	*rho = sqrt(x * x + y * y);
}


#if 0
int f(unsigned int t, int *a, int *b, int *c);
int main(int argc, const char *argv[])
{
	int h = 0;
	int m = 0;
	int s = 0;
	unsigned int t = atoi(argv[1]);

	// printf("adress of argc= %17p\n", &argc);
	// printf("adress of h= %20p\n", &h);
	// printf("adress of m= %20p\n", &m);
	// printf("adress of s= %20p\n", &s);
	
	f(t, &h, &m, &s);

	printf("Time = %d:%d:%d\n", h, m, s);

	return 0;
}

int f(unsigned int t, int *a, int *b, int *c)
{
	*a = t / 3600;
	*b = (t / 60) - *a * 60;
	*c = t - *a * 3600 - *b * 60;
	return 0;
}
#endif