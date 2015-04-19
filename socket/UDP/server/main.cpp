#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>


int main()
{
	int sock_server = socket(AF_INET,SOCK_DGRAM, 0);
	socklen_t recv_len;
    struct sockaddr_in recv_sockaddr;
    recv_sockaddr.sin_family = AF_INET;
    recv_sockaddr.sin_port = htons(8000);
    recv_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    recv_len=sizeof(recv_sockaddr); 
    printf("\n22222\n");
    bind(sock_server,(struct sockaddr *)&recv_sockaddr,sizeof(recv_sockaddr));
    
    char recvbuf[1000];
    
    while(1)
    	{
    	memset(recvbuf, 0, sizeof(recvbuf));
f1:
        //recv(sock_cli, recvbuf,1000,0); ///接收
       	recvfrom(sock_server,recvbuf,1000,0,0,0);
       		for(int i=0;i<1000;i++)
       		{
       			if(recvbuf[i]==0)
       			{
       			printf("recv=0\n");
       			sleep(1);
       				continue;
       			}
       			printf("%c",recvbuf[i]);
       		}
        
		
		}
     
	return 0;
}
