#include "holberton.h"

int parse(char *line, int num_tokens)
{
	int i = 0;
	char *p;
	char *newline = NULL;
	char **array = NULL;
	char **ar = NULL;

	array = malloc(sizeof(char *) * num_tokens);
	newline = _strdup(line);
	p = strtok (newline, " \t\r\n\f\v");
	while (p != NULL)
	{
		array[i++] = p;
		p = strtok (NULL, " \t\r\n\f\v");
	}

	ar = malloc(sizeof(char *) * (num_tokens + 1));

	for (i = 0; i < num_tokens; i++)
	{
		ar[i] = _strdup(array[i]);
	}
	ar[i] = NULL;
	if (_strcmp(ar[0], "exit") == 0)
	{
		for (i = num_tokens; i >= 0; i--)
			free(ar[i]);
		free(ar);
		free(newline);
		free(line);
		free(array);
		return (1);
	}
	execute(ar);
	for (i = num_tokens; i >= 0; i--)
		free(ar[i]);
	free(ar);
        free(newline);
	free(line);
	free(array);
	return (0);
}
