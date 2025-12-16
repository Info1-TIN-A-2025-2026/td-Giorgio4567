#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define H 16
#define W 16
#define MIN_INTERN 4
#define MAX_INTERN 12
#define MAX_value 5
#define MIN_value 0

char generate_random_real_value(const double min_value, const double max_value);
void fill_matrix(unsigned char f[H][W], unsigned int MIN, unsigned int MAX);
void display_matrix(unsigned char matrix[H][W]);
void compte_histo(unsigned char matrix[MAX_value + 1], unsigned char f[H][W]);
void display_histo(unsigned char matrix[MAX_value + 1]);
void fill_intern_matrix(unsigned char f[H][W], unsigned int MIN, unsigned int MAX, unsigned int MIN_intern, unsigned int MAX_intern);
void dilatation(unsigned char f[H][W]);

int main(void)
{
	unsigned char f[H][W] = {0};
	fill_intern_matrix(f, H, W, MIN_INTERN, MAX_INTERN);
	display_matrix(f);
	dilatation(f);
	puts("");
	display_matrix(f);
	// unsigned char h[MAX_value + 1] = {0};
	// fill_matrix(f, MIN_value, MAX_value);
	// display_matrix(f);
	// compte_histo(h, f);
	// display_histo(h);
}

char generate_random_real_value(const double min_value, const double max_value)
{
  int n = rand();
  double max = RAND_MAX;
  double rapport = n/max;
  return (max_value-min_value)*rapport + min_value;
}

void fill_matrix(unsigned char f[H][W], unsigned int MIN, unsigned int MAX)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			f[i][j] = generate_random_real_value(MIN, MAX);
		}
	}
}
void display_matrix(unsigned char matrix [H][W])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%8hd", matrix[i][j]);
		}
		puts("");
	}
}

void compte_histo(unsigned char matrix[MAX_value + 1],unsigned char f[H][W])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			matrix[f[i][j]]++;
		}
	}
}

void display_histo(unsigned char matrix[MAX_value + 1])
{
	for (int i = 0; i < (MAX_value + 1); i++)
	{
		for (int j = 0; j <= matrix[i]; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}

void fill_intern_matrix (unsigned char f[H][W], unsigned int MIN, unsigned int MAX,unsigned int MIN_intern, unsigned int MAX_intern)
{
	for (int i = MIN_intern; i < (MAX_intern-1); i++)
	{
		for (int j = MIN_intern; j < (MAX_intern - 1); j++)
		{
			f[i][j] = 255;
		}
	}
}
void dilatation(unsigned char f[H][W])
{
	unsigned char g[H][W] = {0};

	for (int i = 1; i < (H - 1); i++)
	{
		for (int j = 1; j < (W - 1); j++)
		{
			if (f[i][j] == 255)
			{
				for (int k = (i - 1); k <= (i + 1); k++)
				{
					for (int l = (j - 1); l <= (j + 1); l++)
					{
						g[k][l] = 255;
					}
				}
			}
		}
	}

	for (int i = 0; i < H; i++)
	for (int j = 0; j < W; j++)
		f[i][j] = g[i][j];
}