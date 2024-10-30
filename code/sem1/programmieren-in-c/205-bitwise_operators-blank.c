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

int main()
{
	unsigned int n;

	printf("Please enter an integer number:");
	scanf("%u", &n); // Input unsigned integer from console

	printf("\n Binary representation: ");
	while (n > 0)
	{
		// 11011
		// 00001
		// 00001

		// 10011 
		// 25 & 1 
		printf("%d", n & 1);
		n = n >> 1;
	}
}
