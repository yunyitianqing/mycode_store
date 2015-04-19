#ifndef _WIT_MODULE_
#define _WIT_MODULE_
#include<pthread.h>
#include<string>
#include<iostream>
using namespace std;
class Manager;

class Module
{
protected:
	friend class Manager;
	pthread_t module_fd;
	bool is_start;
	bool is_run;
	bool is_stop;
	std::string name;
public:
	Module(char*name="Anonymous");
	void start(){is_start=1;};
	//void pause(){is_run=0;};
	void stop(){is_stop=1;};
	void set_name(char*name);
	//pthread_t get_pthread(){return module_fd};
	static void*thread_process(void*);
	virtual void M_thread()=0;
	virtual ~Module(){};
};


#endif //_WIT_MODULE_
