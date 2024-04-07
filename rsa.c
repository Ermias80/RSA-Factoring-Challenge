#include <stdio.h>
#include <stdlib.h>
/* is_prime - Checks if a given number is prime
 * @num: The number to be checked
 *
 * It returns 1 if the number is prime, and 0 otherwise.
 */
int is_prime(long long num)
{
	if (num <= 1)
		return (0);
	if (num <= 3)
		return (1);
	if (num % 2 == 0 || num % 3 == 0)
		return (0);
	for (long long i = 5; i * i <= num; i += 6)
		if (num % i == 0 || num % (i + 2) == 0)
			return (0);
	return (1);
}
/**
 * factorize - Factorizes a given number into its prime factors
 * @num: The number to be factorized
 */
void factorize(long long num)
{
	printf("%lld=", num);
	for (long long i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			if (is_prime(i))
			{
				printf("%lld", i);
				num /= i;
				break;
			}
		}
	}
	while (num > 1)
	{
		for (long long i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{
				if (is_prime(i))
				{
					printf("*%lld", i);
					num /= i;
					break;
				}
			}
		}
	}
	printf("\n");
}
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Returns:
 *  - 0 on successful execution
 *  - 1 if incorrect number of command-line arguments is provided
 */
int main(int argc, char *argv[])
{
	long long num = 0;

	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return 1;
	}
	num = atoll(argv[1]);
	factorize(num);
	return 0;
}
