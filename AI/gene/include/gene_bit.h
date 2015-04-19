#ifndef _GENE_BIT_
#define _GENE_BIT_
#include"gene_base.h"
#include<vector>


using namespace std;
///以2进制编码的



class GeneBit : public GeneBase
{

protected:
	vector<unsigned char> gene;
	unsigned int gene_byte;
	///按位杂交运算，a是是否交换的核。该函数杂交8位。
	void breed_bit(unsigned char&p1,unsigned char&p2,unsigned char&c1,unsigned char&c2,unsigned char&a);
	///均匀杂交
	void _breed_equal(GeneBase*p1,GeneBase*p2,GeneBase*&c1,GeneBase*&c2);
	///多点杂交，num取1为单点。
	void _breed_points(GeneBase*p1,GeneBase*p2,GeneBase*&c1,GeneBase*&c2,int num);
	
	double _choice_find_max();
public:
	///基因编码字节数，位数*8
	GeneBit(unsigned int gene_byte);
	virtual ~GeneBit();
	///虚杂交，指针传入后，强制类型转换为派生类，再进行计算
	virtual void _breed(GeneBase*p1,GeneBase*p2,GeneBase*&c1,GeneBase*&c2,int flag=1);
	///虚变异，生成一个派生类实体。并返回指针
	virtual GeneBase* change(int num=1);
	///虚复制，生成一个派生类实体。并返回指针
	virtual GeneBase* copy();
	///虚生存斗争的，种群贡献度计算。
	virtual double choice();
	///虚生成基因序列，根据srand，随机生成个体的基因。
	virtual void gene_rand(int seed);
	///虚赋值计算，用于在父代和子代之间拷贝
	virtual GeneBase& operator=(GeneBase&old);
	///虚new，用于生成子类。
	virtual GeneBase* new_opt();
	///虚del,用于析构子类
	virtual void del_opt(GeneBase*);
};

#endif
