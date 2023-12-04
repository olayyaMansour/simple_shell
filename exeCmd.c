#include "dataHandlers.h"
/**
 * executeCommands - execute a command using fork and execve
 * @Cmd: command to be executed
 * @str: string to hold name of the exe shell
 * forks a new process then check for fork error
 * Return: true if command has been executed
 * successfully otherwise false
 */
bool executeCommands(char **Cmd, char *str)
{
	pid_t procId;

	procId = fork();

	if (procId == -1)
	{
		perror("Err! Couldn't fork");
		_freeArr(Cmd);
		return (true);
	}
	else if (procId == 0)
	{
		if (execve(Cmd[0], Cmd, environ) == -1)
		{
		perror(str);
		_freeArr(Cmd);
		_exit(EXIT_FAILURE);
		}
	}
	else
	{
		pid_t waitprocId;
		int exitStatus;

		do {
		waitprocId = waitpid(procId, &exitStatus, 0);
		if (waitprocId == -1)
		{
		perror("Err! Couldn't wait for child process termination");
		_freeArr(Cmd);
		return (true);
		}
		} while (waitprocId == 0);

		_freeArr(Cmd);
		return (exitStatus != false ? (false) : (true));
	}
	return (false);
}
