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

#include <pthread.h>


void* thread(void*param)
{
	int conn=((int *)param)[0];
	char*recvbuf=new char[2000];
	char*sendbuf=new char[2000];
	recv(conn, recvbuf,2000,0);
        
    printf("%s",recvbuf);
    
    for(int i=5;recv[i]!=' ';i++)
    {
    	
    }

       	
    int sock_out = socket(AF_INET,SOCK_STREAM, 0);
	
	struct sockaddr_in out_sockaddr;
    out_sockaddr.sin_family = AF_INET;
    out_sockaddr.sin_port = htons(80);
    
    
	
	
	delete recvbuf;
}



int main()
{
	int server_sockfd = socket(AF_INET,SOCK_STREAM, 0);
	
	pthread_t tid_out;
	
	struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(8888);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    
    
    
    
    
    if(bind(server_sockfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
    {
    	perror("bind error");
    	exit(-1);
    }
    
    if(listen(server_sockfd,20) == -1)
    {
    	perror("listen error");
    	exit(-2);
    }
    
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    
   

   while(1)
   {
   	 	int conn = accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
   	 	if(conn<0)
   	 	{
   	 		perror("connect error");
   	 		break;
   	 	}
   	 	pthread_create(&tid_out, 
					NULL, 
					thread,
					&conn);
    	
   }
    

    
    
        
       	
       	
       
    
    close(conn);
    close(server_sockfd);
	return 0;
}


