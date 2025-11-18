// #include <stdio.h>
// void delta(double a, double b, double c);

// int main(int argc, const char *argv[])
// {
// 	double a = 0., b = 0., c = 0.;
// 	printf("Calcul du delta : \nEntrer une variable pour a, b et c : \n");
// 	scanf("%lf %lf %lf",&a,&b,&c);
// 	delta(a,b,c);
// 	return 0;
// }


// void delta(const double a, const double b, const double c)
// {
// 	printf("valeur de delta = %lf\n", b * b - 4. * a * c);
// 	return;
// }

#include <stdio.h>
double delta(double a, double b, double c);

int main(int argc, const char *argv[])
{
	double a = 0., b = 0., c = 0., s = 0.;
	printf("Calcul du delta : \nEntrer une variable pour a, b et c : \n");
	scanf("%lf %lf %lf",&a,&b,&c);
	s = delta(a,b,c);
	printf("Valeur de delta : %lf\n",s);
	return 0;
}


double delta(const double a, const double b, const double c)
{
	double r = 0.;
	r = b * b - 4. * a * c;
	return r;
}