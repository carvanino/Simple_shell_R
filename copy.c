#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t my_pid;
	pid_t child_pid = 1;
	int status;
	int i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	my_pid = getpid();
	while (i <= 4 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("Error:");
			return (1);
		}
		wait(&status);
		i++;
	}
	if (child_pid == 0)
	{
		printf("_____________________________\n\n");
		printf("CHILD ID: %u\n\nPARENT ID: %u\n\n", my_pid, child_pid);
		printf("_____________________________\n\n");
	}
	else
	{
		printf(" %u I AM THE FATHER AND MY ID IS %u\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}

