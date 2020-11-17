#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int shell_terminal;
int shell_interaction;

char *_strdup(char *str);

int _strcmp(char *s1, char *s2);

int parse(char *line, int num_tokens);

void execute(char **tokens);

#endif /* HOLBERTON_H */
