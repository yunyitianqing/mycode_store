#ifndef _NEURAL_LAYER_
#define _NEURAL_LAYER_


#include<list>
#include<vector>
#include<string>

using namespace std;

class Triad
{
public:
	int from;
	int to;
	double ratio;
};

class Layer
{
protected:
	///神经网络名字
	string name;
	///神经网络的输入层
	int from;
	///神经网络的输出层
	int to;
	///输出神经层，神经元个数上限
	int max_x;
	///输入神经层，神经元个数上限
	int max_y;
	///0==无，1==矩阵，2==三元表///0==无，1==矩阵，2==三元表
	int flag;
	
	void null_init();
	void null_fini();
	void matrix_init();
	void matrix_fini();
	void triad_init();
	void triad_fini();
public:
	///连接三元组
	list<Triad>triad;
	///连接矩阵
	vector<vector<double> >matrix_ratio;

	Layer(string name,int from,int to,int y,int x,int flag=0);
	virtual ~Layer();
	
	///设置max_x,输出神经元个数
	int push_x(int x);
	///设置max_Y,输入神经元个数
	int push_y(int y);
	///弹出末位输出神经元
	int pop_x();
	///弹出末位输入神经元
	int pop_y();
	///添加连接权值进入三元表
	int add_triad(int from,int to,double ratio);
	///删除从from到to的连接权值 return -1 not find
	///return 0 del ok
	///return -7 flag error
	int del_triad(int from,int to);
};

#endif
