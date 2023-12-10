#include "main.h"

/**
 * splitLine - split a line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char** splitLine(char* line)
{
	size_t bufsize = BUFFER_SIZE;
	size_t position = 0;
	char** args = malloc(bufsize * sizeof(char*));
	char* token = NULL;
	char* delimiter = " \t\n\r\a";
	char *arg_start;

	if (!args)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = line;
	while (*token != '\0')
	{
		while (*token != '\0' && strchr(delimiter, *token) != NULL)
			token++;

		if (*token == '\0')
			break;

		arg_start = token;

		while (*token != '\0' && strchr(delimiter, *token) == NULL)
			token++;

		args[position] = malloc((token - arg_start + 1) * sizeof(char));

		if (args[position] == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}

		strncpy(args[position], arg_start, token - arg_start);
		args[position][token - arg_start] = '\0';
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			args = realloc(args, bufsize * sizeof(char*));
			if (!args)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}
	}

	args[position] = NULL;
	return args;
}

