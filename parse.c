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
	newline = _strdup(line);
	p = strtok (newline, " \t\r\n\f\v");
	while (p != NULL)
	{
		array[i++] = p;
		p = strtok (NULL, " \t\r\n\f\v");
	}
	array[i] = NULL;

	return (array);
}
