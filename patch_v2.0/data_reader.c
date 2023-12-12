#include "dataHandlers.h"
#include "core.h"
/**
 * ReadData - reads user input from terminal
 * @Message: string to be outputed
 * Return: entered user command
 */
char *ReadData(const char *Message)
{
	char *Cmd = NULL;
	size_t sizeOfBuffer = 0;
	ssize_t Length;
	int log = 0;

	if (isatty(STDIN_FILENO))
	{
	write(STDOUT_FILENO, Message, strlen(Message));
	}

	Length = getline(&Cmd, &sizeOfBuffer, stdin);

	if (Length > 0 && Cmd[Length - 1] == '\n')
	{
	Cmd[Length - 1] = '\0';
	}
	else if (Length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
		write(STDOUT_FILENO, "\n", 1);
		free(Cmd);
		onExit(NULL, log);
		}
		else
		{
		free(Cmd);
		onExit(NULL, log);
		}
	}

	return (Cmd);
}

