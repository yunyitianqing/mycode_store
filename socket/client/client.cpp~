#include"client.h"

int main()
{
	int sock_cli = socket(AF_INET,SOCK_STREAM, 0);
	
	struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(80);
    
    char ip[20];
    
    printf("please input server's ip:\n");
    //scanf("%s",ip);
    
    server_sockaddr.sin_addr.s_addr = inet_addr("119.75.217.56");
   
    if (connect(sock_cli, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) < 0)
    {
    	perror("connect error");
    	exit(-1);
    }
    
    char* sendbuf=new char[1000];
    char* recvbuf=new char[1000];
    int i=0;
    memset(sendbuf, 0, sizeof(sendbuf));
    
    
    	
    	sprintf(sendbuf,"HEAD / HTTP/1.1\r\n"
				"Host: 119.75.217.56:80\r\n"
				"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
				"Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\n"
				"Accept-Encoding: gzip, deflate\r\n"
				"Connection: keep-alive\r\n");
    	
    	//if(sendbuf[0]==0)
    	//	break;
    	
    	send(sock_cli,sendbuf,300,0);
    	
    	
    	printf("\n%s\n",sendbuf);
    	
    	while(1)
    	{
    	memset(recvbuf, 0, sizeof(recvbuf));
        recv(sock_cli, recvbuf,1000,0); ///接收
       
       		for(int i=0;i<1000;i++)
       		{
       			if(recvbuf[i]==0)
       				goto f1;
       			printf("%c",recvbuf[i]);
       		}
        
		
		}
f1:		
        
        
        
    
	close(sock_cli);
	return 0;
}
