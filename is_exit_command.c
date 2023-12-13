#include "main.h"
/**
 * isExitCommand - check if the command is exit
 * @args: array of arguments
 *
 * Return: 1 if the command is exit, 0 otherwise
 */
int isExitCommand(char **args)
{
	return (args[0] != NULL && strcmp(args[0], "exit") == 0);
}
