#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;
typedef struct en_v {
	char *data;
	struct en_v *next;
} en_vlist;

char *_getenv(const char *name)
{
	int i = 0;

	char *token, *dir;
	en_vlist *head = NULL, *newnode, *transv = NULL;

	while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "");
			dir = strtok(token, ":");
			while (dir != NULL)
			{
				//dir = strtok(NULL, ":");
				newnode = malloc(sizeof(en_vlist));
				newnode->data = dir;
				newnode->next = NULL;
				if (head == NULL)
				{
					head = transv = newnode;
				}
				else
				{
					transv->next = newnode;
					transv = newnode;
				}
				dir = strtok(NULL, ":");
			}
			transv = head;
			while (transv != NULL)
			{
				printf("%s\n", transv->data);
				transv = transv->next;
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
