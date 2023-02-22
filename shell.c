#include "shell.h"
/**
 * main - display prompt and wait for user to enter a command,
 * display an error if EOF and execute the program
 * Return: Always 0
 */
int main(void)
{
	while (true)
	{
		char *command = NULL;
		size_t leng = 0;

		printf("$ ");
		int charRead = getline(&command, &leng, stdin);

		if (charRead == -1)
		{
			free(command);
			return (-1);
		}
		int argc = 0;
		char *delim = " \n";
		char **argv = tokenizes(&argc, command, delim);

		executeBypath(argv);
		free(command);
		}
	return (0);
}
