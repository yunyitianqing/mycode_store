#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_usr1(int signo)
{
	
	if(signo==SIGUSR1)
		printf("1111111\n");
	if(signo==SIGUSR2)
		printf("222222222\n");
	//flag=1;
}



int main()
{
	if(signal(SIGUSR1,sig_usr1)==SIG_ERR)
		fprintf(stderr,"can't catch SIGUSR1\n");
	if(signal(SIGUSR2,sig_usr1)==SIG_ERR)
		fprintf(stderr,"can't catch SIGUSR2\n");
	if(signal(SIGCONT,sig_usr1)==SIG_ERR)
		fprintf(stderr,"can't catch SIGCONT\n");
	while(1)
		pause();
	
	return 0;
}
