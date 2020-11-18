#include "holberton.h"

int main(void)
{
	size_t bufsize = 0;
	char *line = NULL;
	int i, num_tokens;

	shell_terminal = STDIN_FILENO;
	shell_interaction = isatty(shell_terminal);

	if (shell_interaction == 0)
	{
		i = getline(&line, &bufsize, stdin);
	        if (i < 0)
		{
			free(line);
			printf("getline failed\n");
			exit(101);
		}
		num_tokens = numcount(line);
		parse(line, num_tokens);
	}
	while (shell_interaction)
	{
		printf("($) ");
		num_tokens = 0;
	        i = getline(&line, &bufsize, stdin);
		if (i < 0)
		{
			free(line);
			printf("\n");
			break;
		}
		num_tokens = numcount(line);
		if (parse(line, num_tokens) == 1)
			break;
		line = NULL;
	}
	return (0);
}
