#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets value to 0 at a given index
 * @n: number to evaluate
 * @index: given index
 * Return: 0 
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((0UL << index ) | *n);
	return (0)

}	
