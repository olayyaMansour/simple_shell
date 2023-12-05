#include "dataHandlers.h"
#include "pathLib.h"
#include "strLib.h"
/**
 * pathFinder - finds path of the specified command to be executed
 * @Path: env var name
 * @Cmd: name of exeCommand to search for
 * @env: path env var
 * @originalPath: pointer to store the valid exe path
 * Return:
 * pointer to the valid exe path
 * or NULL if not found
 */
char **pathFinder(char *env, char *Cmd, char *Path, char **originalPath)
{
	char *Direc = NULL;
	ST_STAT st;

	if (_strChr(Cmd, 47) != NULL)
	{
		if (stat(Cmd, &st) == 0)
			return ((char **)_strDuplicate(Cmd));
	}
	else
	{
	Path = (char *)envHandler(env, NULL, NULL);

	if (Path == NULL || Cmd == NULL)
		return (NULL);

	Direc = strtok(Path, ":");

	while (Direc != NULL)
	{
		originalPath = (char **)_strCpNConcat(Direc, Cmd);

		if (stat((char *)originalPath, &st) == 0)
		{
		_freeMemo(Path, NULL);
		return (originalPath);
		}
		_freeMemo((char *)originalPath, NULL);
		Direc = strtok(NULL, ":");
	}
	}

	_freeMemo(Path, NULL);
	return (NULL);
}
