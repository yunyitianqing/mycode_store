#include"imgpro.h"
void MySobel(IplImage* src ,IplImage* dsrc)     //src ：单通道的灰度图，dsrc:单通道的结果图。
  {
		double a00,a01,a02;
		double a10,a11,a12;
		double a20,a21,a22;
		CvScalar s;
		for(int i=1;i<src->height-1;i++)
		{
			for(int j=1;j<src->width-1;++j)
			{
				a00=cvGet2D(src,i-1,j-1).val[0];
				a01=cvGet2D(src ,i-1,j).val[0];
				a02=cvGet2D(src,i-1,j+1).val[0];
				a10 = cvGet2D(src, i, j-1).val[0];
				a11 = cvGet2D(src, i, j).val[0];
				a12 = cvGet2D(src, i, j+1).val[0];
				a20 = cvGet2D(src, i+1, j-1).val[0];
				a21 = cvGet2D(src ,i+1, j).val[0];
				a22= cvGet2D(src, i+1, j+1).val[0];
				// x方向上的近似导数
				double ux = a20 * (1) + a21 * (2) + a22 * (1)+ (a00 * (-1) + a01 * (-2) + a02 * (-1));
				// y方向上的近似导数
				double uy = a02 * (1) + a12 * (2) + a22 * (1)+ a00 * (-1) + a10 * (-2) + a20 * (-1);
				s.val[0] = sqrt(ux*ux + uy*uy);

				cvSet2D(dsrc,i,j,s);
			}
		}
	}
