#include "main.h"

/**
 * _isalpha - check for alphabetic character
 * @c: character to be chacked
 * Return: 1 for alphabetic character or 0 if anything else
 */

int _isalpha(int c)

{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);

}
