#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

//void	check_leak(void)
//{
//	system("leaks --list -- a.out");
//}


int main()
{
	int fd = open("giant_line_nl.txt", O_RDONLY);
	char *buf;
	int i = 0;

	while (i < 2)
	{
		buf = get_next_line(fd);
		printf("%s",buf);
		free(buf);
		buf = NULL;
		i++;
	}
	close(fd);
//	atexit(check_leak);
}
