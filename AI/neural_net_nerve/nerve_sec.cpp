#include"nerve_sec.h"

NerveSec::NerveSec(string name,int y,int x,int flag):NerveBase(name,y,x)
{
	this->flag=flag;
}

void NerveSec::caculate_output()
{
	value_output=value_temp;
	if(flag==0)
	{
		
		if(value_output>1)
			value_output=1;
		if(value_output<0)
			value_output=0;
	}
	if(flag==1)
	{
		if(value_output>1)
			value_output=1;
		if(value_output<-1)
			value_output=-1;
	}
}
