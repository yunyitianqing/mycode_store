#ifndef _HC_MATRIX_
#define _HC_MATRIX_

class Matrix
{   private:
		int get(Matrix*,int,int);

	public:
		double data[4][4];
		Matrix();
		~Matrix();
		Matrix(const Matrix&);
		Matrix operator=(const Matrix& rhs);
		int ni(Matrix *res);
		void print();
		friend Matrix operator*(const Matrix& A,const Matrix B);
		friend Matrix cheng(const Matrix A,const Matrix B);
		Matrix cheng(const Matrix A);
		Matrix zhuan();
};

#endif
