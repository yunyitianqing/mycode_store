#ifndef _GENE_BASE_
#define _GENE_BASE_

class GeneBase
{
public:
	static void breed(GeneBase*p1,GeneBase*p2,GeneBase*c1,GeneBase*c2)
	{
		p1->_breed(p1,p2,c1,c2);
	};
	///虚析构
	virtual ~GeneBase()=0;
	//virtual ceshi()=0;
	///虚杂交，指针传入后，强制类型转换为派生类，再进行计算
	virtual void _breed(GeneBase*p1,GeneBase*p2,GeneBase*&c1,GeneBase*&c2,int flag=1)=0;
	///虚变异，生成一个派生类实体。并返回指针
	virtual GeneBase* change(int num=1)=0;
	///虚复制，生成一个派生类实体。并返回指针
	virtual GeneBase* copy()=0;
	///虚生存斗争的，种群贡献度计算。
	virtual double choice()=0;
	///虚生成基因序列，根据srand，随机生成个体的基因。
	virtual void gene_rand(int seed)=0;
	///虚赋值计算，用于在父代和子代之间拷贝
	virtual GeneBase& operator=(GeneBase&old)=0;
	///虚new，用于生成子类。
	virtual GeneBase* new_opt()=0;
	///虚del,用于析构子类
	virtual void del_opt(GeneBase*)=0;
};

#endif
