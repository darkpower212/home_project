#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long cardnum;

int larray[16];

int digitcount;

int option;

int main() 
{
	for (int i = 0; i < 1; i++)
	{ 
		printf("press 1 to run the program or press 2 for help\n");
		scanf("%d", &option);
		if (option == 1)
		{
			cardinput();
			digitcount = digitcheck();
			printf("digit count = %d \n", digitcount);

			convert();
			if (digitcount == 16)
			{
				test();
			}
			else if (digitcount == 15)
			{
				test2();
			}
			else
			{
				printf("your card number has an invalid number of digits\n");
			}

			type();
		}
		else if (option == 2)
		{
			printf("to use this program type your card number with no spaces and press enter. \n the relevent information about your card will then be displayed on screen\n\n");
		}
		i--;
	}


	return 0;
}

int cardinput()
{
	printf("enter your card number \n");
	scanf("%lld", &cardnum);
	return 0;
}

int digitcheck()
{	
	long long begin[16] = { 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999, 99999999999999, 999999999999999, 999999999999999 };
	long long end[16] = { 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000,};
	

	for (int i = 0; i < 16; i ++)
	{
		if (cardnum > begin[i] && cardnum < end[i]) return i += 2;
	}
	return 0;
}

int convert()
{
	char lchar[16];
	_snprintf(lchar, 16, "%lld", cardnum);
	
	for (int i = 0; i < 16; i++)
	{

		larray[i] = lchar[i] - '0';
	}

	return 0;
}

int test()
{
	int sum_odd = 0;
	int sum_even = 0;
	int swithcedarray[16];
	int final_num;
	int last_num;

		
		for (int i = 0; i < 16; i++)
		{
			swithcedarray[i] = larray[15 - i];
		}


		for (int i = 0; i < 16; i += 2)
		{
			sum_even += swithcedarray[i];
		}

		for (int i = 1; i < 16; i += 2)
		{

			if (swithcedarray[i] * 2 < 10)
			{
				sum_odd += swithcedarray[i] * 2;
			}

			// check greater than 9
			if (swithcedarray[i] * 2 == 10)
			{
				sum_odd += 1;
			}

			if (swithcedarray[i] * 2 == 11)
			{
				sum_odd += 2;
			}

			if (swithcedarray[i] * 2 == 12)
			{
				sum_odd += 3;
			}

			if (swithcedarray[i] * 2 == 13)
			{
				sum_odd += 4;
			}

			if (swithcedarray[i] * 2 == 14)
			{
				sum_odd += 5;
			}

			if (swithcedarray[i] * 2 == 15)
			{
				sum_odd += 6;
			}

			if (swithcedarray[i] * 2 == 16)
			{
				sum_odd += 7;
			}

			if (swithcedarray[i] * 2 == 17)
			{
				sum_odd += 8;
			}

			if (swithcedarray[i] * 2 == 18)
			{
				sum_odd += 9;
			}

		}

		final_num = sum_even + sum_odd;

		last_num = final_num%10;
		if (last_num == 0) { printf("your card number passed Luhn's test\n"); }
		else
		{
			printf("your card number failed the Luhn's test\n");
		}
		return 0;
}


//15 digit test
int test2()
{
	int sum_odd = 0;
	int sum_even = 0;
	int swithcedarray[15];
	int final_num;
	int last_num;


	for (int i = 0; i < 15; i++)
	{
		swithcedarray[i] = larray[14 - i];
	}

	for (int i = 1; i < 15; i += 2)
	{
		if (swithcedarray[i] * 2 < 10)
		{
			sum_odd += swithcedarray[i] * 2;
		}

		// check greater than 9
		if (swithcedarray[i] * 2 == 10)
		{
			sum_odd += 1;
		}

		if (swithcedarray[i] * 2 == 11)
		{
			sum_odd += 2;
		}

		if (swithcedarray[i] * 2 == 12)
		{
			sum_odd += 3;
		}

		if (swithcedarray[i] * 2 == 13)
		{
			sum_odd += 4;
		}

		if (swithcedarray[i] * 2 == 14)
		{
			sum_odd += 5;
		}

		if (swithcedarray[i] * 2 == 15)
		{
			sum_odd += 6;
		}

		if (swithcedarray[i] * 2 == 16)
		{
			sum_odd += 7;
		}

		if (swithcedarray[i] * 2 == 17)
		{
			sum_odd += 8;
		}

		if (swithcedarray[i] * 2 == 18)
		{
			sum_odd += 9;
		}
	}

	// main calculation
	for (int i = 0; i < 15; i += 2)
	{

		sum_even+= swithcedarray[i];

	}

	final_num = sum_even + sum_odd;

	last_num = final_num % 10;

	if (last_num == 0){ printf("your card number passed Luhn's test\n"); }
	else
	{
		printf("your card number failed the Luhn's test\n");
	}
	
	return 0;
}



int type()
{
	if (larray[0] == 3 && (larray[1] == 4 || 7))
	{
		printf(" you have an American Express card \n");
	}

	else if (larray[0] == 4)
	{
		printf(" you have a Visa card \n");
	}

	else if (larray[0] == 5 && larray[1] < 5 && larray[1] > 0)
	{
		printf(" you have a Master card \n");
	}
	return 0;
}