#include "pathLib.h"
#include "strLib.h"
/**
 * builtInHandler - compares and checks userInput command
 * @Cmd: command enter by user
 * @log: used to check log of userInput
 * (currently checks only the user status)
 */
void builtInHandler(char **Cmd, short log)
{
	if (Cmd == NULL || Cmd[0] == NULL)
		return;

    	if (_strCompare(Cmd[0], "exit") == 0)
	{
	    _freeArr(Cmd);
	    exit(log);
	}
	else if (_strCompare(Cmd[0], "env") == 0)
	{
	_freeArr(Cmd);
	pEnv(Cmd, log);
	}
}
