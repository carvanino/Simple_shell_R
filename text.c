#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


int main()
{
	char** argv;
	char* strr = "Well, lets take our time";
	char* delim = " \n";
	char* str_cpy, *str;
	int i = 0;
	int ret, num = 0;
	char *token;

	str = malloc(sizeof(char) * 40);
	strcpy(str, strr);
	ret = strlen(str);
	str_cpy = malloc(sizeof(char) * 120);
	strcpy(str_cpy, str);


	argv = malloc(sizeof(char *) * 20);
	token = strtok(str_cpy, delim);
	while (token != NULL)
	{
		printf("Here\n");
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		printf("%s\n", argv[i]);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (0);
}
