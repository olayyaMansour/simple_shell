#include "strLib.h"
#include "dataHandlers.h"
char *handleNewDirec(char **, char *, char *, short);
char *handleOldDirec();
/**
 * changeDirecHandler - changes from old->new dir and updates envVar
 * @Cmd: gets the name of the command to be executed
 * @str: gets the name of the custom exe shell
 * @direc: gets the target directory
 * @Counter: counts entered commands
 * calls handleNewDirec() and handleOldDirec() functions
 * checks if new directory is NULL or not
 * checks if old directory(current) is NULL or not
 * updates envVars PWD & OLDPWD when changing directory
 * frees memory on failure
 * changes the working directory base on the user input.
 */
void changeDirecHandler(char **Cmd, char *direc, char *str, short Counter)
{
	char *Err = NULL;
	char *newDirec = handleNewDirec(Cmd, direc, str, Counter);
	char *oldDirec = handleOldDirec();

	if (newDirec == NULL)
	{
	Err = " : no such file or directory\n";
	_perror(str, Cmd[0], Counter, Err);
	exit(99);
	}

	if (oldDirec != NULL)
	{
		if (!chdir(newDirec))
		{
		setenv("OLDPWD", oldDirec, 1);
		setenv("PWD", newDirec, 1);
		}
		else
		{
		Err = " : couldn't change directory\n";
		_perror(str, Cmd[0], Counter, Err);
		_freeMemo(newDirec, oldDirec);
		return;
		}
	}
	else
	{
	Err = " : Err! couldn't get this directory\n";
	_perror(str, Cmd[0], Counter, Err);
	_freeMemo(newDirec, NULL);
	exit(99);
	}

	_freeMemo(newDirec, oldDirec);
}
/**
 * handleNewDirec - handles new direc based on userInput
 * @Cmd: gets the name of the command to be executed
 * @str: gets the name of the custom exe shell
 * @direc: gets the target directory
 * @Counter: counts entered commands
 * Return:
 * gets back a string(new directory) or NULL on failure
 */
char *handleNewDirec(char **Cmd, char *direc, char *str, short Counter)
{
	char checker = (direc == NULL ? 0 : _strCompare(direc, "-"));
	char *newDirec = NULL;
	const char *Err = NULL;

	switch (checker)
	{
	case 0:
		newDirec = envHandler("HOME", NULL, NULL);
		break;
	case 1:
		newDirec = envHandler("OLDPWD", NULL, NULL);
		break;
	default:
		newDirec = _strDuplicate(direc);

		if (newDirec == NULL)
		{
		Err = " : No such file or directory\n";
		_perror(str, Cmd[0], Counter, Err);
		return (NULL);
		}
	}

	return (newDirec);
}
/**
 * handleOldDirec - handles old(current) working directory
 * Return:
 * gets back a string(new directory) or NULL on failure
 */
char *handleOldDirec()
{
	return (getcwd(NULL, 0));
}
