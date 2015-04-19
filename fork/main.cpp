#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	int i=0;
	i++;
	int *a=new int[3];
	a[0]=0;
	
	printf("before,fork\n");
	
	pid=fork();
	
	if(pid==0)
	{
		i+=10;
		a[0]+=10;
		printf("child process %d %d %d %d\n",i,&i,a[0],a);
		execl("/bin/ps","ps",0);
	}
	else
	{
		i+=100;
		a[0]+=100;
		printf("father process %d %d %d %d\n",i,&i,a[0],a);	
	}
	pid=fork();
	if(pid==0)
	{
		i+=10;
		a[0]+=10;
		printf("child process %d %d %d %d\n",i,&i,a[0],a);
		execl("/bin/ps","ps",0);
	}
	else
	{
		i+=100;
		a[0]+=100;
		printf("father process %d %d %d %d\n",i,&i,a[0],a);	
	}
	sleep(3);
	
	return 0;
}
