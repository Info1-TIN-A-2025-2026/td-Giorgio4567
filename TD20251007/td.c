#include <stdio.h> // printf et scanf
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	long volume = 42; //m3

	printf("volume = %ld\n",volume);
	printf("volume = [%7ld]\n",volume);
	printf("volume = [%-7ld]\n",volume);

	printf("volume = [%+ld]\n",volume);
	printf("volume = [%+7ld]\n",volume);
	printf("volume = [%+-7ld]\n",volume);

	long pression = -4; // bar
	printf("pression = [%ld]\n",pression);

	double pi = 3.141592653589793;
	printf("pi = [%lf]\n",pi);
	printf("pi = [%.2lf]\n",pi);
	printf("pi = [%+.2lf]\n",pi);

	double absolut_zero = -459.67; // degré fahrenheit
	printf("absolut_zero = [%+.1lf]\n",absolut_zero);

	//alignement des deux 
	printf("[%+10.2lf]\n",pi);
	printf("[%+10.2lf]\n",absolut_zero);	

	//si chiffre trop grand = il l'affiche quand meme
	double light_speed = 299792458.0; //m/s
	printf("[%+10.2lf]\n",light_speed);

	int num_digits = 3; // control du nombre de digits apres la virgule avec une variable
	int width = 8; 
	printf("pi = [%+lf]\n",pi);	
	printf("pi = [%+*.*lf]\n",width,num_digits,pi);







	//saisie
	float x = 0.f;
	float y = 0.f;
	//printf("Enter a floating point value :  ");
	int ret = 0;
	//ret = scanf("%f", &x);
	//printf("x = %.4f\n",x);	
	//printf("ret = %d\n",ret);

	//printf("Enter a floating point value :  ");
	//ret = scanf("%f", &y);
	//printf("y = %.4f\n",y);	
	//printf("ret = %d\n",ret);


	printf("Enter two floating points separate with an espace :  ");
	ret = scanf("%f:%f", &x,&y); // séparation avec : comme menstionné
	printf("ret = %d\n",ret);
	printf("x = %.4f\n",x);
	printf("y = %.4f\n",y);
	return 0;
}