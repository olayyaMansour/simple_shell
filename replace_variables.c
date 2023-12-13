#include "dataHandlers.h"
#include "core.h"
/**
 * replaceVariables - replace vars in the command array with their values.
 *
 * @Cmd: array of strings representing the command.
 * @exitStatus: the ecit status to replace "$?" with.
 *
 */
void replaceVariables(char **Cmd, int exitStatus)
{
	int i;

	for (i = 0; Cmd[i] != NULL; i++)
	{
		if (Cmd[i][0] == '$')
		{
			if (strcmp(Cmd[i], "$?") == 0)
			{
				char exitStatusStr[12];

				snprintf(exitStatusStr, sizeof(exitStatusStr), "%d", exitStatus);
				free(Cmd[i]);
				Cmd[i] = _strDuplicate(exitStatusStr);
			}
			else if (strcmp(Cmd[i], "$$") == 0)
			{
				char pidStr[12];

				snprintf(pidStr, sizeof(pidStr), "%d", getpid());
				free(Cmd[i]);
				Cmd[i] = _strDuplicate(pidStr);
			}
			else
			{
				char *envValue = getenv(Cmd[i] + 1);

				if (envValue != NULL)
				{
					free(Cmd[i]);
					Cmd[i] = _strDuplicate(envValue);
				}
			}
		}
	}
}

