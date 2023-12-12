#include "main.h"
/**
 * main - Entry point for the simple shell program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	char *line;
	char **args;
	int status;
	size_t j;

	if (argc > 1)
	{
		int i;

		for (i = 1; i < argc; i++)
		{
			line = argv[i];
			args = splitLine(line);
			status = execute(args);

			for (j = 0; args[j] != NULL; j++)
			{
				free(args[i]);
			}
			free(args);
		}
	}
	else
	{
		do {
			displayPrompt();
			line = readLine();
			args = splitLine(line);
			status = execute(args);

			free(line);
			free(args);
		} while (status);
	}

	return (0);
}

