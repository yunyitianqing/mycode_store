#ifndef IMG_PRO_H
#define IMG_PRO_H
#include<opencv/cv.h>
#include<opencv/highgui.h>
#include<iostream>
#include<string>
//class Size
//{
//public:
//    int width;
//    int height;
//    Size(int w,int h):width(w),height(h){}

//};

//2D32f
class Filter
{
protected:
    CvSize Filter_size;
    CvPoint source_point;

public:
    float **data;
    Filter(float**,CvSize,CvPoint);
    ~Filter();
    void working(IplImage*src,IplImage*dst);
};

#endif // IMG_PRO_H
