#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <fcntl.h>

char **tokenizes(int *argc, char *command,  char *delim);
char *readInput(void);
int executeBypath(char **argv);

/* for read/write buffers */
#define BUF_FLUSH -1

/* for History */
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@argc: the argument count
 *@err_num: the error code for exit()s
 *@status: the return status of the last exec'd command
 *@env: linked list local copy of environ
 *@path: a string path for the current command
 *@fname: the program filename
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@history: the history node
 *@alias: the alias node
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	int argc;
    char *path;
	int status;
	int err_num;
	list_t *env;
    char *fname;
    list_t *history;
    list_t *alias;
    char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
    int histcount;
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

/* toem_history_aliance.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* toem_environ.c */
int _myenv(info_t *);
char *_getenv(info_t *, const char *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);

#endif/* SHELL_H */
