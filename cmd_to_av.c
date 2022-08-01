#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - getline(), prints "$ " and wait for the user to enter a command
 * and print on the next line
 *
 * Return: 0
 */

int main()
{
	size_t len = 1024;; /* n */
	char *string; /* lineptr */
	int ret;
	char *token;

	printf("$ ");
	string = malloc(1024);
	ret = getline(&string, &len, stdin);
	if (ret == -1)
	{
		return (1);
	}
	else
	{
		printf("get line string: %s\n", string);

		token = strtok(string, " ");
		while(token != NULL)
		{
			printf("strtok string: %s\n", token);

			token = strtok(NULL, " ");
		}
	}
	free(string);
	return (0);
}

