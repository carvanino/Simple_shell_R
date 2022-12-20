#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i = 0;

	while (env != NULL && environ != NULL)
	{
		printf("Address of env is %p and environ is %p\n", &env, &environ);
		break;
	}
	return (0);
}	
