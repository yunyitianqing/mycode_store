#include"nerve_sig.h"
#include<math.h>
NerveSig::NerveSig(string name,int y,int x,int flag):NerveBase(name,y,x)
{
	this->flag=flag;
}

void NerveSig::caculate_output()
{
	if(flag==0)
		value_output=1/(1+exp(-value_temp));
	if(flag==1)
		value_output=tanh(value_temp);
}

