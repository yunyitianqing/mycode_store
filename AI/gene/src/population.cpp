#include"population.h"
#include<stdlib.h>

#include<sys/time.h>

#include<algorithm>


Population::Population(GeneBase*p,int num,double choice_p)
{
	
	//i_parent=p_parent->begin();
	//i_child=p_child->begin();
	
	source=p;
	this->num=num;
	this->choice_p=p;
	
	num=0;
}

Population::~Population()
{
	population_fini();

	
}

void Population::population_init(int num,GeneBase*p,int is_rand)
{
	struct timeval mytime;
	gettimeofday(&mytime,NULL);
	unsigned int seed;
	srand(mytime.tv_sec+mytime.tv_usec);///time is sseed
	seed=rand();
	this->num=num;
	
	for(int i=0;i<num;i++)
	{
		p_parent.push_back(p->new_opt());
		if(is_rand)
			p_parent[i]->gene_rand(seed);
			
		
	}
	
	
	
}

void Population::population_grow()
{
	vector<GeneBase*>::iterator i_parent=p_parent.begin();
	for(;i_parent!=p_parent.end();i_parent++)
	{
		delete (*i_parent);
	}
	p_parent.clear();
	p_parent=p_child;
	p_child.clear();
}

///杂交private
void Population::population_breed(int i_parent1,int i_parent2)
{
	GeneBase*c1 ,*c2;
	
	GeneBase::breed(p_parent[i_parent1],p_parent[i_parent2],c1,c2);
	
	p_child.push_back(c1);
	p_child.push_back(c2);
}
///变异private,未进行选择，选择由上层函数按概率完成
///i_parent输入，要变异的父代个体
void Population::population_change(int i_parent)
{
	p_child.push_back(p_parent[i_parent]->change());
	
}
///复制private
void Population::population_copy(int i_parent)
{
	p_child.push_back(p_parent[i_parent]->copy());
}
///选择，生存竞争。private
void Population::population_choice(int METHOD_FLAG)
{
	
}

void Population::process(double breed_p,double change_p)
{
	
}

bool Population::population_find_max(GeneBase*p1,GeneBase*p2)
{
	double a1;
	double a2;
	
	a1=p1->choice();
	a2=p2->choice();
	
	if(a1>a2)
		return 1;
	else
		return 0;
	
}

///排序选择法
void Population::population_choice_ranking()
{
	vector<GeneBase*>::iterator i_begin=p_child.begin();
	vector<GeneBase*>::iterator i_end=p_child.end();
	sort(i_begin,i_end,population_find_max);
	
	while(p_child.num()>(int)(num*choice_p))
	{
		i_end=p_child.end();
		delete *i_end;
		p_child.pop_back();
	}
}
