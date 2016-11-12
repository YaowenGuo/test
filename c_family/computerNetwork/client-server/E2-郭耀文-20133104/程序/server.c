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
#include "RIP.h"
#define MAXLINE 800
int port = 8000;
#define ADDR_IP "192.168.198.1"
int main(void)
{
    struct sockaddr_in sin;
    struct sockaddr_in pin;
    int listen_fd;
    int conn_fd;
    int sock_fd;
    int nready;
    int maxi;
    int max;
    int client[FD_SETSIZE];
    int address_size = sizeof(pin);
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i;
    int len;
    int n;
    int ret;
    printf("My host ip is:%s\n",ADDR_IP);
    printf("This server use point:%d\n",port);
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);   
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    char hostName[4] = "R6";
    int ripTableLen = 0;
    RipPoint rp = initSer( &ripTableLen);
    printf("This Routing is:%s\n",hostName);
    printf("This Routing's table is:\n");
    showRipTable(rp,ripTableLen);
    

    if (-1 == listen_fd)
    {
        perror("call to socket");
        exit(1);
    }
    n = bind(listen_fd, (struct sockaddr *)&sin, sizeof(sin));
    if (-1 == n)
    {
        perror("call to bind");
        exit(1);
    }
    n = listen(listen_fd, 20);
    if (-1 == n)
    {
        perror("call to listen");
        exit(1);
    }
    printf("Accepting connections...\n");

    while(1)
    {
        conn_fd = accept(listen_fd, (struct sockaddr *)&pin, &address_size);
        n = fork();
        if (-1 == n){
            perror("call to fork");
            exit(1);
        }
        else if (0 == n)
        {
            close(listen_fd);
            Rip addOne = {"\0",0,"\0"};
            while(1)
            {
                memset(buf,'\0',MAXLINE);
readagain:
                ret = read(conn_fd,buf,MAXLINE);
                if (-1 == ret){
                    if (errno == EINTR){
                        goto readagain;
                    }else{
                        perror("call to read");
                        exit(1);
                    }
                } else if (0 == ret){
                    printf("the other side has been closed.\n");
                    break;
                }else if( ret >=4 )
                {
                    int getRipLen = (ret-4)/sizeof(Rip);
                    change((RipPoint)&buf[4], getRipLen, buf);
                    RipPoint temp = (RipPoint)&buf[4];
                    printf("Recive table changed:\n");
                    showRipTable(temp,getRipLen);
                    ripTableLen = merge(rp, ripTableLen, (RipPoint)&buf[4],getRipLen);
                    printf("After combination tip table is:\n");
                    showRipTable(rp,ripTableLen);
                }else
                {
                    printf("Recive data error!\n");
                }
writeagain:
                memcpy(buf,hostName,4);
                copyRip((RipPoint)&buf[4],rp,ripTableLen);
                ret = write(conn_fd, buf, sizeof(Rip)*ripTableLen+4);
                if (-1 == ret){
                    if (errno == EINTR){
                        goto writeagain;
                    } else {
                        perror("call to write!");
                        break;
                    }
                }
                printf("Please input you add:\n");
                if(3 == scanf("%s%d%s",addOne.destintion,(int *)&(addOne.distance),addOne.next))
                {
                  ripTableLen = merge(rp, ripTableLen,&addOne,1);
                  printf("After add one item:\n");
                  showRipTable(rp,ripTableLen);
                }else
                {
                  printf("input error\n");
                }
            }// end while

            ret = close(conn_fd);
            if (-1 == ret){
                perror("call close");
                return -1;
            }
            exit(0);
        }
    }
    return 0;
}