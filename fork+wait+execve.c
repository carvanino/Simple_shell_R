#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork(),wait(),execve()
 *
 * Return: Always 0
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int status;
	int proc;
	int i = 0;
	pid_t my_pid;
	pid_t child_pid = 1;

	printf("Begining of the process\n");
	my_pid= getpid();
	printf("This is the parent process with ID: %u\n", my_pid);
	while (i < 5 && child_pid != 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		printf("Still in parent, see my ID: %u do I have child process yet? ID: %u\n", my_pid, child_pid);
		wait(&status);
		if (child_pid == 0)
		{
			printf("Now, we have a child process with ID: %u and parent ID: %u\n", child_pid, my_pid);
			proc = execve(argv[0], argv, NULL);
			if (proc == -1)
			{
				perror("Error:");
				return (1);
			}
			printf("Wait for the parent process before the child processes\n");
		}
		else 
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
