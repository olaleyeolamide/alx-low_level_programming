#include "main.h"

/**
 * create_file - creates file
 * @filename: A pointer to the name of the file to be created
 * @text_content: Points to the string to write in the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int F, W, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	F = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	W = write(F, text_content, len);

	if (F == -1 || W == -1)
		return (-1);

	close(F);

	return (1);
}
