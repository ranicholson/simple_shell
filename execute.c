#include "holberton.h"

void execute(char **tokens)
{
	int i = 0, status;
	char **ar;
	pid_t child;

	printf("Number Of Tokens in Ex: %d\n", num_tokens);
	ar = malloc(sizeof(char *) * (num_tokens + 1));

	while (i < num_tokens)
	{
		ar[i] = _strdup(tokens[i]);
		i++;
	}
	ar[i] = NULL;

	child = fork();

	if (child == 0)
	{
		if (execve(ar[0], ar, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		while (wait(&status) != child)
			;
	}
}
