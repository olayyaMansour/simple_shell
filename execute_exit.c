#include "main.h"
void executeExit(char **args)
{
    int status = EXIT_SUCCESS;

    if (args[1] != NULL)
    {
        char *endptr;
        long temp = strtol(args[1], &endptr, 10);

        if (*endptr != '\0' || temp > INT_MAX || temp < INT_MIN)
        {
            _puts("Error: exit: ");
            _puts(args[1]);
            _puts(": numeric argument required\n");
            status = EXIT_FAILURE;
        }
        else
        {
            status = (int)temp;
        }
    }
    exit(status);
}

