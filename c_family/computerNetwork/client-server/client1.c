#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#define MAXLINE 200
void str_cli(FILE * fd, int sockfd);

int main(int argc,char **argv)
{
	int sockfd;
	char IP_STR[20];
	int serv_port = 8001;
	struct sockaddr_in servaddr;
	signal(SIGPIPE,SIG_IGN);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr, sizeof(servaddr) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(serv_port);
	printf("Please input Ip address:");
	scanf("%s",IP_STR);
	printf("Please input Point:");
	scanf("%d",&serv_port);
	inet_pton(AF_INET, IP_STR, &servaddr.sin_addr);
	if(0 == connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)))
	{
		printf("connect success!\n");
	}
	str_cli(stdin, sockfd);
	exit(0);
}

void str_cli(FILE * fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	printf("this\n");
	while(fgets(sendline,MAXLINE,fp) != NULL)
	{
		write(sockfd, sendline, strlen(sendline)+1);
		printf("that\n");
		if(read(sockfd,recvline,MAXLINE) == 0)
			printf("input error");
		fputs(recvline,stdout);
	}
	printf("dfasdf\n");
}