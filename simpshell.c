#include "holberton.h"

int main(int ac, char **av, char *envp[])
{
	size_t bufsize = 0;
	char *line = NULL;
	int i, check = 1;
	int num_tokens;

	ac = ac;
	av = av;
	envp = envp;

	shell_terminal = STDIN_FILENO;
	shell_interaction = isatty(shell_terminal);

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
		for (i = 0; line[i]; i++)
		{
			if (line[i] == ' ' || line[i] == 10 || line[i] == '\t')
				check = 1;
			else if (check == 1)
			{
				check = 0;
				++num_tokens;
			}
		}
		parse(line, num_tokens);
		line = NULL;
/*		if (_strcmp(tokens[0], "exit") == 0)
		exit(98); */
/*		execute(tokens, num_tokens);
		for (i = 0; i <= num_tokens; i++)
			free(tokens[i]);
			free(tokens); */
	}
	return (0);
}
