#include <stdio.h>

/**
 * main - print diferent combinations of three digits
 * Return: Always 0
 */
int main(void)
{
	int c;
	int d;
	int e = 0;

	while (e < 10)
	{
		d = 0;
		while (d < 10)
		{
			c = 0;
			while (c < 10)
			{
				putchar('0' + c);
				putchar('0' + d);
				putchar('0' + e);

				if (c + d + e != 9 + 8 + 7)
				{
					putchar(',');
					putchar(' ');
				}

			}
			c++;

		}
		d++;

	}
	e++;

putchar('\n');
return (0);
}
