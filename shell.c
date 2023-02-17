#include <stdio.h>
#include <stdlib.h>
/**
 * main - display prompt and wait for user to enter a command
 * and display an error if EOF
 * also check the buffer allocated
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	size_t leng = 0;

	while (1)
	{
		printf("$ ");
		getline(&command, &leng, stdin);
		printf("%s", command);
		printf("The length of the buffer allocated: %zu\n", leng);
	}
	free(command);
	return (0);
}
