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
void execute(char **tokens)
{
	int i = 0, status;
	char **ar;
	pid_t child;

	printf("Number Of Tokens in Ex: %d\n", num_tokens);

	ar = malloc(sizeof(char *) * (num_tokens + 1));

	while (i < num_tokens)
	{
		ar[i] = _strdup(tokens[i]);
		printf("After strdup ar[%d] = %s\\0\n", i, ar[i]);
		i++;
	}
	ar[i] = NULL;

	child = fork();

	if (child == 0)
	{
		if (execve(ar[0], ar, NULL) == -1)
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
