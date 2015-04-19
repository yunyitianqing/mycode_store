#include"neural_layer.h"

Layer::Layer(string name,int from,int to,int y,int x,int flag)
{
	this->name=name;///神经网络名字
	this->from=from;///神经网络的输入层
	this->to=to;///神经网络的输出层

	this->max_x=x;///输出神经层，神经元个数上限
	this->max_y=y;///输入神经层，神经元个数上限
	this->flag=flag;///0==无，1==矩阵，2==三元表

	switch(flag)
	{
	case 0:
		null_init();
		break;
	case 1:
		matrix_init();
		break;
	case 2:
		triad_init();
		break;
	case 3:
		break;
	
		
	}
	
	
}

Layer::~Layer()
{
	switch(flag)
	{
	case 0:
		null_fini();
		break;
	case 1:
		matrix_fini();
		break;
	case 2:
		triad_fini();
		break;
	case 3:
		break;
	}
}


void Layer::null_init()
{
	
}

void Layer::null_fini()
{
		
}

void Layer::matrix_init()
{
	vector<double> v1;
	for(int i=0;i<max_x;i++)
		matrix_ratio.push_back(v1);
}

void Layer::matrix_fini()
{
	for(int i=0;i<max_x;i++)
		matrix_ratio[i].clear();
	matrix_ratio.clear();
	
}

void Layer::triad_init()
{

} 

void Layer::triad_fini()
{
	triad.clear();
}

///设置max_x,输出神经元个数
int Layer::push_x(int x)
{
	if(flag!=1)
		return -7;
	max_x++;
	vector<double>v1;
	matrix_ratio.push_back(v1);
	for(int i=0;i<max_y;i++)
		matrix_ratio[max_x].push_back(0);
	return 0;
}
///设置max_Y,输入神经元个数
int Layer::push_y(int y)
{
	if(flag!=1)
		return -7;
	max_y++;
	for(int i=0;i<max_x;i++)
		matrix_ratio[i].push_back(0);
}

///弹出末位输出神经元
int Layer::pop_x()
{
	if(flag!=1)
		return -7;
	if(max_x==0)
		return -10;
	matrix_ratio[max_x].clear();
	matrix_ratio.pop_back();
	max_x--;
	return 0;
}
///弹出末位输入神经元
int Layer::pop_y()
{
	if(flag!=1)
		return -7;
	if(max_y==0)
		return -10;
	if(max_x==0)
		return -11;
	for(int i=0;i<max_x;i++)
		matrix_ratio[i].pop_back();
	max_y--;
	return 0;
}

///添加连接权值进入三元表
int Layer::add_triad(int from,int to,double ratio)
{
	if(flag!=2)
		return -7;
	Triad t;
	t.from=from;
	t.to=to;
	t.ratio=ratio;
	triad.push_back(t);
	return 0;
}
///删除从from到to的连接权值 return -1 not find
///return 0 del ok
///return -7 flag error
int Layer::del_triad(int from,int to)
{
	if(flag!=2)
		return -7;
	list<Triad>::iterator i;
	for(i=triad.begin();i!=triad.end();++i)
	{
		if(i->from==from && i->to==to)
		{
			triad.erase(i);
			return 0;
		}
	}
	return -1;
}
