#include "holberton.h"

void myfree(char* line, char **ar, char *newline, char **array, int num_tokens)
{
	int i;

	for (i = num_tokens; i >= 0; i--)
		free(ar[i]);
	free(ar);
	free(newline);
	free(line);
	free(array);
}
