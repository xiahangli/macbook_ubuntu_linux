#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc,char *argv[])
{
int sockfd;
char buffer[1024];
struct sockaddr_in server_addr;
struct hostent *host;
int portnumber,nbytes;

if(argc != 3)
{
fprintf(stderr,"Usage:%s hostname portnumber\a\n",argv[0]);
exit(1);
}

host=gethostbyname(argv[1]);
if(host == NULL)
//if((host=gethostbyname(argv[1]))==NULL)
{
fprintf(stderr,"Gethostbyname error\n");
exit(1);
}

if(portnumber=atoi(argv[2])<0)
{
fprintf(stderr,"Usage:%s hostname portnumber\a\n",argv[0]);
exit(1);
}

if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
fprintf(stderr,"Socket Error:%s\a\n",strerror(errno));
exit(1);
}

bzero(&server_addr,sizeof(struct sockaddr));
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(portnumber);
server_addr.sin_addr = *((struct in_addr*)host->h_addr);

if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
{
fprintf(stderr,"Connect Error:%s\a\n",strerror(errno));
exit(1);
}

if((nbytes=read(sockfd,buffer,1024))==-1)
{
fprintf(stderr,"Read Error:%s\n",strerror(errno));
exit(1);
}

buffer[nbytes]='\0';
printf("I have received:%s\n",buffer);

close(sockfd);
exit(0);
}