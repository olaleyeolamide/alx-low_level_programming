#include "shell.h"

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100

/**
 * execute_command - execute inputed command
 * @command: user's command
 *
 * Return: 0 if successful, 1 for otherwise
 */

void execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	char *token_;
	int i = 0;

	token_ = strtok(command, " ");

	while (token_ != NULL)
	{
		args[i++] = token_;
		token_ = strtok(NULL, " ");
	}

	args[i] = NULL;

	if (execve(args[0], args, NULL) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}

/**
 * run_my_shell - runs the command in the shell
 *
 * Return: 0 if successful
 */

void run_my_shell(void)
{
	char input = NULL;
	char *commands[MAX_COMMANDS];
	char *token;
	ssize_t characters_read;
	int command_num_inp = 0;
	int i;

	while (1)
	{
		printf("$ ");
		characters_read = getline(&input, &input_size, stdin);

		if (characters_read == -1)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
	}

		input[_strcspn(input, "\n")] = '\0';
		token = strtok(input, ";");

		while (token != NULL)
		{
			commands[command_num_inp++] = token;
			token = strtok(NULL, ";");
		}

		for (i = 0; i < num_commands; i++)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("Error forking process");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				execute_command(commands[i]);

				exit(EXIT_SUCCESS);
			}
			else
			{
				wait(NULL);
			}
		}

		num_command_num_inp = 0;
	}
}

/**
 * main - tests the code
 *
 * Return: 0 for success
 */

int main(void)
{
	run_shell();
	return (0);
}
