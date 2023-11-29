#include "handlers.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * ReadData - reads user input from terminal
 * @Message: string to be outputed
 * Return: entered user command
 */
char *ReadData(const char *Message)
{
	char *Cmd = NULL;
	unsigned long sizeOfBuffer = 0;

	write(STDOUT_FILENO, Message, strlen(Message));

	getline(&Cmd, &sizeOfBuffer, stdin);

	if (strlen(Cmd) > 0 && Cmd[strlen(Cmd) - 1] == '\n')
		Cmd[strlen(Cmd) - 1] = '\0';

	return (Cmd);
}
