#include "main.h"

/**
 * append_text_to_file - Adds input to the end of a file.
 * @filename: points to the filename
 * @text_content: additional input
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, W, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	W = write(op, text_content, len);

	if (op == -1 || W == -1)
		return (-1);

	close(op);

	return (1);
}
