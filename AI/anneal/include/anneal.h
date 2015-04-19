#ifndef _ANNEAL_
#define _ANNEAL_
///退火算法
class Anneal
{
protected:
	///温度
	double temperature;
	///温度下降梯度
	double grad;
	///全局最优解
	double ESS;
public:
	Anneal(double temperature=1000);
	///设置温度
	void set_temperature(double);
	///设置下降梯度默认为0.9，max<1
	void set_grad(double=0.9);
	///计算能量
	///flag==0 返回能量最小值
	///flag==1 返回能量最大值
	virtual double caculate_energy(int flag=0);
	virtual double caculate_energy_one()=0;
	///扰动
	virtual void turbulence()=0;
	bool probability_accept();
	void process();
};


#endif
