#include "main.h"
/**
* executeCommand - execute a command
* @args: array of arguments
*
* Return: nothing
*/
void executeCommand(char **args)
{
	char *path, *token;

	if (args[0][0] == '/') {
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	} else {
		path = getenv("PATH");
		if (path == NULL) {
			path = "/bin:/usr/bin";
		}

		token = strtok(path, ":");
		while (token != NULL)
		{
			char *full_path = malloc(strlen(token) + strlen(args[0]) + 2);

			if (full_path == NULL)
			{
				perror("malloc error");
				exit(EXIT_FAILURE);
			}

			sprintf(full_path, "%s/%s", token, args[0]);

			if (execve(full_path, args, NULL) == 0)
			{
				free(full_path);
				exit(EXIT_SUCCESS);
			}

			free(full_path);
			token = strtok(NULL, ":");
		}

		_puts("./shell: No such file or directory\n");
		exit(EXIT_FAILURE);
	}
}

