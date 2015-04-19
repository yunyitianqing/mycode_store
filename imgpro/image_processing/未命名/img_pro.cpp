#include"img_pro.h"

Filter::Filter(float**p, CvSize size=cvSize(3,3), CvPoint point=cvPoint(-1,-1)):Filter_size(size), source_point(point)
{
    data=p;

}


Filter::~Filter()
{

}
void Filter::working(IplImage *src,IplImage*dst)
{
    CvMat mat=cvMat(Filter_size.height,Filter_size.width,CV_32FC1,*data);
    cvFilter2D( src, dst, &mat, source_point);

}


//int main()
//{
//    float a [3][3]={1,2,3,4,5,6,7,8,9};
//    Filter filter((float**)a);
//    IplImage* src,*dst;
//    src=cvLoadImage("Kinect/0107.bmp",0);
//    cvNamedWindow("1");
//    cvShowImage("1",src);
//    cvWaitKey(0);
    //dst=cvCreateImage()
//}
