#ifndef _WIT_MANAGER_
#define _WIT_MANAGER_
#include"WitModule.h"
#include<pthread.h>
#include<iostream>
#include<stdio.h>

#define MAX_MODULE 100

using namespace std;

class Manager
{
	Module* modules[MAX_MODULE];
	static Manager* m_UniqueInstance;
	
public:
	pthread_t thread_ID;
	static void*thread_main(void*);
	Manager();
	void process();
	int add_module(Module*module);
	bool del_module(int i);
	bool del_module(string name);
	static Manager* GetInstance() { return m_UniqueInstance; }
};


#endif //_WIT_MANAGER_
