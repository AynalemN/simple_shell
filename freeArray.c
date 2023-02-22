#include "shell.h"
/**
 * freeArray- to free the array
 * @arr: is the array
 * Return: void
 */
void freeArray(char **arr)
{
	for (int i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
