#include "strLib.h"
/**
 * _strCpNConcat - copies string 1 and 2 into an array then concatenate
 * @firstStr: first string to copy
 * @secondStr: second string to copy
 * Return: full new copied and concatenated string
 */
char *_strCpNConcat(char *firstStr, char *secondStr)
{
	char *newStrArr = NULL;
	short firstStrLength = strlen(firstStr) + 1;
	short secondStrLength = strlen(secondStr) + 1;
	short i = 0, j = 0;

	if (firstStr == NULL || secondStr == NULL)
		return (NULL);

	newStrArr = (char *)malloc(firstStrLength + secondStrLength);

	if (newStrArr == NULL)
		return (NULL);

	for (i = 0; i < (firstStrLength - 1); i++)
		newStrArr[i] = firstStr[i];

	newStrArr[i++] = '/';

	while (j < (secondStrLength - 1))
		newStrArr[i++] = secondStr[j++];

	newStrArr[i] = '\0';
	return (newStrArr);
}
