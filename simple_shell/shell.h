#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define BUFFER 1000

void exe_comd(char *input, char *av[]);
char *location(char *path, char *arg);
char *get_loc(char *arg);
int env(char *envp[]);
size_t _getline(char **line_buff);

#endif/*SHELL_H*/
