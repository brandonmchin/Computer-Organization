// User enters a decimal integer
// Program prints the 32-bit binary equivalent
// Truncate any bits larger than 32

#include <stdio.h>

int main()
{
	long int i;
	int count;
	int reg[32];			// array for 32-bit register
	scanf("%d", &i);		// get decimal input from user

	// convert to binary
	for (count = 0; count < 32; count++)
	{
		reg[count] = i % 2;
		i = i/2;
	}

	// print binary string array (starting with most significant bit)
	for (count = 31; count >= 0; count--)
	{
		printf("%d", reg[count]);
	}

	return 0;
}