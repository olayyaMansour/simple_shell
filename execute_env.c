#include "main.h"
extern char **environ;

/**
 * executeEnv - execute the env command
 *
 * Return: nothing
 */
void executeEnv()
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}
