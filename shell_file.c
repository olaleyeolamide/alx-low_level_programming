#include "shell.h"

/**
 * file_commands - execute commands from a file
 * @filename: name of the file containing the commands
 * Return: void
 */

void file_commands(const char *filename)
{
	int my_file = open(filename, O_RDONLY);

	if (my_file == -1)
	{
		printf("File: '%s' not found.\n", filename);

		return;
	}

	char command[MAX_COMMAND_LENGTH];
	ssize_t no_of_bytesRead;

	while ((no_of_bytesRead = read(my_file, command, sizeof(command))) > 0)
	{
		command[no_of_bytesRead] = '\0';

		char *arguments[MAX_ARGUMENTS];
		int argumentCount = 0;
		char *token = strtok(command, " \t\n");

		while (token != NULL && argumentCount < MAX_ARGUMENTS - 1)
		{
			arguments[argumentCount++] = token;
			token = strtok(NULL, " \t\n");
		}
		arguments[argumentCount] = NULL;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(arguments[0], arguments, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0)
		}
	}
	close(file);
}

/**
 * main - tests the code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful, 1 if otherwise
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: simple_shell [filename]\n");
	}
	else
	{
		const char *filename = argv[1];

		file_commands(filename);
	}
	return (0);
}
