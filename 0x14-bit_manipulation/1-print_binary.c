#include "main.h"

/**
 * print_binary - convert and print binary form
 * @n: number to be converted
 *
 * Return: converted number
 */

void print_binary(unsigned long int n)
{
	int i;
	int count = 0;
	unsigned long int bnum;

	for (i = 63; i >= 0; i--)
	{
		bnum = n >> i;

		if (bnum & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
