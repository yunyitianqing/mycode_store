#ifndef _HC_MATRIX_
#define _HC_MATRIX_

class Matrix
{
public:
	double data[4][4];
	
	
	Matrix();
	Matrix(double*);
//	Matrix((double*)[4]);
	Matrix((double*)[3]);

	~Matrix();
	
	Matrix(Matrix&);

//	Matrix jia(Matrix&);
//	Matrix jia(double&);
//	Matrix jian(Matrix&);
//	Matrix jian(double&);
//	Matrix cheng(Matrix&);
	
	

	Matrix zhuanzhi();
	int ni(Matrix*res);
	
	Matrix operator = (Matrix&old);
	
private:
	//void ni_huan(int hangshu,int hangshu,Matrix*)
	//void ni_jia(int hangshu,int hangshu,Matrix*);
	//void ni_jian(int hangshu,int hangshu,Matrix*);
	//void ni_cheng(int hangshu,double chengshu,Matrix*);
	//void ni_chu(int hangshu,double chushu,Matrix*);
	
	//int ni_accept_1(int lieshu,Matrix*temp=0);

};






#endif//_HC_MATRIX_
