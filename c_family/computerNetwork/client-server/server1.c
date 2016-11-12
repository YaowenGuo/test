
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#define True 1
#define False 0
#define MAXLINE 200
#define LISTENQ 2
#define ADDR_IP "192.168.198.1"
#define SERV_PORT 8001
void str_echo(int sockfd);
int main(int argc, char **argv)
{
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	signal(SIGPIPE, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof( servaddr ));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(SERV_PORT);
	
	bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	printf("My host ip is:%s\n",ADDR_IP);
	printf("This server use point:%d\n",SERV_PORT);
	listen(listenfd,LISTENQ);
	while(True)
	{
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
		if( 0 == (childpid = fork()))
		{
			close(listenfd);
			str_echo(connfd);
			exit(0);
		}
	}
}

void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];
again:
	while( (n = read(sockfd, buf, MAXLINE)) > 0)
	{
		printf("get:%s",buf);
		scanf("%s",buf);
		write(sockfd, buf, n);
	}
	if( n < 0 && errno == EINTR)
		goto again;
	else if(n < 0)
		printf("str_echo:read error");
}



                printf("you ip is %s at port %d:%s\n",
                     inet_ntop(AF_INET, &pin.sin_addr,str,sizeof(str)),
                     ntohs(pin.sin_port),buf);