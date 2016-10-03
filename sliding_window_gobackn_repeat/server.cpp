#include “stdio.h “
#include “sys/types.h “
#include “sys/socket.h “
#include “netinet/in.h “
#include “arpa/inet.h “
#include “string.h “
#include “stdlib.h “
#include “arpa/inet.h “
#include “unistd.h “
#define SIZE 4
main()
{
int id,lfd,i,j,status,n;
char str[20],frame[20],temp[20],ack[20];
socklen_t len;
struct sockaddr_in server,client;
id=socket(AF_INET,SOCK_STREAM,0);
if(id < sin_family="AF_INET;" sin_port="htons(8565);" s_addr="htonl(INADDR_ANY);" len="sizeof(&client);" lfd="accept(id,(struct" i="0;" n="strlen(frame);" j="0;j" status="="-1)" j="0;;)" 4="="0)" n="strlen(frame);" j="0;j" id="socket(AF_INET,SOCK_STREAM,0))="="-1)" sin_family="AF_INET;" sin_port="htons(8565);" c="connect(id,(struct"> y 0-- > n)",str);
scanf("%d",&choice);
if(!choice)
write(id,"-1",sizeof("-1"));
else
{
printf("Enter The Sequence Of Frame Where Error Has Occured: ");
scanf("%s",err);
write(id,err,sizeof(err));
read(id,str,20);
printf("\n\n Received The Retransmitted Frames %s\n\n",str);
}
}
close(id);
return 0;
}
