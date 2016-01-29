#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//used to store the card number
long long cardnum;

//used to store the card number as an integer array
int larray[16];

//stores the number of digits of which the card number is comprised of 
int digitcount;

//check if the card number passed Luhn's test
int passed_test;

int main() 
{
	//stores the option that the user has selected
int option;
	//code is contained in the for loop so that it restarts after an option has been processed such as testing a card
	for (int i = 0; i < 1; i++)
	{ 
		printf("press 1 to run the program or press 2 for help\n");
		scanf("%d", &option);
		if (option == 1)
		{
			cardinput();

			//retrieves the number of digits of which the number is comprised of and stores in the digit count variable
			digitcount = digitcheck();
			printf("digit count = %d \n", digitcount);

			convert();

			//runs the test procedure that corresponds with the number of digits the user has entered
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
			//runs the card type checking procedure
			if (passed_test == 1)
			{
				type();
			}
			
		}
		else if (option == 2)
		{
			printf("to use this program type your card number with no spaces and press enter. \n the relevant information about your card will then be displayed on screen\n\n");
		}
		i--;
	}


	return 0;
}

//this procedure takes the card number the user enters and stores it in the cardnum veritable
int cardinput()
{
	printf("enter your card number \n");
	scanf("%lld", &cardnum);
	return 0;
}

//this function checks number of digits the card number is comprised of and returns it to main
int digitcheck()
{	

	//Used to keep count of the amount of digits the numeber has
	int a = 1;
	//Long long "i" and integer "b" are used to detect the card number leanght
	long long i = 100;
	int b = 9;

	do 
	{
		//checks if the card numebr is greater than "i";
		if (cardnum > i) a++;
		//checks if the card number is greater than b and less than "i" which if so means that the card numebrs order of magnetude has been reached 
		if (cardnum > b && cardnum < i) 
		{
			//sets I equal to 100000000000000001 which stops the loop
			i = 100000000000000001;
		}
		b = b * 10;
		i = i * 10;
	} 
	while (i < 100000000000000000);
	return a += 1;
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
	//holds the values of the numbers in the odd position of the array
	int sum_odd = 0;
	//holds the values of the numbers in the even position of the array
	int sum_even = 0;
	//holds the value of the array reversed
	int swithcedarray[16];
	//holds the final number
	int final_num;
	//holds the last digit of the final number
	int last_num;

		//this loop reverses the array ready for the Luhn's test
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

			for (int b = 1; b < 10; b++)
			{
				//Checks if the given digit in the array according to "i" is 10 or above and if so adds the value of "b" to sum_odd
				if (swithcedarray[i] * 2 == b + 9)
				{
					sum_odd += b;
				}
			}
		}

		final_num = sum_even + sum_odd;

		last_num = final_num%10;
		if (last_num == 0) 
		{ 
			printf("your card number passed Luhn's test\n");
			passed_test = 1;
		}
		else
		{
			printf("your card number failed the Luhn's test\n");
			passed_test = 2;
		}
		return 0;
}


//15 digit test
int test2()
{
	//holds the values of the numbers in the odd position of the array
	int sum_odd = 0;
	//holds the values of the numbers in the even position of the array
	int sum_even = 0;
	//holds the value of the array reversed
	int swithcedarray[15];
	//holds the final number
	int final_num;
	//holds the last digit of the final number
	int last_num;


	for (int i = 0; i < 15; i++)
	{
		swithcedarray[i] = larray[14 - i];
	}

	//this loop reverses the array ready for the Luhn's test
	for (int i = 1; i < 15; i += 2)
	{
		if (swithcedarray[i] * 2 < 10)
		{
			sum_odd += swithcedarray[i] * 2;
		}

	
		//Checks if the given digit in the array according to "i" is 10 or above and if so adds the value of "b" to sum_odd
		for (int b = 1; b < 10; b++)
		{
			if (swithcedarray[i] * 2 == b + 9)
			{
				sum_odd += b;
			}
		}

	}

	// main calculation
	for (int i = 0; i < 15; i += 2)
	{
		sum_even+= swithcedarray[i];
	}

	final_num = sum_even + sum_odd;

	last_num = final_num % 10;

	if (last_num == 0)
	{ 
		printf("your card number passed Luhn's test\n");
		passed_test = 1;
	}
	else
	{
		printf("your card number failed the Luhn's test\n");
		passed_test = 2;
	}
	
	return 0;
}



int type()
{
	//checks if the number is an American express card
	if (larray[0] == 3 && (larray[1] == 4 || 7))
	{
		printf(" you have an American Express card \n");
	}

	//checks if the number is a visa card
	else if (larray[0] == 4)
	{
		printf(" you have a Visa card \n");
	}

	//checks if the number is a master card
	else if (larray[0] == 5 && larray[1] <= 5 && larray[1] > 0)
	{
		printf(" you have a Master card \n");
	}
	return 0;
}