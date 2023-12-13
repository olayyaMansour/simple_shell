#include "main.h"
/**
 * executeExit - execute the exit command
 * @args: array of arguments
 *
 * Return: nothing
 */
void executeExit(char **args)
{
	int status = EXIT_SUCCESS;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);

		if (status == 0 && args[1][0] != '0')
		{
			_puts("Error: exit: ");
			_puts(args[1]);
			_puts(": numeric argument required\n");
			status = EXIT_FAILURE;
		}
	}
	exit(status);
}

