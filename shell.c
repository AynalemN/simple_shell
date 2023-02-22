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
		int argc = 0;
		char *delim = " \n";
		char *command = readInput();
		char **argv = tokenizes(&argc, command, delim);

		executeBypath(argv);
		freeArray(argv);
		free(command);
		}
	return (0);
}
