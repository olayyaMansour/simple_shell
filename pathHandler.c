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

char *pathHandler(char *Cmd, char* Path, char *orignalPath)
{
  char *envValue = envHandler("PATH", NULL, NULL);

    if (!envValue)
        return NULL;

    // Check if Cmd already contains a '/'
    if (FwdSlashContainer(Cmd))
    {
        if (isValidPath(Cmd))
	  _freeMemo(envValue, NULL);
	return (_strDuplicate(Cmd));

	
        return NULL;
    }
    else
    {
        char *Direc = strtok(envValue, ":");

        while (Direc != NULL)
        {
            orignalPath = _strCpNConcat(Direc, Cmd);
            if (isValidPath(orignalPath))
            {
	      _freeMemo(envValue, NULL);
	      return (orignalPath);
            }
            _freeMemo(orignalPath, NULL);
            Direc = strtok(NULL, ":");
        }
    }

    _freeMemo(envValue, NULL);
    return (NULL);
}

/*
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <executable>\n", argv[0]);
        return 1;
    }

    char *Cmd = (char *)pathFinder("PATH", argv[1], NULL, NULL);

    if (Cmd != NULL)
    {
        printf("Executable path: %s\n", Cmd);
        free(Cmd);
    }
    else
    {
        printf("Executable not found in PATH\n");
    }

    return 0;
}
*/
