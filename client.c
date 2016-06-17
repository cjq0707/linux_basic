#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#define LEN 1024000
int main()
{
	int sfd;	
	sfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert(sfd > 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(3131);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	while(connect(sfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0);
	/*char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};
	while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		write(sfd, sendbuf, strlen(sendbuf));
	}*/
	char *buf = malloc(LEN);
	int ret;
	while(1)
	{
		ret = send(sfd, buf, LEN, 0);
		printf("sending data, ret %d\n", ret);
		sleep(2);
	}
	return 0;
}
