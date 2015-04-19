#include"hc_matrix.h"

Matrix::Matrix()
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
		{
			if(i==j)
				data[i][j]=1;
			else 
				data[i][j]=0;
		}
}

Matrix::~Matrix()
{

}

Matrix::Matrix((double*data)[3])
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
		{
			if(i==j)
				this->data[i][j]=1;
			else 
				this->data[i][j]=0;
		}
		
		
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			this->data[i][j]=data[i][j];
		}
	
	
}

Matrix::Matrix(Matrix&old)
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
		{
			
			this->data[i][j]=old.data[i][j];
			
		}
}


int Matrix::ni(Matrix *res)
{
	//Matrix temp;
	//ni_accept_1(0,temp);

//***************************************
	
	
	
	
	
	
	
	
	Matrix*temp=new Matrix();
	
}


/*
int Matrix::ni_accept_1(int lieshu,Matrix*temp)
{
	if(temp)
	{
		if(data[lieshu][lieshu]==0)
		{
			for(int i=lieshu;i<4;i++)
			{
				if(data[i][lieshu])
				{
					ni_huan(lieshu,i,this);
					ni_huan(lieshu,i,temp);
					return 1;
				}
			}
			return 0;
		}
		else
			return 1;
	}
	return -1;
}

*/


