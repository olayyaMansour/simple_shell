#include "main.h"

int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		displayPrompt();
		line = readLine();
		args = splitLine(line);
		status = execute(args); //returns 0 on success and a non-zero value on failure, so we can use it as the condition for the do-while loop to keep the shell running until the user types exit or presses Ctrl+D to exit the shell.
		free(line);
		free(args);
	} while (status);

	return (0);
}

