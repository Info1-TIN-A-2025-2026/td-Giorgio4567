#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
	long max_value = 0;
	bool number_ok = false;
	printf("Nombre permiers jusqu'au nombre : ");
	scanf("%ld", &max_value);

	for (3 long int i = 2; i <= max_value; i++)
	{
		number_ok = false;
		for (volatile long j = 2; j <= sqrt(i);j++)
		{
			if (i%j == 0)
				number_ok = true;
		}
		
		if (!number_ok)
		{
			printf(" %ld \n", i);
		}
	}
	return 0;
}

#if 0
#include <stdio.h>

int main(int argc, const char *argv[])
{
	//int a = 0, b = 0, q = 0, r = 0;

	//printf("enter a:  ");
	//scanf("%d", &a);
	//printf("enter b:  ");
	//scanf("%d", &b);

	//q = a / b;
	//r = a % b;

	//printf("a/b = %d\n", q);
	//printf("a%%b = %d\n", r);
	//int a = 10;
	//printf("a++ = %d\n", a++);
	//a = 10;
	//printf("++a = %d\n", ++a);

	//char x = 127;
	//x++;
	//printf("x = %d\n", x);

	//écriture des nombres premier
	volatile unsigned i;
	for (i = 2; i <= 200000;i++)
	{
	volatile unsigned j;
	volatile unsigned k = 0;
		for (j = 2; j <= 10;j++)
		{
			if (!(i%j))
				k++;
		}
	if (k==0) 
	{
		printf("%d\n", i);
	}
	}
		return 0;
}
#endif