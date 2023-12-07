#include "dataHandlers.h"
#include "MemoHandlers.h"
#include "strLib.h"
#include "core.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void onTrigger(char *, short Counter);
void onExit(void);
/**
 * onSession_start - starts a session
 * calls onTrigger() func in an infinte loop
 * @argc: argument counter to be driven from main
 * @str: string that holds name of exe shell driven from main
 */
void onSession_start(int argc, char *str)
{
	(void) argc;
	short Counter = 0;
	
	while (true)
	{
	  onTrigger(str, (Counter += 1));
	}
}

/**
 * onTrigger - trigger the user input to read from
 * uses custom built string comparison to check
 * for a specified word(string)
 * calls onExit if condition is met
 * @str: string that holds name of exe shell driven from main
 */
void onTrigger(char *str, short Counter)
{
	char *userInput = ReadData("$ ");
	char **Cmd = NULL;
	int log = 0;

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
		  log = executeCommands(Cmd, str, Counter);
		  /*	char *Err = "Command exited!\n";

			if (log != -1)
			write(STDOUT_FILENO, Err, strlen(Err));*/
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
