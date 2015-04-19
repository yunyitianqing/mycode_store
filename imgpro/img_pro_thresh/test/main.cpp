#include<imgpro.h>
#include<stdlib.h>
#include<stdio.h>
/*
int main()
{
	char file[100];
	
	IplImage *src,*dst,*resize,*hsv;
	IplImage *thresh_dst;
	int thresh[6]={100,120,150,255,0,255};
	for(int i=450;i<=6800;++i)
	{
		sprintf(file,"mara_source/%d.jpg",i);
		printf("%s\n",file);
		src=cvLoadImage(file);
		
		resize=cvCreateImage(cvSize(src->width/1,src->height/1),8,3);
		
		cvResize(src,resize);
		
		cvNamedWindow("main_src_bgr");
		cvShowImage("main_src_bgr",resize);
		
		
		dst=cvCreateImage(cvGetSize(resize),8,1);
		hsv=cvCreateImage(cvGetSize(resize),8,3);
		thresh_dst=cvCreateImage(cvGetSize(resize),8,1);
		
		cvCvtColor(resize,hsv,CV_BGR2HSV);
		
		WitFindColor * findcolor=new WitFindColor(hsv,dst);
		
		findcolor->loadThreshold(thresh);
	
		findcolor->findByHSV2GRAY();
		
	
		ThreshAdaptive *imgpro=new ThreshAdaptive(resize);
		
		imgpro->run_canny(thresh,thresh_dst);
		//imgpro->run(thresh);
		
	
		cvNamedWindow("main_src_hsv");
		cvShowImage("main_src_hsv",hsv);
		cvNamedWindow("main_dst");
		cvShowImage("main_dst",dst);
		
		cvNamedWindow("main_threshdst");
		cvShowImage("main_threshdst",thresh_dst);
		
		printf("%d %d %d %d %d %d\n",thresh[0],thresh[1],thresh[2],thresh[3],thresh[4],thresh[5]);
	
	    
    
		cvWaitKey(0);
	
		cvReleaseImage(&src);
		cvReleaseImage(&resize);
		cvReleaseImage(&hsv);
		cvReleaseImage(&dst);
		delete imgpro;
		delete findcolor;
	}
	return 0;
}
*/

//sy1
/*
int main()
{
	IplImage*src=cvLoadImage("lena.jpg");
	
	if(src==0)
	{
		printf("error\n");
		exit(0);
	}
	
	cvNamedWindow("src");
	cvShowImage("src",src);
	
	cvWaitKey(0);
	
	IplImage*B,*G,*R;
	IplImage*resize1,*resize2;
	IplImage*junheng1,*junheng2,*junheng3,*junheng;
	
	B=cvCreateImage(cvGetSize(src),8,1);
	G=cvCreateImage(cvGetSize(src),8,1);
	R=cvCreateImage(cvGetSize(src),8,1);
	
	junheng1=cvCreateImage(cvGetSize(src),8,1);
	junheng2=cvCreateImage(cvGetSize(src),8,1);
	junheng3=cvCreateImage(cvGetSize(src),8,1);
	
	junheng=cvCreateImage(cvGetSize(src),8,3);
	
	resize1=cvCreateImage(cvSize(src->width/2,src->height/2),8,3);
	resize2=cvCreateImage(cvSize(src->width*2,src->height*2),8,3);
	
	
	ChannelSplit *split=new ChannelSplit(src);
	
	split->Channel3to1(B,0);
	split->Channel3to1(G,1);
	split->Channel3to1(R,2);
	
	cvNamedWindow("B");
	cvShowImage("B",B);
	cvNamedWindow("G");
	cvShowImage("G",G);
	cvNamedWindow("R");
	cvShowImage("R",R);
	cvWaitKey(0);
	cvResize(src,resize1);
	cvResize(src,resize2);
	
	cvNamedWindow("resize_small");
	cvShowImage("resize_small",resize1);
	cvNamedWindow("resize_big");
	cvShowImage("resize_big",resize2);
	cvWaitKey(0);
	
	cvEqualizeHist(B,junheng1);
	cvEqualizeHist(G,junheng2);
	cvEqualizeHist(R,junheng3);
	
	cvMerge(junheng1,junheng2,junheng3,0,junheng);
	
	cvNamedWindow("equal");
	cvShowImage("equal",junheng);
	cvWaitKey(0);
	
	return 0;
	
}
*/

//sy2

int main()
{
	IplImage*src=cvLoadImage("lena.jpg");
	
	if(src==0)
	{
		printf("error\n");
		exit(0);
	}
	
	IplImage*gray=cvCreateImage(cvGetSize(src),8,1);
	cvCvtColor(src,gray,CV_BGR2GRAY);
	IplImage*temp1=cvCreateImage(cvGetSize(src),8,1);
	IplImage*temp2=cvCreateImage(cvGetSize(src),8,1);
	cvSmooth
	
}

