#include"hc_matrix.h"
#include"iostream"
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
Matrix Matrix::cheng(const Matrix A)
{
	Matrix temp;
	int i,j,h;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			temp.data[i][j]=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			for(h=0;h<4;h++)
				temp.data[i][j]=temp.data[i][j]+this->data[i][h]*A.data[h][j];
	return temp;
}
Matrix::~Matrix()
{

}
Matrix::Matrix(const Matrix& s)
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			data[i][j]=s.data[i][j];
}
Matrix Matrix::operator=(const Matrix& rhs)
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			data[i][j]=rhs.data[i][j];
	return *this;
}
int Matrix::ni(Matrix *res)
{   
	Matrix temp1,*p;
	p=res;
	int i,j,t;
	double A=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			temp1.data[i][j]=get(p,j,i);
	for(j=0;j<4;j++)
	 	A=A+get(p,0,j);
	if(A==0)
		return t=0;
	else
    {
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				temp1.data[i][j]=temp1.data[i][j]/A/(temp1.data[3][3]/A);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				std::cout<<temp1.data[i][j]<<"\t";
			 std::cout<<std::endl;
		 }
		return t=1;

	}
	
}
int Matrix::get(Matrix *res,int i,int j)
{
	int a=0,b=0,h=0,c=0;
	double ab[3][3],s=0;
	for(a=0;a<4;a++)
	{   c=0;
		if(a==i)
			continue;
		else 
			for(b=0;b<4;b++)
				{		
					if(b==j)
					   continue;
					else
					{
						ab[h][c]=(*res).data[a][b];
						c++;
					}
				}
        h++;
       
	}
	for(h=0;h<3;h++)
	for(c=0;c<3;c++)
		s=ab[0][0]*ab[1][1]*ab[2][2]+ab[0][1]*ab[1][2]*ab[2][0]+ab[1][0]*ab[2][1]*ab[0][2]-ab[0][2]*ab[1][1]*ab[2][0]-ab[0][1]*ab[1][0]*ab[2][2]-ab[1][2]*ab[2][1]*ab[0][0];
	if((i+j)%2==0)	
			return s;
	else
	        return -s;
 }
void Matrix::print()
{
	int i,j;
	for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				std::cout<<data[i][j]<<"\t";
			std::cout<<std::endl;
		}
}


Matrix cheng(const Matrix A,const Matrix B)
{	
	Matrix temp;
	int i,j,h;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			temp.data[i][j]=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			for(h=0;h<4;h++)
				temp.data[i][j]=temp.data[i][j]+A.data[i][h]*B.data[h][j];
	return temp;
}

Matrix operator*(const Matrix& A,const Matrix B)
{
	return cheng(A,B);
}
Matrix Matrix::zhuan()
{	
	double a[4][4];
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			a[i][j]=data[i][j];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			data[i][j]=a[j][i];
}

/*
int main()
{ 
	int i,j,t;
	Matrix T,*f,A,C,B;
	f=&T;
	std::cout<<"please input the matrix"<<std::endl;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			std::cin>>T.data[i][j];
	t=T.ni(f);
	std::cout<<"t:"<<t<<std::endl;
	T.print();
	T.zhuan();
	T.print();
	B=cheng(A,C);
	B.print();
	T.cheng(A);
	T.print();
	return 0;
}
*/				
				
	
			
