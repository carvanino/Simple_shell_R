#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * n_toks - get the number of tokens from a string
 *
 * @str: string to be tokenised or parsed
 * @delim: delimiter
 *
 * Return: Number of tokens
 */

int n_toks(char *str, char *delim)
{
	int i = 0;
	int num = 0;
	char *token;

	token = strtok(str, delim);
	while (token != NULL)
	{
		num++;
		token = strtok(NULL, delim);
	}
	num++;

	return (num);
}
