#include "strLib.h"
/**
 * _strChr - finds the first occurence of a char in a given string
 * @str: string to be fetched
 * @chr: character to find
 * Return:
 * pointer to the first occurence of char in @str
 * Or
 * NULL if chr isn't found
 */
char *_strChr(char *str, short chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
	str++;
	}

	return (NULL);
}
