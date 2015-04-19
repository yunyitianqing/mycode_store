#include<cv.h>
#include<highgui.h>
#include<iostream>


#define NUM 10

class WitThreshold
{
//private:
//protected:
public:	
	int *control;
	//[0]->isAIchangeThreshold
	//[1]->isAIsetLong
	//[2]->isAIsetLimit
//	int isFindWhite;
	
	IplImage *srcHSV;
//	IplImage *myStatisH;
	int *H12_H,*H12_1,*H12_2;

	int Bmax,Gmax,Rmax,Bmin,Gmin,Rmin;
	int Hmax,Smax,Vmax,Hmin,Smin,Vmin;
	int Crmax,Crmin,Cbmax,Cbmin;
	int *y_H;
	int averageH,averageS,averageV;
	int averageInH,averageInS,averageInV;
	int dataH[NUM],dataS[NUM],dataV[NUM];
	int dataInH[NUM],dataInS[NUM],dataInV[NUM];
	int longH,long1,long2;
	int limitHmax,limitSmax,limitVmax,limitHmin,limitSmin,limitVmin;

	int Light;
	int averageB,averageW,averageBW;

	WitThreshold();
	WitThreshold(WitThreshold&);
	~WitThreshold();

	void loadImage(IplImage*);
	void loadThresholdHSV(int*);
	void loadThresholdBWmainB(int*);
	void loadThresholdLimit(int*);
	void loadControl(int*);
	void loadLongH12(int*);
	
	void returnThresholdHSV(int*);
	void returnThresholdBWmainB(int*);
	
	void valueStatisH12();
	void valueStatisBW();
	void valueStatisMainH();
//	void drawStatis(int);
	
//	int* returnData(int flag);
	
	void AIsetLimit();
	void AIsetLong();
	
	void AIchangeThresholdBW();
	void AIchangeThresholdH();
	void AIchangeThresholdHSVbyConstLongLimit(bool,bool,bool);

	
};

class WitFindColor
{
private:
	IplImage*src,*dst;
	int channel1max,channel1min;
	int channel2max,channel2min;
	int channel3max,channel3min;
	int pointNum;
	CvPoint averagePoint;
	int sumX,sumY;
public:
	WitFindColor(){};
	WitFindColor(WitFindColor&);
	~WitFindColor(){};
	
	void loadImage(IplImage*src,IplImage*dst);
	void loadImageSrc(IplImage*);
	void loadImageDst(IplImage*);
	void loadThreshold(int*);
	
	
	
	void findByHSV2GRAY();
	void findByBGR2GRAY();
	void findByHSV2BGR(const int* setcolor);
	void findByBGR2BGR(const int* setcolor);
	void findByGRAY2GRAY();
	
	int returnPointNum();
	CvPoint returnAveragePoint();
};
