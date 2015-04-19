#include"nerve_base.h"


NerveBase::NerveBase(string name, int y, int x);
{
	double value_temp=0;
	double value_output=0;
	double b=0;
	
	this->name=name;
	this->y=y;
	this->x=x;
}

NerveBase::~NerveBase()
{

}

void NerveBase::input(double x ,double w)
{
	value_temp+=x*w;
}

void change_B(double b)
{
	this->b=b;
}

