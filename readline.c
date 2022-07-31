#include <stdio.h>
#include <stdlib.h>

/**
 * main - getline()
 *
 * Return: 0
 */

int main()
{
	size_t len = 1024;; /* n */
	char *string; /* lineptr */
	int ret;

	printf("$ ");
	string = malloc(1024);
	ret = getline(&string, &len, stdin);
	if (ret == -1)
	{
		return (1);
	}
	else
	{
		printf("%s", string);
	}
	free(string);
	return (0);
}

