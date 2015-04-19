#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<unistd.h>
#include"test.h"

int main()
{
	void* pdl=0;
	void* pdl2=0;
	A* p=0;
	
	printf("1\n");
	pdl=dlopen("./libtest.so",RTLD_LAZY|RTLD_GLOBAL);
	printf("2\n");
	if(dlerror())
	{
		printf("error1:%s\n",dlerror());
		exit(1);
	}
	p=(A*)dlsym(pdl,"a");
	
	printf("3\n");
	
	//A::getGoalA()->print();
	
	if(dlerror())
	{
		printf("error2:%s\n",dlerror());
		dlclose(pdl);
		exit(2);
	}
	p->print();
	
	
	
	pdl2=dlopen("./libtest2.so",RTLD_LAZY|RTLD_GLOBAL);
	
	void (*p1)();
	
	p1=(void(*)())dlsym(pdl2,"print");
	
	
	
	printf("2\n");
	if(dlerror())
	{
		printf("error1:%s\n",dlerror());
		exit(1);
	}
	p1();
	printf("3\n");
	return 0;
}
