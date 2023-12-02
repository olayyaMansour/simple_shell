#include "strLib.h"
/**
 * _strDuplicate - allocate memory and returns
 * a pointer to a cpied string
 * @str: string to be duplicated
 *
 * used malloc to allocate memory
 * checks:
 * if string @str is NULL
 * if CopiedStr allocated memory
 *
 * loop for copying @str to CopiedStr by index
 * after a successful memory allocation
 *
 * Return: pointer to the newly allocated memory
 * CopiedStr(full string)
 */
char *_strDuplicate(char *str)
{
	char *CopiedStr;

	if (str == NULL)
	{
	return (NULL);
	}
	else
	{
	unsigned short i = 0, Length = (strlen(str));

	CopiedStr = malloc(Length + 1);

	if (CopiedStr == NULL)
		return (NULL);

	for (i = 0; i <= Length; i++)
		CopiedStr[i] = str[i];

	CopiedStr[Length + 1] = '\0';
	}

	return (CopiedStr);
}
