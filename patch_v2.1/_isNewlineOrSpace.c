#include "strLib.h"
/**
 * _isNewlineOrSpace - returns either a space or newline
 * @c: charcter to be checked/compared
 * Return: returns truen if either a space or newline
 * otherwise false
 */
bool _isNewlineOrSpace(char c)
{
	return (c == ' ' || c == '\n');
}
/**
 * CheckNewlineOrSpace - checks if a string has a newline or space
 * @str: string to be checked
 * Return: true if string has only spaces or newline
 * otherwise false
 */
bool CheckNewlineOrSpace(const char *str)
{
	size_t i = 0;

	for (i = 0; i < (strlen(str)); i++)
	{
		if (!_isNewlineOrSpace(str[i]))
			return (false);
	}

	return (true);
}
