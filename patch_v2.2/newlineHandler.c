#include "strLib.h"
#include <stdlib.h>
/**
 * newlineOrSpaceHandler - frees if spaces followed by newline or just newline
 * @str: array of strings to be checked
 */
void newlineOrSpaceHandler(char **str)
{
	if (CheckNewlineOrSpace(*str))
	{
	free(*str);
	*str = NULL;
	}
}
