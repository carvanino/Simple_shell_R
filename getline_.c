#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * getline - reads a line from strean (stdin)
 *
 * @args: array of string that stores the text user input to stream
 * @n: size of the text
 * @stream: where text is displayed
 *
 * Return: The number of character read including the delimiter
 * does not retiurn the NULL character.
 * Otherwise: -1 on fail
 */

size_t getline_(char **args, size_t n, FILE *stream)
{
	
