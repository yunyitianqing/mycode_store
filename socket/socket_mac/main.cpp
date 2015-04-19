#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#include <pthread.h>

# include <sys/socket.h>

# include <sys/ioctl.h>              /* ioctl command */

# include <netinet/if_ether.h>        /* ethhdr struct */

# include <net/if.h>                /* ifreq struct */

# include <netinet/in.h>             /* in_addr structure */

# include <netinet/ip.h>             /* iphdr struct */

# include <netinet/udp.h>            /* udphdr struct */

# include <netinet/tcp.h>


int main()
{
	int sock_fd = socket(AF_INET,SOCK_PACKET, htons(0x0003));
	char*dev="eth0";
	struct ifreq  ifr;
	strcpy(ifr.ifr_name, dev);
	int i=ioctl(sock_fd,SIOCGIFFLAGS,&ifr);
	if(i<0)
	{
		close(sock_fd);
		perror("can't get flags\n");
		exit(0);
	}
	ifr.ifr_flags|=IFF_PROMISC;
	i=ioctl(sock_fd,SIOCSIFFLAGS,&ifr);
	if(i<0)
	{
		perror("can't set promiscuous\n");
	}
	
	char recvbuf[1000];
	
	while(1)
    {
    	memset(recvbuf, -33, sizeof(recvbuf));
    	recv(sock_fd, recvbuf,1000,0); ///接收
       
		
       	for(int a=0;a<1000;a++)
       	{		
       		if(recvbuf[a]==-33)
       			break;
       		if(recvbuf[a]==0)
       			continue;
       		fprintf(stderr,"%02x ",(unsigned char)recvbuf[a]);
       		
       	}
		
	}
	
	return 0;
}
