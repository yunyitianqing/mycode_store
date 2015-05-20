#ifndef _NERVE_STEP_
#define _NERVE_STEP_
//阶跃神经元
#include"nerve_base.h"
#include<string>
using namespace std;

class NerveStep : public NerveBase
{
	///正输出标志或正负输出标志。
	int flag;
	///输出阈值
	double b;
public:
	/// \param[in] 神经元所在域的名字
	/// \param[in] 神经元所在的层数
	/// \param[in] 神经元为该层的哪一个
	/// \param[in] 为0，输出0,1/为1,输出-1/1
	NerveStep(string name,int y,int x,int flag=0);
	
	/// 改变阈值
	void change_B(double b);
	
	///虚继承，计算输出
	void caculate_output();
};


#endif
