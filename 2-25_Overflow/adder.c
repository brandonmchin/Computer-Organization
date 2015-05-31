// User enters two decimal integers and the operation (ex. 2 + 5)
// Program converts inputs into 32-bit binary strings
// Then performs full binary addition (carry in/carry out)

#include <stdio.h>

int main()
{
	long int a, b;								// inputs to be added
	char sign;									// addition/subtraction sign
	
	scanf("%d %c %d", &a, &sign, &b);			// get input expression from user

	if (sign == '+')
	{
		printf("Addition\n");
	}
	else if (sign == '-')
	{
		printf("Subtraction\n");
	}
	else printf("Invalid Input\n");

	// convert to binary
	int i;
	int reg1[32], reg2[32];			// arrays for 32-bit registers
	for (i = 0; i < 32; i++)
	{
		reg1[i] = a % 2;
		a = a/2;
		reg2[i] = b % 2;
		b = b/2;
	}

	int sum[32], sum_bit;
	int carry = 0;
	for (i = 0; i < 32; i++)
	{
		if (reg1[i] == 1 && reg2[i] == 1)
		{
			sum_bit = 0;
			carry = 1;
		}
		else
		{
			if (reg1[i] == 0 && reg2[i] == 0)
			{
				sum_bit = 0 + carry;
				carry = 0;
			}
			else if (carry == 0)
				sum_bit = 1;
			else if (carry == 1)
				sum_bit = 0;
		}
		sum[i] = sum_bit;
	}

	// print each binary string array (starting with most significant bit)
	printf("Register1: \t");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", reg1[i]);
	}
	printf("\nRegister2: \t");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", reg2[i]);
	}
	printf("\nSum: \t\t");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", sum[i]);
	}

	return 0;
}