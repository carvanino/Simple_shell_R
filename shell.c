#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * main - simple_shell
 *
 * Return: Always 0
 */

int main (void)
{
	size_t len = 128;
	int ret;
       	int i = 0, n_tok = 0;
	int prompt = 1;
	char *string, *str_cpy, *token, *delim = " \n";
	char **argv;

	while (prompt > 0)
	{
		printf("#cisfun$ ");
		prompt = getline(&string, &len, stdin);
		if (prompt == -1)
		{
			return (1);
		}
		
		ret = strlen(string);
		str_cpy = malloc(sizeof(char) * ret);
		strcpy(str_cpy, string);

		token = strtok(string, delim);
		while(token != NULL)
		{
			n_tok++;
			token = strtok(NULL, delim);
		}
		n_tok++;

		argv = malloc(sizeof(char *) * n_tok);
		token = strtok(str_cpy, delim);
		while(token != NULL)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			printf("%s\n", argv[i]);
			i++;
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		free(string);
		free(str_cpy);

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error ->");
			return (1);
		}
	}


}
