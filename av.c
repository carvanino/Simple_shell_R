#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints all argument passed
 *
 * @ac: number of items in av
 * @av: null terminated string
 *
 * Return: 0
 */

int main(int ac __attribute__((unused)), char **av)
{
	int i;

	for (i = 0; av[i]; i++)
	{
		printf("%s ", av[i]);
	}
	printf("\n");
	return (0);
}
