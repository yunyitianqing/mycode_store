#include<wit_camera.h>
#include<cv.h>
#include<highgui.h>
int main()
{
	CamModule*camera=new CamModule();
	int i=0;
	
	IplImage*img=cvCreateImage(cvSize(1000,1000),8,3);
	char path[50];
	
	while(1)
	{
		i++;
		camera->get_frame((unsigned char*)img->imageData);
		printf("%d\n",i);
		sprintf(path,"save/%04d.bmp",i);
		//cvSaveImage(path,img);
		int m=0;
		while(m<10000)
			m++;
		//usleep(1);
	}
	
	
	return 0;
}
