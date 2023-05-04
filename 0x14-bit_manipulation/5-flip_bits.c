#include "main.h"

/**
 * flip_bits - flip between two num 
 * by a number of bits
 * @n: first num
 * @m: second num
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;
	int count = 0;
	unsigned long int beg;
	unsigned long int lat = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		beg = lat >> i;
		if (beg & 1)
			count++;
	}

	return (count);
}
