#ifndef _COMMUNIATION_SERVER_
#define _COMMUNIATION_SERVER_
#include<zmq.h>
#define SOCKET_NUM 10
class Socket
{
public:	
	Socket(void*);
	~Socket();
	
}




class myServer
{
public:
	myServer();
	~myServer();
private:
	void* context;
	void* socket;
	Socket* mySocket[SOCKET_NUM];
}




#endif //_COMMUNIATION_SERVER_
