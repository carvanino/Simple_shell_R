#include <unistd.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	char *token, *dir;

	while (environ[i] != NULL)
	{
		//printf("Here1\n");
		token = strtok(environ[i], "=");
		//printf("%s\n", token);
		if (strcmp(token, name) == 0)
		{
			//printf("Here2\n");
			token = strtok(NULL, "");
			printf("%s\n", token);
			dir = strtok(token, ":");
			while (dir != NULL)
			{
				printf("%s\n", dir);
				dir = strtok(NULL, ":");
			}
		}

		i++;
	}
	return (0);
}

int main()
{
	char *env;

	env = _getenv("PATH");
	return (0);
}
