//分段神经元
#ifndef _NERVE_SEC_
#define _NERVE_SEC_
#include"nerve_base.h"
#include<string>
using namespace std;

class NerveSec : public NerveBase
{
	int flag;
public:
	/// \param[in] 神经元所在域的名字
	/// \param[in] 神经元所在的层数
	/// \param[in] 神经元为该层的哪一个
	/// \param[in] 为0，输出0~1/为1,输出-1~1
	NerveSec(string name,int y,int x,int flag=0);
	
	///虚继承，计算输出
	void caculate_output();
};


#endif
