#include<cv.h>
#include<highgui.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	IplImage*src=cvLoadImage("./2.png");
	
	
	/*FILE*fp=fopen("abc.txt","a+");
	for(int y=100;y<src->height;y++)
	{
		for(int x=100;x<src->width;x++)
		{
			int pid;
			pid=fork();
			if(pid==0)
			{
				
				IplImage*resize=cvCreateImage(cvSize(src->width/5+1,src->height/5+1),8,3);
				cvResize(src,resize);
				fprintf(fp,"x=%d,y=%d,success\n",x,y);
				printf("x=%d,y=%d,success\n",x,y);
				cvReleaseImage(&resize);
				exit(0);
			}
			sleep(1);
		}
		fprintf(fp,"\n");
	}
	*/
	IplImage*resize=cvCreateImage(cvSize(711,400),8,3);
				cvResize(src,resize);
	cvNamedWindow("1");
	cvNamedWindow("2");
	cvShowImage("1",src);
	cvShowImage("2",resize);
	cvWaitKey(0);
	return 0;
}
