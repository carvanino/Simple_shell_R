#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


char **_strtok(char *str, char *delim)
{
	char** argv;
	int i = 0;
	char *token;
	char *str_cpy;
	int ret, n_toks = 0;


	str_cpy = malloc(sizeof(char) * strlen(str));
	if (str_cpy == NULL)
	{
		return (NULL);
	}
	strcpy(str_cpy, str);

	token = strtok(str, delim);
	while (token != NULL)
	{
		n_toks++;
		token = strtok(NULL, delim);
	}
	n_toks++;

	argv = malloc(sizeof(char *) * n_toks);
	token = strtok(str_cpy, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		argv[i] = token;
		printf("%s\n", argv[i]);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	//free(str_cpy);
	return (argv);
}

int main()
{
	char buffer[] = "The wicked shall go unpunished";
	char* delim = " ";
	char **s;
	int i = 0;

	s =_strtok(buffer, delim);
	if (s != NULL)
	{
		printf("%p", s);
	}
	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}

	return (0);
}

