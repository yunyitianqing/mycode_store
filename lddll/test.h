#ifndef _TEST_H_
#define _TEST_H_

typedef void* (*TEST_FUN)(void*);

class B
{
public:
	B(){};
};

class A :public B
{
	static A*a;
public:
	A();
	
	~A()
	{
		printf("A_xigou\n");
	}
	
	void print();
	
	static A* getGoalA(){return a;}
	
	void*fun(void*);
};

#endif//_TEST_H_
