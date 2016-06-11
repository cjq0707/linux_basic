#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>

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
	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};
	while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		write(sfd, sendbuf, strlen(sendbuf));
	}
	return 0;
}
