#include <stdio.h>
#include <string.h>

#define x 8
#define y 4
#define z 4
int main(int argc, const char *argv[])
{
	int a[z][y][x] = {{{1,2},{2,3}}};
	int (*b)[y][x] = a;
	int w = 0;
	for(int *c = &b[0][0][0]; c < &b[0][0][0] + x*y*z; c++)
	{
		w += *c;
	}
	printf("%d",w);
	putchar('\n');
	int *c = &b[0][0][0];
	*(c + x * y * z - 1) = 1000;
	memset(c, &b[1][0][0],10);
	w = 0;
	for(int i = 0; i < z; i++)
	{
		for(int j = 0; j < y; j++)
		{
			for(int k = 0; k < x; k++)
			{
				w += b[i][j][k];
			}
		}
	}

	printf("%d",w);
	putchar('\n');

	char d[100] = "de la merde cette journée";
	char* e = strstr(d,"merde");

	printf("%p\n", e);
	return 0;
}