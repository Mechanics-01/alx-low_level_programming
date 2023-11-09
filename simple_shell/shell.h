#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

typedef struct path_node
{
	char *dir;
	struct path_node *next;
}pathnode;

void exe_comd(char *input, char *av[]);
char *location(char *path, char *arg);
char *get_loc(char *arg);

#endif/*SHELL_H*/
