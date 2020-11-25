#include "holberton.h"

/**
 * exe - function to execute new processes
 * @line: input from user
 * @ar: array to be handled by execve
 * @nln: duplicate of line
 * @arry: Tokens to check
 * @argv: arguments
 * @flcnt: number of commands that have failed
 * Return: 0 for success
 */

int exe(char *line, char **ar, char *nln, char **arry, char **argv, int flcnt)
{
	int status, onpath = -1;
	pid_t child;
	struct stat *statbuf;

	statbuf = malloc(sizeof(struct stat)); /* creates status buffer */
	if (stat(ar[0], statbuf) == -1) /* checks if filename or path */
	{
		onpath = findonpath(ar); /* if file name, searchespath for it */
		if (onpath == 0)
		{
			free(statbuf); /* if on path go back */
			return (0);
		}
	}
	child = fork(); /* forks a child process */
	if (child == 0)
	{
		if (execve(ar[0], ar, environ) == -1) /* attempt execute file */
		{
			_printf("%s: %d: %s: not found\n", argv[0], flcnt, ar[0]);
			free(statbuf);
			myfree(line, ar, nln, arry);
			_exit(-1); /* terminates the child */
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child) /* waits for child */
			;
	}
	free(statbuf);
	if (status == 0) /* checks if execve failed or succeeded */
		errno = 0;
	if (status == 512)
		errno = 2;
	if (status == 65280)
		errno = 127;
	return (0);
}
