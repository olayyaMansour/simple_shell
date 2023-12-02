#include "main.h"
/**
 * isEnvCommand - check if the command is env
 * @args: array of arguments
 * 
 * Return: 1 if the command is env, 0 otherwise
 */
int isEnvCommand(char **args)
{
	return (args[0] != NULL && strcmp(args[0], "env") == 0);
}
