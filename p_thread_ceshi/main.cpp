#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

void cleanup1(void*);

void cleanup2(void*);

void cleanup1(void*param)
{
	printf("child1 cleanup\n");
	return ;
}

void cleanup2(void*param)
{
	printf("child2 cleanup\n");
	return ;
}

void* child1(void*param)
{
	printf("child1:start\n");
	pthread_cleanup_push(cleanup1,0);
	
	while(1)
	{
		printf("child1:i am runing\n");
		sleep(1);
	}
	
	pthread_cleanup_pop(0);
	return 0;
}

void* child2(void*param)
{
	printf("child2:start\n");
	pthread_cleanup_push(cleanup2,0);
	
	while(1)
	{
		printf("child2:i am runing\n");
		sleep(1);
	}
	pthread_cleanup_pop(0);
	return 0;
}



int main()
{
	pthread_t tid_child1;
	pthread_t tid_child2;
	
	pthread_create(&tid_child1, NULL, child1, NULL);
	pthread_create(&tid_child2, NULL, child2, NULL);
	
	int i;
	scanf("%d",&i);
	
	pthread_cancel(tid_child1);
	pthread_cancel(tid_child2);
	
	while(1)
	{
		sleep(1);
	}

	return 0;
}
