#include "addons.h"

/**
 * _strCompare - compares each char of 2 strings
 * @str1: pointer to the 1st string
 * @str2: pointer to the 2nd string
 * 0 if strings are equal
 * positive or negative if both strings are less or greater
 * Return: an integer value from comparison
 */
short _strCompare(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return ((short)(*str1 - *str2));
		}
	str1++, str2++;
	}
	return ((short)(*str1 - *str2));
}
