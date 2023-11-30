#include "main.h"
/**
 * splitLine - split a line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char **splitLine(char *line)
{
	char **args = malloc(2 * sizeof(char *));

	args[0] = line;
	args[1] = NULL;

	return (args);
}

