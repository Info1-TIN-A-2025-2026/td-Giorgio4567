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