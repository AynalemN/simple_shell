
# Simple_shell
![banner](img/alx_simple_shell.png)
![GitHub repo size](https://img.shields.io/github/repo-size/AynalemN/simple_shell)
![GitHub issues](https://img.shields.io/github/issues/AynalemN/simple_shell)
![GitHub Repo stars](https://img.shields.io/github/stars/AynalemN/simple_shell?logo=github&style=flat)
![GitHub forks](https://img.shields.io/github/forks/AynalemN/simple_shell?logo=github&style=falt)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/AynalemN/simple_shell?logo=github)

## Description

This is a simple implementation of a shell in Linux written in C. The purpose of this project is to replicate the behavior of a shell like Bash, allowing users to execute commands and perform various operations in a Linux environment.

## Getting Started
### Prerequisites
In order to build and run this project, you need to have the following software installed on your system:

- Git
- GCC

## Installing
You can download the source code of this project by running the following command:
```bash
https://github.com/AynalemN/simple_shell.git
```
Once you have downloaded the source code, you can build the executable by running the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
This will create an executable file named `hsh` in the same directory.

## Usage
To run the shell, simply execute the shell executable:
```bash
./shs
```
This will start the shell and display a prompt:
```bash
$
```
You can then type in commands, just like in Bash:

```bash
$ ls -l
total 8
-rw-r--r-- 1 user user  616 Feb 24 14:53 README.md
-rw-r--r-- 1 user user  576 Feb 24 14:53 shell.c

```
To exit the shell, you can use the exit command:
```bash
$ exit
```

## Features
- Running external commands (e.g. ls, echo, etc.)
- Changing directories with the cd command
- Handling of signals (e.g. Ctrl-C to interrupt a command)

## Limitations
- Redirection of standard input and output (e.g. ls > file.txt)
- Pipes (e.g. ls | grep foo)
- It does not support tab completion
- It does not support shell functions or aliases

## Tasks
There was 6 mandatory tasks and 11 advanced tasks, to check the detail click the button below
<details>
<summary>Click To check Detailed tasks</summary>

### Mandatory
0. Write a beautiful code that passes the Betty checks
1. Write a UNIX command line interpreter.
   -  Usage: simple_shell
      -  Display a prompt and wait for the user to type a command. A command line always ends with a new line.
      -  The prompt is displayed again each time a command has been executed.
      -  The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
      -  The command lines are made only of one word. No arguments will be passed to programs.
      -  If an executable cannot be found, print an error message and display the prompt again.
      -  Handle errors.
      -  You have to handle the “end of file” condition `(Ctrl+D)`
   - You don’t have to:
      - use the `PATH`
      - implement built-ins
      - handle special characters : ", ', `, \, *, &, #
      - be able to move the cursor
      - handle commands with arguments
2. Handle command lines with arguments
3. Handle the `PATH`
4. Implement the `exit` built-in, that exits the shell
5. Implement the `env` **built-in**, that prints the current environment
### Advanced
6. Write your own getline function
   - Use a buffer to read many chars at once and call the least possible the `read` system call
   - You will need to use `static` variables
   - You are not allowed to use `getline`
7. You are not allowed to use `strtok`
8. handle arguments for the built-in `exit`
   - Usage: `exit status`, where `status` is an integer used to exit the shell
9. Implement the `setenv` and `unsetenv` builtin commands
    - setenv
      - Initialize a new environment variable, or modify an existing one
      - Command syntax: `setenv VARIABLE VALUE`
      - Should print something on stderr on failure

    - unsetenv
      - Remove an environment variable
      - Command syntax: `unsetenv VARIABLE`
      - Should print something on stderr on failure
10. Implement the builtin command `cd`:
    - Changes the current directory of the process.
    - Command syntax: `cd [DIRECTORY]`
    - If no argument is given to cd the command must be interpreted like `cd $HOME`
    - You have to handle the command `cd -`
    - You have to update the environment variable `PWD` when you change directory
11. Handle the commands separator
12. andle the `&&` and `||` shell logical operators
13. Implement the `alias` builtin command
    - Usage: `alias [name[='value'] ...]`
      - `alias`: Prints a list of all aliases, one per line, in the form `name='value'`
      - `alias name [name2 ...]`: Prints the aliases `name`, `name2`, etc 1 per line, in the form `name='value'`
      - `alias name='value' [...]`: Defines an alias for each `name` whose `value` is given. If `name` is already an alias, replaces its value with `value`
14. Handle variables replacement
    - Handle the `$?` variable
    - Handle the `$$` variable
15. Handle comments `(#)`
16. File as input
    - Usage: `simple_shell [filename]`
    - Your shell can take a file as a command line argument
    - The file contains all the commands that your shell should run before exiting
    - The file should contain one command per line
    - In this mode, the shell should not print a prompt and should not read from `stdin`
</details>


***
### contributors
<a href="https://github.com/AynalemN/simple_shell/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=AynalemN/simple_shell" />
</a>