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
		printf("After strdup ar[%d] = %s\\0\n", i, ar[i]);
		i++;
	}
	ar[i] = NULL;
	for (i = 0; i < num_tokens; i++)
	{
		printf("%p\n", tokens[i]);
	}
        free(tokens[0]);
	free(tokens);
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
		while (waitpid(-1, &status, 0) != child)
			;
	}
	for (i = 0; i < (num_tokens + 1); i++)
	{
		free(ar[i]);
	}
	free(ar);
}
