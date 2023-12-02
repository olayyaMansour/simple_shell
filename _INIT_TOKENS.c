#include "strLib.h"
#include "parse.h"
/**
 *
 */
char **_INIT_TOKENS(char **arrToken, int *limiter)
{
	arrToken = (char **)malloc(sizeof(char *) * (*limiter));
	return (arrToken);
}
