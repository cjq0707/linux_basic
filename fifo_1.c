#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	char buf[512];
	int fd;
	unlink("ts_fifo");
	mkfifo("ts_fifo", 0777);
	if(fork() > 0)
	{
		char *s = "process data";
		fd = open("ts_fifo", O_WRONLY);
		write(fd, s, strlen(s));
	}
	else
	{
		fd = open("ts_fifo", O_RDONLY);
		read(fd, buf, sizeof(buf));
		printf("read from fifo %s\n", buf);
	}
	return 0;
}
