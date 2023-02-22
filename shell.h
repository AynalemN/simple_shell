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
/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@argc: the argument count
 *@err_num: the error code for exit()s
 *@status: the return status of the last exec'd command
 *@env: linked list local copy of environ
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	int argc;
	int status;
	int err_num;
    list_t *env;
} info_t;

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/* toem_freeArray.c */
int freeMemory(void **);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_environ.c */
int _myenv(info_t *);
char *_getenv(info_t *, const char *);

#endif/* SHELL_H */
