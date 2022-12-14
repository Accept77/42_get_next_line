#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define BUFFER_SIZE 4

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *buf = get_next_line(fd);
	printf("%s",buf);
	buf = get_next_line(fd);
	printf("%s",buf);
	close(fd);
}
