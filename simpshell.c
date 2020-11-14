#include "holberton.h"

int main(int ac, char **av, char *envp[])
{
	int i = 0;
	char *line = NULL;
	size_t bufsize = 0;
	char **tokens;

	ac = ac;
	av = av;
	envp = envp;

	shell_terminal = STDIN_FILENO;
	shell_interaction = isatty(shell_terminal);

	while (shell_interaction)
	{
		printf("($) ");
	        getline(&line, &bufsize, stdin);
		tokens = parse(line);
		if (_strcmp(tokens[0], "exit") == 0)
			break;
		execute(tokens);
		i = 0;
		printf("Number Of Tokens: %d\n", num_tokens);
		while (i < num_tokens)
		{
			printf("%s\n", tokens[i]);
			i++;
		}
	}
	i = 0;
	while (i < num_tokens)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(line);
		return (0);
}
