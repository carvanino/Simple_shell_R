#include "shell.h"

int main(void)
{
	size_t len;
	char *prompt_char = "\n$ ";
	int w;
	pid_t pid;
	int prompt;
	char *string, *str_cpy, *token, *delim = " \n";
	char **argv;

	while (prompt > 0)
	{
		w = write(STDIN_FILENO, prompt_char, 3);;
		if (w == -1)
		{
			return (1);
		}
		

		str_cpy = malloc(sizeof(char) * strlen(string));
		strcpy(str_cpy, string);
		n_token = n_toks(string, delim);

		argv = malloc(sizeof(char *) * n_token);

