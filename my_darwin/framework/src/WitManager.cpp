#include"WitManager.h"
#include<pthread.h>

Manager* Manager::m_UniqueInstance = new Manager();

void* Manager::thread_main(void*param)
{
	if(param!=0)
	{
		Manager*This=(Manager*)param;
		This->process();
	}
	return 0;
}


Manager::Manager()
{
	for(int i=0;i<MAX_MODULE;i++)
	{
		modules[i]=0;
	}
}

int Manager::add_module(Module*module)
{
	int i=0;
	for(i=0;i<MAX_MODULE;i++)
	{
		if(modules[i]==0)
		{
			modules[i]=module;
			return -1;
		}
	}
	return i;
}



bool Manager::del_module(int i)
{
	if(modules[i])
	{
		delete modules[i];
		modules[i]=0;
		return 1;
	}
	else 
		return 0;
}

bool Manager::del_module(string name)
{
	for(int i=0;i<100;i++)
	{
		if(modules[i]->name==name)
		{
			return del_module(i);
		}
			
	}
	printf("don't have %s module",name.c_str());
	return 0;
}


void Manager::process()
{
	while(1)
	{
		for(int i=0;i<MAX_MODULE;i++)
		{
			if(modules[i])
			{	
				if(modules[i]->is_start==1 && modules[i]->is_run==0)
				{
					int p_create_res=0;
					p_create_res=pthread_create(&modules[i]->module_fd,0,modules[i]->thread_process,0);
					modules[i]->is_start=0;
					if(p_create_res)
					{
						char print_error[100];
						sprintf(print_error,"Module %s start failed:",modules[i]->name.c_str());
						perror(print_error);	
					}
					else
					{
						modules[i]->is_run=1;
					}
				}
				if(modules[i]->is_stop==1 && modules[i]->is_run==0)
				{
					int p_cancel_res=pthread_cancel(modules[i]->module_fd);
					modules[i]->is_stop=0;
					if(p_cancel_res)
					{
						char print_error[100];
						sprintf(print_error,"Module %s cancel failed:",modules[i]->name.c_str());
						perror(print_error);
						
					}
					else 
					{
						modules[i]->module_fd=0;
						modules[i]->is_run=0;
					}
				}
			}
			usleep(50);
		}
		sleep(1);
	}
}
