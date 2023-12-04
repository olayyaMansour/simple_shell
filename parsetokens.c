#include "strLib.h"
#include "parse.h"
/**
 * parseToken - adds tokens to arr(array of tokens), reshape if necessary
 * @arr: array of tokens
 * @counter: pointer to tokens count
 * @limiter: pointer to limiter of arr token
 * @token: token to be parsed(added)
 * Return: full updated array of tokens with newly added tokens
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
