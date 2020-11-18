#include "holberton.h"

int parse(char *line, int num_tokens)
{
	int i = 0, bltin;
	char *p = NULL, *newline = NULL, **array = NULL, **ar = NULL;
	char *del = " \t\r\n\f\v";

	array = malloc(sizeof(char *) * num_tokens);
	newline = _strdup(line);
	p = strtok(newline, del);
	if (p == NULL)
	{
		myfree(line, ar, newline, array, num_tokens);
		return (0);
	}
	for (; p != NULL; p = strtok(NULL, del))
		array[i++] = p;

	ar = malloc(sizeof(char *) * (num_tokens + 1));

	for (i = 0; i < num_tokens; i++)
	{
		ar[i] = _strdup(array[i]);
	} ar[i] = NULL;
	bltin = checkbltin(ar);
	if (bltin != 0)
		myfree(line, ar, newline, array, num_tokens);
	if (bltin == 1)
		return (1);
	else if (bltin > 1)
		return (2);
	execute(ar);
	myfree(line, ar, newline, array, num_tokens);
	return (0);
}
