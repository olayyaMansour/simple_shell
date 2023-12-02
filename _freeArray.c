#include "MemoHandlers.h"
/**
 * _freeArr - free memory for an array
 * @Arr: array to be freed
 */
void _freeArr(char **Arr)
{
	if (Arr)
	{
	short i;

	for (i = 0; Arr[i] != NULL; i++)
		free(Arr[i]);

	free(Arr);
	}
}
