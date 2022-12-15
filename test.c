#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *buf;
	int i = 0;

//	while (i < 256)
//	{
//		fd = open("test.txt", O_RDONLY);
//		printf("fd is %d\n", fd);
//		i++;
//	}
	while (i < 6)
	{
		buf = get_next_line(fd);
		printf("%s\n",buf);
		i++;
	}
	close(fd);
}
