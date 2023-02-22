#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

char** tokenizes(int *argc, char *command,  char *delim);
int executeBypath(char **argv);

#endif/* SHELL_H */
