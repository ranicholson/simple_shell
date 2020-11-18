#include "holberton.h"

int checkbltin(char **ar)
{
	int i = 0;

	if (_strcmp(ar[0], "exit") == 0)
		return (1);
	if (_strcmp(ar[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (2);
	}
	return (0);
}
