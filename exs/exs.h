#include<stdio.h>
struct E_point
{
	int data;
	E_point*l;
	E_point*r;
	int blance;
};
class EXS
{
	E_point*root;
	
	E_point* is_blance(int&);
	void blance_rr();
	void blance_ll();
	void blance_rl();
	void blance_lr();
public:
	EXS();
	bool is_empty();
	void create(int*,int);
	void add(int);
	E_point* find(int,int&re);
	void del(int);
};
