#include <stdio.h>
#include "main.h"

/**
 * set_bit - set value of bit to 1
 * @n: number to evaluate
 * @index: given index
 * Return: 1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (1UL << index | *n);
		return (1);

}

