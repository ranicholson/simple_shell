#include "holberton.h"

void myfree(char* line, char **ar, char *newline, char **array, int num_tokens)
{
	int i;

	for (i = num_tokens; i >= 0 && ar != NULL; i--)
		free(ar[i]);
	if (ar != NULL)
		free(ar);
	if (newline != NULL)
		free(newline);
	if (line != NULL)
		free(line);
	if (array != NULL)
		free(array);
}
