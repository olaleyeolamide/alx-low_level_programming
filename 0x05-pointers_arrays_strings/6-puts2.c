#include <stdio.h>
#include "main.h"

/**
 * puts2 - print every other character of a string
 * @*str: string to be printed
 * Return: void
 */

void puts2(char *str)

{
	char *str;

	for (; *str != '\0'; *str = +2)
	{
		_putchar(*str);
	}
	_putchar('\n')

}
