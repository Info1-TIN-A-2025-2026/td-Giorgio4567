#include <stdio.h> // printf et scanf
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	unsigned char num_students = 23, num_chairs = 32;

	short delta = num_students - num_chairs;

	bool sw1 = true;
	bool sw2 = true;

	unsigned char state = (sw2 << 4) + sw1;

	printf("Number of students = %u , Number of chairs = %u \n", num_students, num_chairs);
	printf("Sw1 = %hd \n", sw1);
	printf("Sw2 = %hd \n", sw1);
	printf("State = %X (b16) %d (b10) %o (b8) \n", state, state, state);

	char a = 'A';
	printf("%d (b10) %c (carractère correspondant)\n", a, a);

	char b = 117;
	printf("%d (b10) %c (carractère correspondant)\n", b, b);
	return 0;
}