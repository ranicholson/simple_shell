#include "holberton.h"

void execute(char **tokens)
{
	int i = 0;
	char *ar[10];

	while (i < num_tokens)
	{
		ar[i] = _strdup(tokens[i]);
		i++;
	}
	ar[i] = NULL;
	while(ar[i] != NULL)
	{
		printf("%s", ar[i]);
		i++;
	}
	/*
	if (execve(ar[0], ar, NULL) == -1)
	{
		perror("Error:");
	}
	*/
	/*
	int i = 0, j = 0;
	char **argv;

	while (i < num_tokens)
	{
		len = 0;
		while (tokens[i])
		{
			*(argv + i) = _strdup(tokens[i]);
		}
		i++;
 	}
	execve(tokens[0], tokens, NULL);
	*/
}
