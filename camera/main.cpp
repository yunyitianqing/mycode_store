#include<cv.h>
#include<highgui.h>
#include<stdio.h>
int main()
{
	IplImage*frame;
	
	CvCapture*capture=cvCreateCameraCapture(1);
	
	cvNamedWindow("1");
	char addr[1000];
	int i=0;
	while(1)
	{	
		i++;
		//printf("111\n");
		//sprintf(addr,"IMG/%5d.jpg",i);
		frame=cvQueryFrame(capture);
		//printf("112\n");
		if(!frame)break;
		cvShowImage("1",frame);
		cvWaitKey(35);
		//cvSaveImage(addr,frame);
	}
	return 0;
}
