#include "holberton.h"
/**
 * main - entry point of the shell, checks interactivity
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(int argc, char *argv[])
{
	size_t bufsize = 0;
	char *line = NULL;
	int i, num_tokens = 0, failcount = 1, shell_terminal, shell_interaction;

	signal(SIGINT, SIG_IGN);
	/* Check interactivity */
	shell_terminal = STDIN_FILENO;
	shell_interaction = isatty(shell_terminal);
	/* if non-interactive */
	if (shell_interaction == 0 && argc == 1)
	{
		i = getline(&line, &bufsize, stdin); /* grabs input */
		if (i < 0)
		{
			free(line); /* frees and returns on failed read */
			return (-1);
		}
		num_tokens = numcount(line); /* counts the # of tokens */
		parse(line, num_tokens, argv, failcount);
		/* sends line and numtoken to parser */
	}
	/* if interactive */
	while (shell_interaction)
	{
		/* Shell prompt */
		write(1, "($) ", 4);
		num_tokens = 0; /* resets token count to 0 */
		i = getline(&line, &bufsize, stdin); /* grabs input */
		if (i < 0)
		{
			free(line);
			write(1, "\n", 1);
			/* frees, skips line, and repeats for failed input or CTRL - D */
			break;
		}
		num_tokens = numcount(line); /* counts tokens */
		failcount += parse(line, num_tokens, argv, failcount);
		/* sends line and numtoken to parser - tracks fails*/
		line = NULL; /* resets line to null */}
	return (0);
}
