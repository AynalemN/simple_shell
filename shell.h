#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

char **tokenizes(int *argc, char *command,  char *delim);
char *readInput(void);
int executeBypath(char **argv);

typedef struct passinfo
{
	char *arg;
	char **argv;
	int argc;
	int status;
	int err_num;
} info_t;

/* toem_freeArray.c */
int freeMemory(void **);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);

#endif/* SHELL_H */
