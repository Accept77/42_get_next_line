#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	check_leak(void)
{
	system("leaks --list -- a.out");
}


int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *buf;

	buf = get_next_line(fd);
	printf("%s",buf);
	free(buf);
	buf = NULL;
	close(fd);
	atexit(check_leak);
}
