#include <stdio.h>

int main(int argc, const char *argv[])
{
	int n = 0;
	// const int I_MIN = 10;
	// const int I_MAX = 20;
	do
	{
		int ret = 0;
		printf("Enter a value (ON = 1, OFF=2, BLINK=4)  =  ");
		ret = scanf("%d", &n);
		if (ret != 1) {
			// char c = 0;
			// do
			// {
			// 	c = getchar();
			// } while (c != '\n');
			while(getchar() != '\n');
		}

	} while ((n != 0) && (n != 1) && (n != 2) && (n != 4));
	printf("n = %d\n", n);
	switch (n)
	{
	case 1:
		puts("ON");
		break;
	case 2:
		puts("OFF");
		break;
	case 4:
		puts("BLINK");
		break;
	default:
		puts("ERROR");
		break;
	}


}
