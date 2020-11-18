#include "holberton.h"

void execute(char **tokens)
{
	int status;
	pid_t child;

	child = fork();

	if (child == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror(tokens[0]);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
}
