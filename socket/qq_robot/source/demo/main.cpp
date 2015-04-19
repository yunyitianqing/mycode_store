#include"../connect/client.h"

int main()
{	

	HC_UDP *udp=new HC_UDP;
	udp->UDP_init("111.161.88.29",8000);
	char send[500]={0};
	char recv[500]={0};
	sprintf(send,"POST / HTTP/1.0\r\n"
				"Host: 111.161.88.29\r\n"
				"Content-Length: 99\r\n"
				"connection: close\r\n"
				//"\r\n"
"VER=1.0&CMD=Login&SEQ=%d&UIN=191397810&PS=d40ab32ecae21f47dcaa9df25d7dd940&M5=1&LC=9326B87B234E7235",rand()%8000+1000);

//	sprintf(send,"HEAD / HTTP/1.1\r\n"
//				"Host: 111.161.88.29:8000\r\n"
//				"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
//				"Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\n"
//				"Accept-Encoding: gzip, deflate\r\n"
//				"Connection: keep-alive\r\n");
				
	printf("1\n");
	udp->send(send,500);
	printf("2\n");
	udp->recv(recv,500);
	printf("3\n");	
	printf("%s\n",recv);
	return 0;
}
