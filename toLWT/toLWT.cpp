
#include"toLWT.h"

FindDoor::FindDoor(IplImage*src)
{
	this->src=src;
	
	
}

FindDoor::FindDoor(FindDoor&last)
{
	this->src=last.src;
	
	

}

FindDoor::~FindDoor()
{
	
	
}

void FindDoor::loadImage(IplImage*src)
{
	this->src=src;
}
 
void FindDoor::findNearestDoorByBlackAndWhite(int doormindistance,int doorheight)
{
	unsigned char *psrc;
	

	int count=0;//记录点数
	int *counts=new int[src->width];
	bool*isdoor=new bool[src->width];

	
	//统计每一列的点数
	for(int x=0;x<src->width;++x)
	{	
		psrc=(unsigned char*)(src->imageData+x);
		for(int y=0;y<src->height;++y)
		{
			if(psrc[y*src->widthStep]>200)
				count++;
		}
		counts[x]=count;
	}
	//判断这一条中是不是门
	for(int x=0;x<src->width;x++)
	{
		if(counts[x]>=doorheight)
			isdoor[x]=1;
		else isdoor[x]=0;
	}
	//找门的左边线
	for(int x=0;x<src->width;x++)
	{
		if(isdoor[x]==1)
		{
			door_left=x;
			break;
		}
	}
	//找门的右边线
	
	for(int x=0;x<src->width;x++)
	{
		if(isdoor[x]==1)
		{
			int flag=1;
			for(int i=1;i<doormindistance;++i)
			{
				if(isdoor[x+i]==1)
					flag=0;
			}
			if(flag==1)
				door_right=x;
		}
	}
	
	delete []counts;
	delete []isdoor;
}

void FindDoor::drawNearestDoorLR(IplImage*dst)
{
	unsigned char *pdst;
	
	for(int x=0;x<dst->width;x++)
	{
		//画边界，左，color=blue
		if(x==door_left)
		{
			pdst=(unsigned char*)(dst->imageData+x*3);
			for(int y=0;y<dst->height;++y)
			{
				pdst[y*dst->widthStep]=255;
			}
		}
		//画边界，右，color=red
		if(x==door_right)
		{
			pdst=(unsigned char*)(dst->imageData+x*3+2);
			for(int y=0;y<dst->height;++y)
			{
				pdst[y*dst->widthStep]=255;
			}
		}
	}
}


void Interface::interface1(IplImage*src,// a BGR picture
	int*thresholdHSV,	//[0]Hmin [1]Hmax [2]Smin [3]Smax [4]Vmin [5]Vmax
	int*returnData, //[0]door_left [1]door_right
	int*controlforAI,//[0] true is open AIchangeThreshold
					 //[1] true is open AIsetLong
					 //[2] true is open AIsetLimit
	int*controlForFinddoor,//[0] door min distance [1]door height
	int*limitThreshold=0,		//[0]Hmin [1]Hmax [2]Smin [3]Smax [4]Vmin [5]Vmax
	int*limitLong=0,	//[0]Hlong [1]Slong [2]Vlong
	IplImage*returnimg=0// a BGR picture
	)
{
	IplImage *HSV = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage *GRAY = cvCreateImage(cvGetSize(src), 8, 1);
	cvCvtColor(src, HSV, CV_BGR2HSV);
	
	threshold.loadImage(HSV);
	threshold.loadControl(controlforAI);
	threshold.loadThresholdHSV(thresholdHSV);
	
	threshold.AIsetLong();
	threshold.AIsetLimit();
	
	threshold.loadThresholdLimit(limitThreshold);
	threshold.loadLongH12(limitLong);
	std::cout<<"\n"<<threshold.longH<<"\t"
		<<threshold.long1<<"\t"
		<<threshold.long2<<"\n"
		<<threshold.limitHmin<<"\t"
		<<threshold.limitHmax<<"\t"
		<<threshold.limitSmin<<"\t"
		<<threshold.limitSmax<<"\t"
		<<threshold.limitVmin<<"\t"
		<<threshold.limitVmax<<"\n"
		<<threshold.Hmin<<"\t"
		<<threshold.Hmax<<"\t"
		<<threshold.Smin<<"\t"
		<<threshold.Smax<<"\t"
		<<threshold.Vmin<<"\t"
		<<threshold.Vmax<<"\n"
		<<"---------------------------\n"<<std::endl;
	threshold.valueStatisMainH();
	threshold.AIchangeThresholdHSVbyConstLongLimit(1,1,1);
	
	threshold.returnThresholdHSV(thresholdHSV);
	
	findcolor.loadImage(HSV,GRAY);
	findcolor.loadThreshold(thresholdHSV);
	findcolor.findByHSV2GRAY();
	
	cvDilate(GRAY,GRAY,0,3);
	cvErode(GRAY,GRAY,0,5);
	cvDilate(GRAY,GRAY,0,2);
	
	finddoor.loadImage(GRAY);
	finddoor.findNearestDoorByBlackAndWhite(controlForFinddoor[0],controlForFinddoor[1]);
	
	if(returnimg!=0)
	{
		cvCvtColor(GRAY,returnimg,CV_GRAY2BGR);
		finddoor.drawNearestDoorLR(returnimg);
	}
}



//main

int main()
{
	Interface   myinterface;
	IplImage *src,*dst;
	CvCapture *capture;
	int threshold[6];
	int returndata[2];
	int controlforAI[3];
	int controlforfinddoor[2];
	int thresholdLimit[6];
	int HSVlong[3];
	cvNamedWindow("src");
	cvNamedWindow("dst");
	cvNamedWindow("threshold");
	cvNamedWindow("AI");
	cvNamedWindow("finddoor");
	cvNamedWindow("limit");
	cvNamedWindow("long");
	
	cvCreateTrackbar("Hmin","threshold",&threshold[0],180,0);
	cvCreateTrackbar("Hmax","threshold",&threshold[1],180,0);
	cvCreateTrackbar("Smin","threshold",&threshold[2],255,0);
	cvCreateTrackbar("Smax","threshold",&threshold[3],255,0);
	cvCreateTrackbar("Vmin","threshold",&threshold[4],255,0);
	cvCreateTrackbar("Vmax","threshold",&threshold[5],255,0);
	cvCreateTrackbar("isopenAI","AI",&controlforAI[0],1,0);
	cvCreateTrackbar("isopenAIsetLong","AI",&controlforAI[1],1,0);
	cvCreateTrackbar("isopenAIsetLimit","AI",&controlforAI[2],1,0);
	cvCreateTrackbar("minDistance","finddoor",&controlforfinddoor[0],50,0);
	cvCreateTrackbar("doorheight","finddoor",&controlforfinddoor[1],640,0);
	
	cvCreateTrackbar("Hmin","limit",&thresholdLimit[0],180,0);
	cvCreateTrackbar("Hmax","limit",&thresholdLimit[1],180,0);
	cvCreateTrackbar("Smin","limit",&thresholdLimit[2],255,0);
	cvCreateTrackbar("Smax","limit",&thresholdLimit[3],255,0);
	cvCreateTrackbar("Vmin","limit",&thresholdLimit[4],255,0);
	cvCreateTrackbar("Vmax","limit",&thresholdLimit[5],255,0);
	
	cvCreateTrackbar("H","long",&HSVlong[0],180,0);
	cvCreateTrackbar("S","long",&HSVlong[1],255,0);
	cvCreateTrackbar("V","long",&HSVlong[2],255,0);
	
	
	capture=cvCreateCameraCapture(-1);
	src=cvQueryFrame(capture);
	dst=cvCreateImage(cvGetSize(src),8,3);
	while(1)
	{
		src=cvQueryFrame(capture);
		myinterface.interface1(src,threshold,returndata,controlforAI,
								controlforfinddoor,thresholdLimit,HSVlong,dst);
								
		cvShowImage("src",src);
		cvShowImage("dst",dst);
		cvWaitKey(33);
		
		printf("%d\t%d\t!!!!!!!!!!!\n",returndata[0],returndata[1]);
		
		
	}
	
	return 0;
}







//645487
