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

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("ERROR pid");
			return (-1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				return (-1);
		}
		else
		{
			wait(0);
		}
		for (int i = 0; argv[i] != NULL; i++)
			printf("argv[%d] = %s\n", i, argv[i]);
		free(command);
		}
	return (0);
}
