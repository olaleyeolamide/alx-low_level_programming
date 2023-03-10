#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @str: character to check the length
 * Return: The length of @str.
 */

size_t _strlen(const char *str)

{
	size_t length = 0;

	while (*str++)
		length++;
	return (length);

}

