#ifndef _TEST_H_
#define _TEST_H_

typedef void* (*TEST_FUN)(void*);

class A
{
	static A*a;
public:
	A()
	{
		printf("A2_gouzao\n");
		
	}
	~A()
	{
		printf("A2_xigou\n");
	}
	
	void print()
	{
		printf("A2_print\n");
	}
	
	static A* getGoalA(){return a;}
	
	void*fun(void*);
};

#endif//_TEST_H_
