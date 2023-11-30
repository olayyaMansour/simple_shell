#include "main.h"
/**
 * splitLine - split a line into arguments
 * @line: input line
 *
 * Return: array of arguments
 */
char **splitLine(char *line)
{
	/* For now the command lines are made only of one word. No arguments will be passed to programs. So we are just splitting the line into two arguments (command and NULL) and returning it. */

	char **args = malloc(2 * sizeof(char *)); // 2 is the number of arguments (command and NULL)

	args[0] = line;
	args[1] = NULL;

	return (args);
}

