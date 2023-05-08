#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file and print to standard output.
 * @filename: file to read
 * @letters: letters to read
 * Return: W - num of bytes read and outputed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t F;
	ssize_t W;
	ssize_t let;

	F = open(filename, O_RDONLY);
	if (F == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	let = read(F, buf, letters);
	W = write(STDOUT_FILENO, buffer, let);

	free(buffer);
	close(F);
	return (W);
}
