#include "dataHandlers.h"
#include "MemoHandlers.h"
#include "strLib.h"
#include "core.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void onTrigger(char *);
void onExit(void);
/**
 * onSession_start - starts a session
 * calls onTrigger() func in an infinte loop
 */
void onSession_start(int argc, char *str)
{
	(void) argc;
	while (true)
	{
	onTrigger(str);
	}
}

/**
 * onTrigger - trigger the user input to read from
 * uses custom built string comparison to check
 * for a specified word(string)
 * calls onExit if condition is met
 */
void onTrigger(char *str)
{
	char *userInput = ReadData("$ ");
	char **Cmd = NULL;

	if (userInput == NULL)
		return;

	Cmd = strParsing(userInput, NULL, NULL, NULL);
	if (Cmd && Cmd[0])
	{
		if (_strCompare(Cmd[0], "exit") == false)
		{
			_freeArr(Cmd);	
			onExit();
		}
		else
		{
			int log = executeCommands(Cmd, str);
			char *Err = "Command exited!";
			if (log != -1)
				write(STDOUT_FILENO, Err, strlen(Err));
		}
	}
}
/**
 * onExit - exits the session
 */
void onExit(void)
{
	exit(EXIT_SUCCESS);
}
