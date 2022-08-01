#include <stdio.h>
#include <unistd.h>

/**
 * main - fork()  creates a separate duplicate of a process
 * Return: 0
 */

int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1) /* if fork fails */
	{
		perror("Error:");
		return (1);
	}
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	if (child_pid == 0) /* if true, implies that fork has begun, there is a child process and 0 is the first child. */
	{
		printf("(%u) Nooooooooo!\n", my_pid);
	}
	else /* Indicates that we are still in the parent process */
	{
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	}
	return (0);
}
