#include<zmq.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
//#include<sys/socket.h>
//#include<ifaddrs.h>
//#include <unistd.h>


//#include <errno.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
//#include <sys/utsname.h>

int main()
{
	void* context=zmq_ctx_new();
	void* socket=zmq_socket(context,ZMQ_REP);
//	struct sockaddr_in sin;
	
	zmq_bind(socket,"tcp://*:5555");
	
//	unsigned char * p_data=new unsigned char[320*240];
	
	char temp[100];
	int recv_size;
	int sent_size;
	zmq_msg_t message;
	zmq_msg_init(&message);
	
	

	
	while(1)
	{
		
		
		//std::cout<<"hello Server1"<<std::endl;
		recv_size=zmq_msg_recv(&message,socket,0);
		//std::cout<<"hello Server2"<<std::endl;
		if(recv_size>0)
		{	
			//std::cout<<"hello Server3"<<recv_size<<std::endl;
			memcpy(temp,zmq_msg_data(&message),recv_size);
			//std::cout<<"hello Server4"<<std::endl;
			std::cout<<temp<<std::endl;
		}
		sprintf(temp,"recv is ok\n");
		memcpy(&message,temp,strlen(temp)+1);
		zmq_send(socket,&message,strlen(temp)+1,0);
		sleep(1);
	}
	
	return 0;
}

