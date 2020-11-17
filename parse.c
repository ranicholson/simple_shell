#include "holberton.h"
char *_strdup(char *str)
{
    char *ar;
    unsigned int i, size;

    if (str == NULL)
        return (NULL);
    for (size = 0; *(str + size) != '\0'; size++)
        ;
    ar = malloc((size + 1) * sizeof(char));
    if (ar == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
    {
        ar[i] = str[i];
    }
    ar[i] = '\0';
    return (ar);
}

void parse(char *line, int num_tokens)
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
	printf("Tokens before tokens alloc: %d", num_tokens);
	ar = malloc(sizeof(char *) * (num_tokens + 1));

	for (i = 0; i < num_tokens; i++)
	{
		ar[i] = _strdup(array[i]);
		printf("After strdup ar[%d] = %s\\0\n", i, ar[i]);
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
		exit(98);
	}
	execute(ar, num_tokens);
	for (i = num_tokens; i >= 0; i--)
		free(ar[i]);
	free(ar);
        free(newline);
	free(line);
	free(array);
}
