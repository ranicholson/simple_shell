#include "holberton.h"

int main(int ac, char **av, char *envp[])
{
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
		num_tokens = 0;
	        getline(&line, &bufsize, stdin);
		tokens = parse();
		if (_strcmp(tokens[0], "exit") == 0)
			break;
		execute(tokens);
		free(line);
	}
	return (0);
}
