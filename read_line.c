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

	if (getline(&line, &bufsize, stdin) == -1)
	{
		_puts("\n");
		free(line);
		exit(EXIT_SUCCESS);
	} else
	{
		line[_strlen(line) - 1] = '\0';
	}
	return (line);
}

