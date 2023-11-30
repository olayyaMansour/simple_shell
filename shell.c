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
		status = execute(args);
		free(line);
		free(args);
	} while (status);

	return (0);
}

