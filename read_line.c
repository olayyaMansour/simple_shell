#include "main.h"
/**
 * readLine - reads a line from stdin using getline(),
 * handles EOF (ctrl + d) condition and removes trailing
 * newline character from the input line if present.
 *
 * Return: line read
 */
char *readLine(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	ssize_t bytesRead = getline(&line, &bufsize, stdin);

	if (bytesRead == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		} else
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}
	}

	if (bytesRead > 0 && line[bytesRead - 1] == '\n')
		line[bytesRead - 1] = '\0';

	return (line);
}

