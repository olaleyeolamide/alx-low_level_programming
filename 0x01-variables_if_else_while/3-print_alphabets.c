#include <stdio.h>
/**
 * main - Entry point
 *
 * Description - prints the alphabet in lowercase and then in uppercase
 * followed by a newline
 *
 * return: Always 0 (Success)
 */

int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)

		putchar(ch);
	for (ch = 'A'; ch <= 'Z'; ch++)
		putchar(ch);
	putchar('\n');
return (0);
}
