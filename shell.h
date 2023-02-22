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
void freeArray(char **arr);

/* toem_freeArray.c */
int freeMemory(void **);

/* toem_builtin.c */
int _myexit(info_t *);

#endif/* SHELL_H */
