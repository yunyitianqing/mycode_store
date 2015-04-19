#ifndef _POPULATION_
#define _POPULATION_

#include<vector>
#include"gene_base.h"
using namespace std;
///种群类，初始化给父本分配内存，
///运行时给子本个体分配和收回内存空间。
class Population
{
protected:
	///杂交
	void population_breed(int i_parent1,int i_parent2);
	///变异
	void population_change(int);
	///复制
	void population_copy(int);
	///选择，生存竞争。
	virtual void population_choice();
	//#########选择、生存竞争子方式##########
	///轮盘赌
	void population_choice_roulette();
	///n扇分轮盘赌
	void population_choice_roulette_n(int n);
	///排序
	void population_choice_ranking();
	///局部竞争
	void population_choice_localCompetition();
	//######################################
	
	GeneBase * source;
	
	///存储种群中有多少个个体
	int num;
	///一次生存竞争后留下的个体百分比
	double choice_p;
	
public:
	Population(GeneBase*p,int num,double choice_p);
	~Population();
	///处理
	void process(double breed_p,double change_p,double choice_p);
	///初始化种群
	void population_init(int num,GeneBase*p,int is_rand=0);
	void population_grow();
protected:
	///个体
	vector<GeneBase*>p_parent;
	vector<GeneBase*>p_child;

	
	
	
	
};

#endif//_POPULATION_
