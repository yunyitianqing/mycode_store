#include"exs.h"
EXS::EXS()
{
	root=0;
}

void EXS::create(int*data,int max)
{
	E_point *p=new E_point();
	p->l=0;
	p->r=0;
	p->blance=0;
	p->data=data[0];
	root=p;
	for(int i=1;i<max;++i)
	{
		add(data[i]);
	}
}

void EXS::add(int data)
{
	int re;
	E_point*father=find(data,re);
	if(re==1)
		return;
	E_point *p=new E_point();
	p->l=0;
	p->r=0;
	p->blance=0;
	p->data=data;
	if(p->data<father->data)
		father->l=p;
	else father->r=p;

}

E_point* EXS::find(int a,int&re)
{
	return 0;
}

E_point* EXS::is_blance(int&re)
{
	return 0;
}
