#include<unistd.h>
#include<sys/ioctl.h>
#include<stdio.h>

int main()
{
	int fd;
	fd=dup(0);
	
	printf("%d\n",fd);
	
	sleep(100);
	
	return 0;
	
	
}
