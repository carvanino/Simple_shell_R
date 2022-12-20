#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * main - which "Filename"
 * 
 * @ac: argument count
 * @av: argument vector
 *
 * Return
 */

int main(int ac,  char **av)
{
	char *env_var;
	char *token, *tokdup;
	char *str_cpy;
	char **tokens, **str_cat;
	struct stat st;
	int len = 0, j, k, a, n_toks = 0;
	unsigned int i = 0;

	if (ac > 0)
	{
		if (av[1] != "/")
		{	
			printf("tokens[i]\n");
			env_var = getenv("PATH");
			/* Have a copy to PATH */
			str_cpy = malloc(sizeof(char) * strlen(env_var));
			strcpy(str_cpy, env_var);

			/* Get the numbers of tokens */
			token = strtok(env_var, ":");
			while (token != NULL)
			{
				n_toks++;
				token = strtok(NULL, ":");
			}
			n_toks++;
			printf("%d\n", n_toks);

			/* Create an array to store all token */
			tokens = malloc(sizeof(char *) * n_toks);
			token = strtok(str_cpy, ":");
			while (token != NULL)
			{
				tokens[i] = malloc(sizeof(char) * strlen(token));
				strcpy(tokens[i], token);
				printf("%s\n", tokens[i]);
				i++;
				token = strtok(NULL, ":");
			}
			tokens[i] = NULL;
			printf("tokens[i]\n");

			/* Concatente token[i] with argument passed */
			a = 0;
			while (tokens[a] != NULL)
			{
				printf("tokens[i]\n");
				tokdup = malloc(sizeof(char) * strlen(tokens[a]));
				printf("tokens[i]\n");
				strcpy(tokdup, tokens[a]);
				printf("%s\n", tokdup);
				printf("tokens[i]\n");
				for(len = 0; tokdup[len]; len++)
				{
				}
				printf("Here\n");
				printf("%d\n", len);
				for (k = 0; av[1][k]; k++, len++)
				{
					tokdup[len] = av[1][k];
				}
				printf("tokens[i]\n");

				/* Was trying to wriet stst outside of the while loop */
				str_cat = malloc(sizeof(char *) * n_toks);
				str_cat[a] = malloc(sizeof(char) * strlen(tokdup));
				strcpy(str_cat[a], tokdup);
				printf("%s\n", str_cat[a]);

				/* Checks if concatenated string is found in any of path directory */
				if (stat(tokdup, &st) == 0)
				{
					printf("Here last\n");
					//strcpy(av[j], tokdup);
					printf("%s\n", tokdup);
				}
				a++;
			}
		}

		else
			printf("Usage: %s filename\n", av[0]);
	}
	return (0);
}
