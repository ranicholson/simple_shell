#include "holberton.h"

void execute(char **tokens)
{
	int i = 0;
	char **ar;
	printf("Number Of Tokens in Ex: %d\n", num_tokens);
	ar = malloc(sizeof(char *) * (num_tokens + 1));

	while (i < num_tokens)
	{
		ar[i] = _strdup(tokens[i]);
		i++;
	}
	ar[i] = NULL;

	if (execve(ar[0], ar, NULL) == -1)
	{
		perror("Error:");
	}
}
