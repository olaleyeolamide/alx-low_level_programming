#inclde "shell.h"

/**
 * main - ignores comment in code
 *
 * Return: 0 if successful
 */

int main(void)
{
	char *command = NULL;
	size_t buffer_size = 0;
	ssize_t characters;

	while (1)
	{
		printf("Type your command: ");
		characters = getline(&command, &buffer_size, stdin);

		if (characters > 0 && command[characters - 1] == '\n')
		{
			command[characters - 1] = '\0';
		}

		if (characters <= 1 || command[0] == '#')
		{
			continue;
		}

		printf("Executing command: %s ... \n", command);
	}

	free(command);
	return (0);
}
