#include "dataHandlers.h"
#include "pathLib.h"

void exeChildProcess(char *, char **);
short waitForChildProc(pid_t, char *, char **);
/**
 * executeCommands - execute a command using fork and execve
 * @Cmd: command to be executed
 * @str: string to hold name of the exe shell
 * @Counter: counts entered commands
 * forks a new process then check for fork error
 * Return: true if command has been executed
 * successfully otherwise false
 */
bool executeCommands(char **Cmd, char *str, short Counter)
{
	pid_t procId;
	char *cmdPath = NULL;

	cmdPath = (char *)pathHandler(Cmd[0], NULL, NULL);

	if (!(cmdPath))
	{
	_perror(str, Cmd[0], Counter, ": Not found\n");
	_freeArr(Cmd);
	return (true);
	}

	procId = fork();

	if (procId == -1)
	{
		perror("Err! Couldn't fork");
		_freeArr(Cmd);
		return (true);
	}
	else if (procId == 0)
	{
		exeChildProcess(cmdPath, Cmd);
	}
	else
	{
		int exitStatus = waitForChildProc(procId, cmdPath, Cmd);

		_freeMemo(cmdPath, NULL), _freeArr(Cmd);
		return (exitStatus != false ? (false) : (true));
	}
	return (false);
}
/**
 * exeChildProcess - executes child process using execve
 * @cmdPath: path to exe command
 * @Cmd: array of strings where first element is the cmd
 */
void exeChildProcess(char *cmdPath, char **Cmd)
{
	if (execve(cmdPath, Cmd, environ) == -1)
	{
	_freeMemo(cmdPath, NULL);
	_freeArr(Cmd);
	}
}
/**
 * waitForChildProc - waits for child process to terminate
 * @procId: process ID of child process
 * @cmdPath: path to the exe command
 * @Cmd: cmd and its arguments as an array
 * Return:
 * exit status of child process
 */
short waitForChildProc(pid_t procId, char *cmdPath, char **Cmd)
{
	pid_t waitprocId;
	int exitStatus = 0;

	do {
	waitprocId = waitpid(procId, &exitStatus, 0);
	if (waitprocId == -1)
	{
	perror("Err! Couldn't wait for child process termination");
	_freeMemo(cmdPath, NULL);
	_freeArr(Cmd);
	return (true);
	}
	} while (waitprocId == 0);

	return (exitStatus);
}
