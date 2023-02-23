#include "main.h"

/**
 * print_triangle - prints triangles.
 * @size: size of the triangle.
 *
 * Return: no return.
 */
void print_triangle(int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar(35);
		}
		if (i != size - 1)
			_putchar('\n');
	}
	_putchar('\n');
