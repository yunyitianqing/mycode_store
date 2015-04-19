#ifndef _NERVE_BASE_
#define _NERVE_BASE_

#include<string>
using namespace std;

class NerveBase
{
protected:
	double value_temp;
	double value_output;
	double b;
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
	void change_B(double b);
	virtual void caculate_output()=0;
};

#endif
