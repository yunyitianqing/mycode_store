#ifndef _IMGPRO_
#define _IMGPRO_
#include<cv.h>
#include<highgui.h>
#include<stdio.h>
#include<findcolor.h>

#include"../blob/BlobResult.h"

class Base
{
protected:	
	IplImage *src;
public:
	Base(IplImage*src);
	Base();
	void loadImgSrc(IplImage*src);
	
};

///通道分离器
class ChannelSplit :virtual public Base
{
public:
	ChannelSplit(IplImage*src);
	int Channel3to1(IplImage*dst,int channelNum=0);
};

///边缘
class Border : virtual public Base
{
public:
	Border(IplImage*src);
	int find_border1(IplImage*dst);	
};

///角点
class Corner :virtual public Base
{
public:
	Corner(IplImage*src);
	int find_corner1(IplImage*dst);
};


///细化
class Thin :virtual public Base
{
protected:
	const static int erasetable[256];
	
	int npow(int n)  
	{  
	    int mul = 1;  
	    for(int i=0;i<n;i++)  
	    {  
	        mul *= 2;  
	    }  
	    return mul;  
	};
	
public:	
	Thin(IplImage*src);
	void scantable();  
};

const  int Thin::erasetable[256]={ 
	    0,0,1,1,0,0,1,1,     1,1,0,1,1,1,0,1,  
	    1,1,0,0,1,1,1,1,     0,0,0,0,0,0,0,1,  
	    0,0,1,1,0,0,1,1,     1,1,0,1,1,1,0,1,  
	    1,1,0,0,1,1,1,1,     0,0,0,0,0,0,0,1,  
	    1,1,0,0,1,1,0,0,     0,0,0,0,0,0,0,0,  
	    0,0,0,0,0,0,0,0,     0,0,0,0,0,0,0,0,  
	    1,1,0,0,1,1,0,0,     1,1,0,1,1,1,0,1,  
	    0,0,0,0,0,0,0,0,     0,0,0,0,0,0,0,0,  
	    0,0,1,1,0,0,1,1,     1,1,0,1,1,1,0,1,  
	    1,1,0,0,1,1,1,1,     0,0,0,0,0,0,0,1,  
	    0,0,1,1,0,0,1,1,     1,1,0,1,1,1,0,1,  
	    1,1,0,0,1,1,1,1,     0,0,0,0,0,0,0,0,  
	    1,1,0,0,1,1,0,0,     0,0,0,0,0,0,0,0,  
	    1,1,0,0,1,1,1,1,     0,0,0,0,0,0,0,0,  
  	    1,1,0,0,1,1,0,0,     1,1,0,1,1,1,0,0,  
	    1,1,0,0,1,1,1,0,     1,1,0,0,1,0,0,0  
	};
	
///自适应阈值	
class ThreshAdaptive : public Base
{
public:
	///BGR
	ThreshAdaptive(IplImage*src);
	void run(int *thresh);
	void run_canny(int *thresh);
};

///统计
class Statistics : public Base
{
	void show();
public:
	int *data;
	///GRAY
	Statistics(IplImage*src);
	void run();
};


///图像处理
class ImgPro :public Base
{
protected:
	
public:
	///BGR
	ImgPro(IplImage*src);
	///GRAY
	void find_lower(int*thresh,IplImage*dst);
	///GRAY,GRAY
	int myFlood1(IplImage*src);
	
	
 
};
#endif//_IMGPRO_
