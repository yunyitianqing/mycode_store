#include<unistd.h>
#include<termios.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#include"camera.h"
#include"51_proctrl.h"
#include"imgpro.h"
#include"findcolor.h"

#include<cv.h>
#include<highgui.h>
int main()
{
	Camera*camera=new Camera;
	IplImage*src=camera->get_frame();
	//=cvCreateImage(cvSize(320,240),8,3);
	ProCtrl proctrl;
	WitFindColor findcolor;
	IplImage*hsv=cvCreateImage(cvGetSize(src),8,3);
	IplImage*gray=cvCreateImage(cvGetSize(src),8,1);
	
	
	
	
	
	cvNamedWindow("src");
	
	cvNamedWindow("gray");
	
	cvNamedWindow("thresh");
	
	int Hmin=0;
	int Smin=0;
	int Vmin=0;
	int Hmax=0;
	int Smax=0;
	int Vmax=0;
	int start=0;
	int flag=0;
	cvCreateTrackbar("Hmin","thresh",&Hmin,180,0);
	cvCreateTrackbar("Hmax","thresh",&Hmax,180,0);
	
	cvCreateTrackbar("Smin","thresh",&Smin,255,0);
	cvCreateTrackbar("Smax","thresh",&Smax,255,0);
	
	cvCreateTrackbar("Vmin","thresh",&Vmin,255,0);
	cvCreateTrackbar("Vmax","thresh",&Vmax,255,0);
	cvCreateTrackbar("start","thresh",&start, 1,0);
	CvPoint point;
	flag=0;
	proctrl.stop();
	//while(1)
	//	proctrl.go();
	int thresh[6];
	int num;
	while(1)
	{
		src=camera->get_frame();
		cvCvtColor(src,hsv,CV_BGR2HSV);
		findcolor.loadImage(hsv,gray);
		
		
		thresh[0]=Hmin;
		thresh[1]=Hmax;
		thresh[2]=Smin;
		thresh[3]=Smax;
		thresh[4]=Vmin;
		thresh[5]=Vmax;
		findcolor.loadThreshold(thresh);
		findcolor.findByHSV2GRAY();
		point=findcolor.returnAveragePoint();
		num=findcolor.returnPointNum();
		cvShowImage("src",src);
		cvShowImage("gray",gray);
		cvWaitKey(33);
		
		if(start==0)
		{	flag=0;
			printf("%d\n",num);
			continue;
		}
		else
		{
			printf("1\n");
			printf("%d\n",num);
			if(point.x==-1||point.y==-1||num<2000)
			{
				printf("1.1\n");
				proctrl.turn_left();
			}
			if(num>20000&&num<250000)
			{
				printf("1.2\n");
				if(point.x<src->width*2/3&&point.x>src->width*1/3)
					proctrl.go();
				if(point.x<src->width*1/3)
					proctrl.turn_left();
				if(point.x>src->width*2/3)
					proctrl.turn_right();
			}		
			if(num>2000&&num<20000)
			{
				if(point.x<src->width/2);
					proctrl.turn_left();	
				if(point.x>src->width/2);
					proctrl.turn_right();
			}
			
			if(num>250000)
			{
				printf("1.3\n");
				proctrl.stop();
				start=0;
			}
				
			
			
			
			
		}
		
		
		
	}
	
	
	return 0;
}
