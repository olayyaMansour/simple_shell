#include "MemoHandlers.h"
/**
 * _freeMemo - frees strings
 * @firstStr: first string to be deallocated
 * @secondStr: second string to be deallocated
 */
void _freeMemo(char *firstStr, char *secondStr)
{
	free(firstStr);
	free(secondStr);
}
