#include "holberton.h"

void execute(char **tokens, int num_tokens)
{
	int i = 0, status;
	pid_t child;

	printf("Number Of Tokens in Ex: %d\n", num_tokens);

	for (i = 0; i < num_tokens; i++)
	{
		printf("%p\n", tokens[i]);
	}
	child = fork();

	if (child == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
}
