#include "shell.h"
/**
 * freeMemory- to free the pointers and NULL addresses
 * @ptr: is the address to be freed
 * Return: 1 if freed, else 0
 */
int freeMemory(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
