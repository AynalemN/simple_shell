
# Simple Shell
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
- Background execution of commands (e.g. sleep 10 &)
- It does not support tab completion
- It does not support shell functions or aliases
***

## Tasks
<details>
<summary>Click To check Detailed tasks</summary>

    
</details>


***
### contributors
<a href="https://github.com/AynalemN/simple_shell/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=AynalemN/simple_shell" />
</a>