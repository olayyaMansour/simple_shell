#include <stdlib.h>
#include "MemoHandlers.h"
/**
 * reshapeArr - resize/reshape array to new size
 * @arr: array to be reshaped
 * @limiter: pointer to current array limiter
 * @resize: new size to reshape array to
 * Return: full reshaped array with specified new size
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
