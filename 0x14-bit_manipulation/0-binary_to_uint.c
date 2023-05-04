#include "main.h"

/**
 * binary_to_uint - convert binary to unsigned integer
 * @b: number to be converted
 *
 * Return: converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int cval = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		cval = 2 * cval + (b[i] - '0');
	}

	return (cval);
}
