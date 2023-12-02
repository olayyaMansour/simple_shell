#include "strLib.h"
#include "parse.h"
/**
 *
 */
char **parseToken(char **arr, int *counter, int  *limiter, char *token)
{
	if (*counter == (*limiter - 1))
	{
	arr = reshapeArr(arr, limiter, (*limiter) * 2);
	if (!arr)
		return (NULL);
	}

	arr[*counter] = _strDuplicate(token);
	(*counter)++;

	return (arr);
}
