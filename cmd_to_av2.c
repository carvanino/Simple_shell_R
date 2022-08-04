#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - getline(), prints "$ " and wait for the user to enter a command
 * and print on the next line
 *
 * Return: 0
 */

//char **environ;

int main()
{
	size_t len = 1024; /* n */
	char *string, *str_cpy; /* lineptr */
	size_t ret;
	char *token;
	char *delim = " \n";
	char **argv;
	int tok = 0, i = 0;

	printf("$ ");
	ret = getline(&string, &len, stdin);
	if (ret == -1)
	{
		return (1);
	}
	printf("get line string: %s\n", string);

	str_cpy = malloc(sizeof(char) * ret);
	strcpy(str_cpy, string);

	token = strtok(string, delim);
	while(token != NULL)
	{
		tok++;
		token = strtok(NULL, delim);
	}
	tok++;

	argv = malloc(sizeof(char *) * tok);
	token = strtok(str_cpy, delim);
	while(token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		printf("strtok string: %s\n", token);
		i++;

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	/* Fix stack smashing error */
	return (0);

}

