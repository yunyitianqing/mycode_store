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

class HC_UDP
{
public:
	HC_UDP();
	int UDP_init(char*ip="119.147.10.11",unsigned int port=8000);
	void send(char*,int);
	void recv(char*,int);
protected:
	int socket_send_fd;
	int socket_recv_fd;
	struct sockaddr_in send_addr;
	struct sockaddr_in recv_addr;
	socklen_t recv_len;
};
