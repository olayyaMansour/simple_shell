#include "pathLib.h"
/**
 * pEnv - handles the env variables
 * @Cmd: user entered command (unused param)
 * @log: used to check log of userInput (unused param)
 * (currently checks only the user status)
 */
void pEnv(char **Cmd, short log)
{
    short i = 0;
    (void) log;
    (void) Cmd;
    
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }

}
