#include<stdio.h>
#include"test.h"



extern "C"
{

	void init()
	{
		printf("dll init\n");
		
	}
	
	void print()
	{
		A::getGoalA()->print();
	}

}
