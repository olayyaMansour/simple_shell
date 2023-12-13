#include "dataHandlers.h"
#include "strLib.h"
#include "core.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void onTrigger(char *, short Counter);
void onExit(char **, short);
void replaceVariables(char **Cmd, int exitStatus);
/**
 * onSession_start - starts a session
 * calls onTrigger() func in an infinte loop
 * @argc: argument counter to be driven from main
 * @str: string that holds name of exe shell driven from main
 */
void onSession_start(int argc, char *str)
{
	short Counter = 0;
	(void) argc;

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
 * @Counter: counts entered commands
 */
void onTrigger(char *str, short Counter)
{
	char *userInput = ReadData("$ ");
	char **Cmd = NULL;
	short log = 0;

	if (userInput == NULL)
		return;

	newlineOrSpaceHandler(&userInput);

	Cmd = strParsing(userInput, NULL, NULL, NULL);
	if (Cmd && Cmd[0])
	{
		char exitFunc = _strCompare(Cmd[0], "exit");
		char envFunc = _strCompare(Cmd[0], "env");

		replaceVariables(Cmd, log);
		if (exitFunc == false || envFunc == false)
		{
		builtInHandler(Cmd, log);
		}
		else
		{
		log = executeCommands(Cmd, str, Counter);
		}
	}
}
/**
 * onExit - exits the session
 * @Cmd: command entered by user (Unused param)
 * @log: user logs Infos (currently has only status builtIn)
 */
void onExit(char **Cmd, short log)
{
	(void)Cmd;
	exit(log);
}
