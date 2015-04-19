  #include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*fp;
	
	char re[100];
	char* send=new char [50];
	
	while(1)
	{
	
	gets(send);
	
	
	
	if((fp=popen(send,"r"))==0)
	{
		perror("tty");
		return -1;
	}
	
	
	
	
	
	fscanf(fp,"%s",re);
	
	printf("%s\n",re);
	
	
	pclose(fp);
	
	}
	
	
	return 0;
}
