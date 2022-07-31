#include <stdlib.h>
#include <stdio.h>

char  *get_line(char *s, size_t maxchar, FILE *f)
{
	size_t i = 0;

	if (maxchar)
	{
		int c;
		while ( i < maxchar - 1 && ( c = fgetc( f ) ) != EOF && c != '\n' )
		{
			s[i++] = c;
		}
	}
	s[i] = '\0';

	return s;
}

#define MAX_CHAR 100

int main(void)
{
	char s[MAX_CHAR];

	printf( "%s\n", get_line(s, 12, stdin) );
	printf( "%s\n", get_line(s, 41,  stdin) );
}
