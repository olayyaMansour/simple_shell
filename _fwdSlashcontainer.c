#include "pathLib.h"
/**
 * FwdSlashContainer - checks if a string contains a forward slash '/' char
 * @str: input string to check
 * Return: true if '/' found in the specified string or false otherwise
 */
bool FwdSlashContainer(const char *str)
{
	return (_strChr((char *)str, 47) != NULL);
}
