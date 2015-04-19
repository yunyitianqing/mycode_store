#include"client.h"
#include<stdlib.h>

HC_UDP::HC_UDP()
{
	socket_send_fd = socket(AF_INET,SOCK_DGRAM, 0);
	socket_recv_fd = socket(AF_INET,SOCK_DGRAM, 0);
	
	send_addr.sin_family = AF_INET;
    send_addr.sin_port = htons(8000);
	send_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(INADDR_ANY);
    recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	recv_len=sizeof(recv_addr); 
		
}

int HC_UDP::UDP_init(char*ip,unsigned int port)
{
	send_addr.sin_port = htons(port);
	send_addr.sin_addr.s_addr = inet_addr(ip);
	//recv_addr.sin_port = htons(port);
	
	int res=bind(socket_recv_fd,(struct sockaddr *)&recv_addr,sizeof(recv_addr));
	
	struct timeval tv_out;
    tv_out.tv_sec = 10;//等待10秒
    tv_out.tv_usec = 0;
	setsockopt(socket_recv_fd,SOL_SOCKET,SO_RCVTIMEO,&tv_out, sizeof(tv_out));
	
	return res;
}

void HC_UDP::send(char*s,int len)
{
	sendto(socket_send_fd,s,len,0,(struct sockaddr*)&send_addr,sizeof(send_addr));
}

void HC_UDP::recv(char*s,int len)
{
	memset(s,0,len);
f1:	
	if(recvfrom(socket_recv_fd,s,len,0,0,0)<0)
	{
		fprintf(stderr,"recv timeout\n");
		//goto f1;
	}
}

/*
int main()
{
	int sock_cli = socket(AF_INET,SOCK_DGRAM, 0);

	 
	struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(8000);

    server_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("\n11111\n");

    printf("\n22222\n");
 
    
    char* sendbuf=new char[1000];
    char* recvbuf=new char[1000];
    int i=0;
    memset(sendbuf, 0, sizeof(sendbuf));
    
    
    	
    	sprintf(sendbuf,"POST / HTTP/1.1\r\n\
				Host: 119.147.10.11:8000\r\n\
\r\n\
VER=1.1&\
CMD=Login&\
SEQ=%d&\
UIN=191397810&\
PS=d40ab32ecae21f47dcaa9df25d7dd940&\
M5=1&\
LC=9326B87B234E7235\r\n",rand()%8000+1000);
    	
		
    	sendto(sock_cli,sendbuf,300,0,(struct sockaddr*)&server_sockaddr,sizeof(server_sockaddr));
    	//send(sock_cli,sendbuf,300,0);
    	
    	printf("\n%s\n",sendbuf);
    	
    	while(1)
    	{
    	memset(recvbuf, 0, sizeof(recvbuf));
f1:
        //recv(sock_cli, recvbuf,1000,0); ///接收
//       	recvfrom(sock_server,recvbuf,1000,0,(struct sockaddr *)&recv_sockaddr,&recv_len);
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
		
        
        
        
    
	close(sock_cli);
	return 0;
}
*/
