#include"nerve_step.h"

NerveStep::NerveStep(string name,int y,int x,int flag):NerveBase(name,y,x)
{
	this->flag=flag;
}

void NerveStep::caculate_output()
{
	if(flag==0)
	{
		if(value_temp>=b)
			value_output=1;
		else
			value_output=0;
	}
	if(flag==1)
	{
		if(value_temp>=b)
			value_output=1;
		else
			value_output=-1;
	}
}

void NerveStep::change_B(double b)
{
	this->b=b;
}
