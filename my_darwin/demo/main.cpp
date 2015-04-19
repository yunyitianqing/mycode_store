#include"engines_control.h"
#include"WitManager.h"
#include<stdio.h>
#include<pthread.h>



int main()
{
	Manager::GetInstance()->add_module(EnginesControl::GetInstance());
	for(int i=0;i<=20;i++)
	{
		EnginesControl::GetInstance()->Angle[i]=0;
		EnginesControl::GetInstance()->engines[i].TORQUE_ENABLE=1;
	}
	EnginesControl::GetInstance()->start(); 
	pthread_create(&Manager::GetInstance()->thread_ID,0,Manager::thread_main,Manager::GetInstance());
	int input;
	while(1)
	{
		
		printf("input:\n");
		scanf("%d",&input);
		for(int i=0;i<=20;i++)
			EnginesControl::GetInstance()->engines[i].TORQUE_ENABLE=input;
		sleep(1);
	}
	return 0;
}
