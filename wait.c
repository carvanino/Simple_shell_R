#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - wait(), suspends program execution until a child process
 * is executed first and terminated
 *
 * Return: Always 0
 */

int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me,  wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh its all better now\n");
	}
	return (0);
}
