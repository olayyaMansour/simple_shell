#include "dataHandlers.h"
#include "pathLib.h"
#include "strLib.h"
/**
 * pathHandler - finds path of the specified command to be executed
 * @Path: path env var (Unused because of code refactored)
 * @Cmd: name of exeCommand to search for
 * @originalPath: pointer to store the valid exe path
 * Return:
 * pointer to the valid exe path
 * or NULL if not found
 */

char *pathHandler(char *Cmd, char *Path, char *originalPath)
{
	char *envValue = NULL;
	(void) Path;

	envValue = envHandler("PATH", NULL, NULL);

	if (!envValue)
		return (NULL);

	if (FwdSlashContainer(Cmd))
	{
		if (isValidPath(Cmd))
		{
		_freeMemo(envValue, NULL);
		return (_strDuplicate(Cmd));
		}
	return (NULL);
	}
	else
	{
	char *Direc = strtok(envValue, ":");

	while (Direc != NULL)
	{
	originalPath = _strCpNConcat(Direc, Cmd);
	if (isValidPath(originalPath))
	{
	_freeMemo(envValue, NULL);
	return (originalPath);
	}
	_freeMemo(originalPath, NULL);
	Direc = strtok(NULL, ":");
	}
	}

	_freeMemo(envValue, NULL);
	return (NULL);
}
