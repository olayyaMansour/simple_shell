#include "main.h"
/**
 * execute - execute a command
 * @args: array of arguments
 *
 * Return: 1 if the shell should continue, 0 if it should exit
 */
int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	(void)wpid;

	if (args[0] == NULL)
	{
		return (1);
	} 

	pid = fork();

	if (pid == 0) { 
		if (execve(args[0], args, NULL) == -1)
		{
			_puts("./shell: No such file or directory\n");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{ 
		perror("fork error");
	} else
	{ 
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

