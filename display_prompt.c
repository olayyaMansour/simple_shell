#include "main.h"

/**
 * displayPrompt - displays a prompt for the user to enter a command
 *
 * Return: void
 */

void displayPrompt(void)
{
	if (isatty(STDIN_FILENO))
	_puts("#cisfun$ ");
}
