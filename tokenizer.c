#include "shell.h"
/**
 * tokenizes - split a string
 * @argc: the argument count
 * @command: the command entered
 * @delim: a deliminator
 * Return: array of each word of the string
 */
char **tokenizes(int *argc, char *command,  char *delim)
{
	char *token;
	char **argv;

	char *copy_cmd = strdup(command);

	strcpy(copy_cmd, command);

	token = strtok(command, delim);
	(*argc)++;

	while (token)
	{
		(*argc)++;
		token = strtok(NULL, delim);
	}
	/** allocate argv with the number of argc */
	argv = malloc(sizeof(char *) * (*argc));
	token = strtok(copy_cmd, delim);
	int i = 0;

	for (i = 0; token; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
