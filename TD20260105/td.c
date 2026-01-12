#include <stdio.h>
#include <string.h>
void display(char *t);
int main(int argc, const char *argv[])
{
	char S1[] = "TXT";
	printf(" memory size = %ld\n",(sizeof(S1)));
	printf(" num cells. = %ld\n",(sizeof(S1) / sizeof(char)));

	unsigned long count = 0;

	while (S1[count] != '\0')
	{
		count++;
	}
	printf(" string length. = %ld\n",count);
	printf(" string length. = %ld\n",strlen(S1));

	char S2[100] = "TXT";
	printf(" memory size 2 = %ld\n",(sizeof(S2)));
	printf(" string length.2 = %ld\n",strlen(S2));

	char *s3 = "pipo";
	printf(" memory size 2 = %ld\n",(sizeof(s3)));
	printf(" string length.2 = %ld\n", strlen(s3));

	char S4[] = "ABC";
	printf(" memory size = %ld\n", (sizeof(S4)));
	printf(" num cells. = %ld\n",(sizeof(S4) / sizeof(char)));

	display(S4);

	char s6[][10] = // 3x10 donc  = 30 bytes
		{
			"ABC",
			"DEF",
			"GHIJKL"};
	
	char *s7[] = // 3x size(of(adress)) = 24 bytes
		{
			"ABC",
			"DEF",
			"GHIJKL"};

	printf("%c\n", s7[1][2]);
	return 0;
}

void display(char* t)
{
	for (int i = 0; i <= strlen(t); i++)
	{
		printf("%3d ", t[i]);
	}

	putchar('\n');
	for (int i = 0; i <= strlen(t); i++)
	{
		printf("%2c  ", t[i]);
	}
	putchar('\n');
}