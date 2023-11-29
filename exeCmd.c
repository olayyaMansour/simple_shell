#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * executeCommands - execute a command using fork and execve
 * @Cmd: command to be executed
 * forks a new process then check for fork error
 * Return: true if command has been executed
 * successfully otherwise false
 */
bool executeCommands(char *Cmd)
{
	pid_t procId;

	procId = fork();

	if (procId == -1)
	{
		perror("Err! Couldn't fork");
		free(Cmd);
		return (false);
	}
	else if (procId == 0)
	{
		char *args[] = {"/bin/sh", "-c", NULL, NULL};

		args[2] = (char *)Cmd;

		if (execve(args[0], args, NULL) == -1)
		{
		perror("Err! Can't execute this command");
		_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int exitStatus;

		if (waitpid(procId, &exitStatus, 0) == -1)
		{
		perror("Err! terminating child process");
		free(Cmd);
		return (false);
		}

		free(Cmd);
		return (exitStatus != false ? (false) : (true));
	}
	return (false);
}
