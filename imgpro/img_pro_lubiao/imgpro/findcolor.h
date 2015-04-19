#ifndef _FINDCOLOR_
#define _FINDCOLOR_
#include<cv.h>
#include<iostream>
class WitFindColor
{
protected:
	/// 输入的图像
	IplImage*src;	
	/// 输出的图像
	IplImage*dst;	
	/// 第一通道的阈值max
	int channel1max,
	/// 第一通道的阈值min
		channel1min;	
	/// 第二通道的阈值max
	int channel2max,
	/// 第二通道的阈值min
		channel2min;	
	/// 第三通道的阈值max
	int channel3max,
	/// 第三通道的阈值min
		channel3min;	
	/// 在阈值范围内的像素点数
	int pointNum;	
	/// 在阈值范围内的像素点数的中心点
	CvPoint averagePoint;	
	/// 临时变量
	int sumX,
	/// 临时变量
		sumY;	
public:
	/// 构造函数
	WitFindColor(){};
	///带参数的构造函数
	WitFindColor(IplImage*src,IplImage*dst,int v1=0,int v2=0,int v3=0,int v4=0,int v5=0,int v6=0)
	{
		loadImage(src,dst);
		channel1min=v1;
		channel1max=v2;
		channel2min=v3;
		channel2max=v4;
		channel3min=v5;
		channel3max=v6;
	};
	WitFindColor(IplImage*src)
	{
			this->src=src;
	}
	/// 复制构造函数
	WitFindColor(WitFindColor&);
	///析构函数。
	~WitFindColor(){};
	///  loadImage 导入图像
	///  \param src [in] 源图像指针，支持单通道，HSV通道和BGR通道。
	///  \param dst [in] 目标图像指针，支持BGR通道和单通道。
	void loadImage(IplImage*src,IplImage*dst);
	///  loadImageSrc 导入源图像指针
	void loadImageSrc(IplImage*);
	///  loadImageDst导入目标图指针
	void loadImageDst(IplImage*);
	///  loadImage导入阈值
	///  \param threshold [in]阈值指针[0]H/Bmin或者是单通道的min
	///                          [1]H/Bmax或者是单通道的max
	///                          [2]S/Gmin
	///                          [3]S/Gmax
	///                          [4]V/Rmin
	///                          [5]V/Rmax
	void loadThreshold(int*threshold);
	
	
	/// findByHSV2GRAY
	/// 通过导入的阈值与一张HSV图二值化图像。
	void findByHSV2GRAY();
	void findByHSV2GRAY(IplImage*dst);
	/// findByBGR2GRAY
	/// 通过导入的阈值与一张BGR图二值化图像。
	void findByBGR2GRAY();
	void findByBGR2GRAY(IplImage*dst);
	/// findByHSV2BGR
	/// 通过阈值在HSV图像上面找到阈值范围内的像素，并且用你指定的颜色填充哦过年到一张BGR图上面
	/// \param setcolor [in]你指定的颜色指针，[0]B,[1]G,[2]R
	void findByHSV2BGR(const int* setcolor);
	/// findByBGR2BGR
	/// 通过阈值在BGR图像上面找到阈值范围内的像素，并且用你指定的颜色填充哦过年到一张BGR图上面
	/// \param setcolor [in]你指定的颜色指针，[0]B,[1]G,[2]R
	void findByBGR2BGR(const int* setcolor);
	/// findByGRAY2GRAY
	/// 灰度图转化为二值图，在阈值范围内为白色，不再为黑色。
	void findByGRAY2GRAY();
	void findByGRAY2GRAY(IplImage*dst);
	/// returnPointNum 返回在阈值范围内的点数
	/// \return 在阈值范围内的点数
	int returnPointNum();
	/// returnAveratePoint 返回中心点
	/// \return 中心点
	CvPoint returnAveragePoint();
};

class Map_FindColor_Base 
{
protected:
	bool(*ColorMap)[256];
public:
	Map_FindColor_Base();
	Map_FindColor_Base(int*thresh);
	Map_FindColor_Base(int v1min ,int v1max,int v2min,int v2max,int v3min=0,int v3max=255);
	~Map_FindColor_Base(){delete []ColorMap[256];}
	void mapAddThreshRect(int v1,int v2,int v3,int v4);
	void mapAddThreshRect(CvPoint &LU,CvPoint &RD);
	void mapCutThreshRect(int v1,int v2,int v3,int v4);
	void mapCutThreshRect(CvPoint &LU,CvPoint &RD);
};

class FindColor_Base
{
protected:
	int v1min;
	int v1max;
	int v2min;
	int v2max;
	int v3min;
	int v3max;
	bool inThreshHSV(int H,int S, int V );
public:
	FindColor_Base(){};
	FindColor_Base(int v1min,int v1max,int v2min=0,int v2max=255,int v3min=0 ,int v3max=255)
	{
		this->v1min=v1min;
		this->v1max=v1max;
		this->v2min=v2min;
		this->v2max=v2max;
		this->v3min=v3min;
		this->v3max=v3max;
	};
	void loadThresh(int v1min,int v1max,int v2min,int v2max,int v3min=0 ,int v3max=255);
	void loadThresh(int *thresh);
	
};

//public Map_FindColor_Base ,
class Blob_FindColor : public FindColor_Base
{
protected:
	IplImage*BlobMap;
	int BlobNum;
	int (*BlobPix)[2];
	//double k;
public:	
	Blob_FindColor(int num);
	Blob_FindColor(int num,IplImage*BlobMap);
	~Blob_FindColor();
	int loadBlobMap(IplImage*map);
	int findByHSV2GRAY(IplImage*src,IplImage*dst,double percent=0.7);
};

#endif //_FINDCOLOR_
