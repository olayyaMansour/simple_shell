#include "main.h"
/**
 * executeEnv - execute the env command
 *
 * Return: nothing
 */
void executeEnv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}
