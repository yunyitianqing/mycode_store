#ifndef _NERVE_BASE_
#define _NERVE_BASE_

#include<string>
using namespace std;

class NerveBase
{
protected:
	///累计求和时的累加变量。
	double value_temp;
	///最后的输出变量
	double value_output;
	
	///名字
	string name;
	///神经元所在层数
	int y;
	///神经元是该层的哪一个
	int x;
public:

	NerveBase(string name, int y, int x);
	virtual ~NerveBase();

	void input(double x ,double w);
	
	void clear(){value_temp=0;};
	virtual void caculate_output()=0;
};

#endif
