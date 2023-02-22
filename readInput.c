#include "shell.h"
/**
 * readInput - reads used input from the terminal
 * Return: the commnad entered
 */
char *readInput(void)
{
	char *command = NULL;
	size_t leng = 0;

	printf("$ ");
	int charRead = getline(&command, &leng, stdin);

	if (charRead == -1)
	{
		free(command);
		return (NULL);
	}
	return (command);
}
