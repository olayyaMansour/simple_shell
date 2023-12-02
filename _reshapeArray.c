#include <stdlib.h>
#include "MemoHandlers.h"
/**
 *
 */
char **reshapeArr(char **arr, int *limiter, short resize)
{
	char **newArr = NULL;
	short i = 0;
	newArr = (char **)malloc(sizeof(char *) * resize);

	if (newArr != NULL)
	{
		for (i = 0; i < *limiter; i++)
			newArr[i] = arr[i];
	}
	else
	{
	_freeArr(arr);
	return (NULL);
	}

	free(arr);
	*limiter = resize;
	return (newArr);
}
