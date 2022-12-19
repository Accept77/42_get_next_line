#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("read_error.txt", O_RDONLY);
	char *buf;
	int i = 0;

	while (i < 6)
	{
		buf = get_next_line(fd);
		printf("%s\n",buf);
		i++;
	}
	close(fd);
}
