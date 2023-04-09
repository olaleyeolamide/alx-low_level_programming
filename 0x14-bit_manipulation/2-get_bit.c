#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit
 * @n: number to evaluate
 * @index: given index
 * Return: Always 0
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
