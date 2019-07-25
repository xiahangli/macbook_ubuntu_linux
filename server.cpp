#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc,char *argv[])
{
int sockfd,new_fd;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
unsigned int sin_size,portnumber;
char hello[]="hello!are you fine?\n";

if(argc != 2)
{
fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
exit(1);
}

if((portnumber=atoi(argv[1]))<0)
{
fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
exit(1);
}

if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
fprintf(stderr,"Socket error:%s \n\a",strerror(errno));
exit(1);
}
printf("socket success\n");

bzero(&server_addr,sizeof(struct sockaddr_in));
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
server_addr.sin_port = htons(portnumber);

if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr)) == -1)
{
fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
exit(1);
}
printf("bind success\n");

if(listen(sockfd,5)==-1)
{
fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
exit(1);
}
printf("listen success\n");

while(1)
{
printf("in while\n");
sin_size = sizeof(struct sockaddr_in);
new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size);
if(new_fd == -1)
{
fprintf(stderr,"Accept error:%s\n\a",strerror(errno));
exit(1);
}
printf("accept\n");

fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));

if(write(new_fd,hello,strlen(hello))==-1)
{
fprintf(stderr,"Write Error:%s\n",strerror(errno));
exit(1);
}

close(new_fd);
}
close(sockfd);
exit(0);
}