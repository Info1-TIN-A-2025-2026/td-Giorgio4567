#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUM_CELLS 1000
#define MIN_VALUE (-100)
#define MAX_VALUE (100)
#define CANDIDATE_VALUE 93
long generate_random_real_value(const double min_value, const double max_value);
int main(int argc, const char *argv[])
{
	long array[NUM_CELLS] = {0};

	srand(time(NULL));

	for (unsigned long i = 0; i < NUM_CELLS; i++)
	{
		array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		//printf("%4lu, %ld\n", i, array[i]);
	}

	for (unsigned long i = 0; i < NUM_CELLS; i++)
	{
		if (CANDIDATE_VALUE == array[i])
		{
			printf("%d found at the position %lu\n", CANDIDATE_VALUE, i);
			break;
		}
	}

	for (unsigned long i = 0; i < NUM_CELLS; i++)
	{
		array[i] = generate_random_real_value(MIN_VALUE,MAX_VALUE);
		//printf("%4lu, %ld\n", i, array[i]);
	}
	for (unsigned long i = 0; i < NUM_CELLS; i++)
	{
		if (CANDIDATE_VALUE == array[i])
		{
			printf("%d found at the position %lu\n", CANDIDATE_VALUE, i);
			break;
		}
	}
	return 0;
}

long generate_random_real_value(const double min_value, const double max_value)
{
  int n = rand();
  double max = RAND_MAX;
  double rapport = n/max;
  return (max_value-min_value)*rapport + min_value;
}
