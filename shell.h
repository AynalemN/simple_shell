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
#define READ_BUF_SIZE 1024

/* for command chaining */
#define CMD_NORM	0

/* for History */
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@argc: the argument count
 *@err_num: the error code for exit()s
 *@status: the return status of the last exec'd command
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@path: a string path for the current command
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
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
	int linecount_flag;
	list_t *env;
	char *fname;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
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

/* toem_getpath.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

#endif/* SHELL_H */
