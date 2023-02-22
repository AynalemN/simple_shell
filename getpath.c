#include "shell.h"
/**
 * executeBypath- getting and executing command by path
 * @argv: the string commands
 * Return: Always 0
 */
int executeBypath(char **argv)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("ERROR pid\n");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		wait(0);
	}
}
