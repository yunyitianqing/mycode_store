#include"communication_server.h"
//class myServer
myServer::myServer()
{
	context=zmq_ctx_new();
	socket=zmq_socket(context,ZMQ_REP);
	for(int i=0;i<SOCKET_NUM;i++)
	{
		mySocket[i]=NULL;
	}
}

//class Socket
Socket::mySocket(void*)
{
	socket=zmq_socket(context,ZMQ_REP);
	
}
