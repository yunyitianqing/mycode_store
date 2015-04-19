#include<imgpro.h>

int main()
{
	char file[100];
	
	IplImage *src,*dst,*resize;
	
	for(int i=1;i<=1200;++i)
	{
		sprintf(file,"img/source/%04d.bmp",i);
		printf("%s\n",file);
		src=cvLoadImage(file);
		
		resize=cvCreateImage(cvSize(src->width/1,src->height/1),8,3);
		cvResize(src,resize);
		dst=cvCreateImage(cvGetSize(resize),8,1);
		
	
		
	
		ThreshAdaptive *imgpro=new ThreshAdaptive(resize);
		int thresh[6]={80,120,150,255,0,255};
		imgpro->run_canny(thresh);
	
	
	
		
	
	
	    
    
		cvWaitKey(0);
	
		cvReleaseImage(&src);
		cvReleaseImage(&resize);
		
		cvReleaseImage(&dst);
		delete imgpro;
		
	}
	return 0;
}
