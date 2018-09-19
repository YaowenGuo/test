#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include "RIP.h"
#define MAXLINE 800

int main(int argc, char *argv[])
{
  struct sockaddr_in pin;
  int sock_fd;
  char buf[MAXLINE] = "\0";
  char str[MAXLINE];
  int n;
  char IP_STR[20];
  int serv_port = 0;

  signal(SIGPIPE,SIG_IGN);

  //bzero(&pin, sizeof(pin));
  pin.sin_family = AF_INET;
  printf("Please input Ip address:");
  scanf("%s",IP_STR);
  printf("Please input Point:");
  scanf("%d",&serv_port);
  inet_pton(AF_INET, IP_STR, &pin.sin_addr);
  pin.sin_port = htons(serv_port);
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  char hostName[4] = "R4";
  int ripTableLen = 0;
  RipPoint rp = initCli(&ripTableLen);
  printf("This Routing is:%s\n",hostName);
  printf("This Routing's table is:\n");
  showRipTable(rp,ripTableLen);

  n=connect(sock_fd, (void *)&pin, sizeof(pin));
  if (-1 == n)
  {
     perror("call connect");
     exit(1);
  }
  fgets(str,MAXLINE, stdin);
  Rip addOne = {"\0",0,"\0"};
  while(1)
  {
    memcpy(buf,hostName,4);
    copyRip((RipPoint)&buf[4],rp,ripTableLen);
    write(sock_fd, buf, sizeof(Rip)*ripTableLen +4 );
    n=read(sock_fd, buf, MAXLINE);
    if (0 == n)
      printf("the othere side has been closed.\n");
    else if (n >=4)
    {
      int getRipLen = (n-4)/sizeof(Rip);
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
    printf("Plese input a rip item you want add!\n");
    if(3 == scanf("%s%d%s",addOne.destintion,(int *)&(addOne.distance),addOne.next))
    {
      ripTableLen = merge(rp, ripTableLen,&addOne,1);
      printf("After add one item:\n");
      showRipTable(rp,ripTableLen);
    }else
    {
      printf("input error\n");
    }  
  }
  close(sock_fd);
  return 0;
}
