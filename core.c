#include "handlers.h"
#include "addons.h"
#include "core.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void onTrigger(void);
void onExit(void);
/**
 * onSession_start - starts a session
 * calls onTrigger() func in an infinte loop
 */
void onSession_start(void)
{
	while (true)
	{
	onTrigger();
	}
}

/**
 * onTrigger - trigger the user input to read from
 * uses custom built string comparison to check
 * for a specified word(string)
 * calls onExit if condition is met
 */
void onTrigger(void)
{
	char *userInput = ReadData("$ ");

	if (_strCompare(userInput, "exit") == false)
		onExit();
	else
		executeCommands(userInput);
}
/**
 * onExit - exits the session
 */
void onExit(void)
{
	exit(EXIT_SUCCESS);
}
