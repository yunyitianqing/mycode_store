#include"anneal.h"

Anneal::Anneal(double temperature=1000)
{
	this->temperature=temperature;
	///温度下降梯度
	this->grad=0.9;
}

void Anneal::process()
{
	init();
	ESS=caculate_energy();
}
/*
double Anneal::caculate_energy(int flag)
{
	double min,double max;
	for()
	caculate_energy_one()
}
*/
