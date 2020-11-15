#include "holberton.h"

char **parse() {

	int i = 0, check = 1;
	char *p;
	char *newline;
	char **array;

	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == 10 || line[i] == '\t')
			check = 1;
		else if (check == 1)
		{
			check = 0;
			++num_tokens;
		}
		i++;
	}
	i = 0;

	array = malloc(sizeof(char *) * (num_tokens + 1));
	newline = line;
	p = strtok (line, " \t\r\n\f\v");
	while (p != NULL)
	{
		array[i++] = p;
		p = strtok (NULL, " \t\r\n\f\v");
	}
	array[i] = NULL;
	return (array);
}
