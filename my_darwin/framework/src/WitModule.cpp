#include"WitModule.h"

Module::Module(char*name)
{
	module_fd=0;
	is_start=0;
	is_run=0;
	is_stop=0;
	if(name)
		this->name=name;
}

void Module::set_name(char*name)
{
	if(name)
		this->name=name;
	
}


void*Module::thread_process(void*param)
{
	Module * This=(Module*)param;
	This->M_thread();
	return 0;
}
