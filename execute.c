#include "main.h"
/**
* execute - execute a command or handle built-in commands
* @args: array of arguments
*
* Return: 1 if the shell should continue, 0 if it should exit
*/
int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	(void)wpid;

	if (isExitCommand(args))
	{
		exit(EXIT_SUCCESS);
	}
	else if (isEnvCommand(args))
	{
		executeEnv();
		return (1);
	}

	pid = fork();

	if (pid == 0)
	{
		executeCommand(args);
	}
	else if (pid < 0)
	{
		perror("fork error");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

