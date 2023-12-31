#include "MemoHandlers.h"
#include "dataHandlers.h"
#include "strLib.h"
/**
 * envHandler - retrieves value of an environment var
 * @envName: name of environment variable
 * @envValue: value of environment variable
 * @envKey: key of environment variable
 * Return:
 * value of env variable
 * Or
 * NULL if not found
 */
char *envHandler(char *envName, char *envValue, char *envKey)
{
	char *Temp = NULL;
	char **envPtr = environ;

	while (*envPtr != NULL)
	{
		Temp = _strDuplicate(*environ);
		envKey = strtok(Temp, "=");

		if (!(_strCompare(envKey, envName) && envKey))
		{
		envValue = _strDuplicate(strtok(NULL, "\n"));
		_freeMemo(Temp, NULL);
		return (envValue);
		}

	_freeMemo(Temp, NULL);
	environ++;
	}

	return (NULL);
}
