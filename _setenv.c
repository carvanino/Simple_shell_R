#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;
typedef struct en_v {
	const char *data;
	struct en_v *next;
} en_vlist;

int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;
	int ret;

	char *token, *dir;
	en_vlist *head = NULL, *newnode, *transv = NULL, *endnode;
	char **str_cpy;

	while (environ[i] != NULL)
	{
		/* creates a linked list to store all environ var */
		newnode = malloc(sizeof(en_vlist));
		newnode->data = environ[i];
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
		i++;
	}
	i = 0;
	strcpy = malloc(sizeof(char *) * )

	while (environ[i] != NULL)
	{
		/* Checks if name is a present env var */
		token = strtok(environ[i], "=");
		if (token != NULL)
		{
			ret = strcmp(token, name);
			if (ret == 0 && overwrite == 1)
			{
				strcat(name, "=");
				strcat(name, value);
				//replace environ[i] witj name
				return (1);
			}
		}
		i++;
	}
	/* After we have checked through env var array and name is not
	 * found add a new node at the end of thr list */
	if (ret <= 0 && overwrite == 1)
	{
		/* Add a new node to linked list */
		endnode = malloc(sizeof(en_vlist));
		if (endnode == NULL)
		{
			return (0);
		}
		endnode->data = name;
		endnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			transv = head;
			while (transv->next != NULL)
			{
				transv = transv->next;
			}
			transv->next = endnode;
		}

		return (0);
	}
	else 
	{
		return (-1);
	}
}
