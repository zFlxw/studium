/* bitwise_operators.c binary operations */
/* TO DO 1: Something is wrong with the output
		 Hint: put the output first into an additional variable m,
		 use bitwise operators and count the digits */
/* TO DO 2: A second number should be entered and
		 both numbers should be combined with the various bitwise
		 operators before providing the output */
/* TO DO 3: Use signed integers and see how negative numbers
					 are presented in binary format */

#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int n;

	printf("Please enter an integer number:");
	scanf("%u", &n); // Input unsigned integer from console

	// 25_10 = 11001_2

	unsigned int bits;
	unsigned int m = n;
	for (bits = 0; m != 0; ++bits)
	{
		m >>= 1;
	}

	printf("\n Binary representation: ");
	for (int i = 0; i < bits; i++)
	{
		printf("%d", (n & (1 << (bits - i - 1))) ? 1 : 0);
	}
}
