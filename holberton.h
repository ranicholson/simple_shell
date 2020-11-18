#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>

extern char **environ;

int shell_terminal;
int shell_interaction;

char *_strdup(char *str);

int _strcmp(char *s1, char *s2);

int parse(char *line, int num_tokens);

void execute(char **tokens);

void myfree(char* line, char **ar, char *newline, char **array, int num_tokens);

int checkbltin(char **ar);

int numcount(char *line);

#endif /* HOLBERTON_H */
