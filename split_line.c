#include "main.h"
/**
 * splitLine - split a line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char **splitLine(char *line) 
{
	size_t bufsize = BUFFER_SIZE;
	size_t position = 0;
	char **args = malloc(bufsize * sizeof(char *));
	char *token;

	if (!args)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n\r\a");
	while (token != NULL)
	{
		args[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			args = realloc(args, bufsize * sizeof(char *));
			if (!args)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\n\r\a");
	}
	args[position] = NULL;
	return (args);
}

