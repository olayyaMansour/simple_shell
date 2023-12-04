#include "strLib.h"
#include "parse.h"
/**
 * _INIT_TOKENS - init array of tokens with given limiter
 * @arrToken: array of tokens to get initialized
 * @limiter: pointer to array limiter
 * Return: fully initialized array of tokens with given limiter
 */
char **_INIT_TOKENS(char **arrToken, int *limiter)
{
	arrToken = (char **)malloc(sizeof(char *) * (*limiter));
	return (arrToken);
}
