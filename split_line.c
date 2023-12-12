#include "main.h"
char **splitLine(char *line)
{
    size_t bufsize = BUFFER_SIZE;
    size_t position = 0;
    char **args = malloc(bufsize * sizeof(char *));
    char *token = NULL;
    char *delimiter = " \t\n\r\a";
    char *arg_start;
    size_t i;

    if (!args)
    {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delimiter);
    while (token != NULL)
    {
        if (position >= bufsize)
        {
            bufsize += BUFFER_SIZE;
            args = realloc(args, bufsize * sizeof(char *));
            if (!args)
            {
                perror("realloc error");
                exit(EXIT_FAILURE);
            }
        }

        arg_start = token;
        args[position] = strdup(arg_start);
        if (args[position] == NULL)
        {
            perror("strdup error");
	    for(i = 0; i < position; i++)
	    {
		    free(args[i]);
	    }
            exit(EXIT_FAILURE);
        }

        position++;

        token = strtok(NULL, delimiter);
    }

    args[position] = NULL;
    return args;
}

