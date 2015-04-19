#include<cv.h>
#include<highgui.h>
#include<stdio.h>



IplImage* mysrc;
IplImage* mydst;
int*thresh;
CvPoint *pp_res;



/*

void trackbar_callback()
{
	
}





void fun_mouse_callback(int event, int x, int y, int flags, void* param)
{
	IplImage*img=(IplImage*)param;
	cvPoint LU;
	cvPoint RD;
	unsigned char* p;
	switch(event)
	{
		case CV_EVENT_LBUTTONDOWN:
		{
			LU.x=x;
			LU.y=y;
		}
		break;
		case CV_EVENT_LBUTTONUP:
		{
			RD.x=x;
			RD.y=y;
			
			int hmax=0;
			int hmin=180;
			int smax=0;
			int smin=255;
			int vmax=0;
			int vmin=255;
			
			for(int Y=LU.y;Y<RD.y;Y++)
			{
				p=(unsigned char*)(img->imageData+Y*img->widthStep);
				for(int X=LU.x;X<RD.x;X++)
				{
					if(p[3*X+0]<hmin)
						hmin=p[3*X+0];
					if(p[3*X+0]>hmax)
						hmax=p[3*X+0];
					
					if(p[3*X+1]<smin)
						smin=p[3*X+1];
					if(p[3*X+1]>smax)
						smax=p[3*X+1];
					
					if(p[3*X+2]<vmin)
						vmin=p[3*X+2];
					if(p[3*X+2]>vmax)
						vmax=p[3*X+2];
					
				}
				
			}
			
			thresh[0]=hmax;
			thresh[1]=hmin;
			thresh[2]=smax;
			thresh[3]=smin;
			thresh[4]=vmax;
			thresh[5]=vmin;
			
			cvSetTrackbarPos("Hmin","trackbar",thresh[0]);
			cvSetTrackbarPos("Hmax","trackbar",thresh[1]);
			cvSetTrackbarPos("Smin","trackbar",thresh[2]);
			cvSetTrackbarPos("Smax","trackbar",thresh[3]);
			cvSetTrackbarPos("Vmin","trackbar",thresh[4]);
			cvSetTrackbarPos("Vmax","trackbar",thresh[5]);
			
		}
		break;
	}
}


void hc_marathon_simple()
{
	
	
	
	IplImage*hsv;
	
	
	hsv=cvCreateImage(cvGetSize(mysrc),8,3);
	
	cvCvtColor(mysrc,hsv,CV_BGR2HSV);
	
	int pointNum=0;
	int sumX=0;
	int sumY=0;
	unsigned char*psrc,*pdst;
	
	for(int y=0;y<src->height;++y)
	{
		psrc=(unsigned char *)(hsv->imageData+y*hsv->widthStep);
		pdst=(unsigned char *)(mydst->imageData+y*mydst->widthStep);	
		for(int x=0;x<src->width;++x)
		{
			if(psrc[3*x]<=thresh[1]&&psrc[3*x]>=thresh[0]
			&&psrc[3*x+1]<=thresh[3]&&psrc[3*x+1]>=thresh[2]
			&&psrc[3*x+2]<=thresh[5]&&psrc[3*x+2]>=thresh[4])
			{
				pdst[x]=255;
				pointNum++;
				sumX+=x;
				sumY+=y;
			}
			else
			{
				pdst[x]=0;
			}
		}
	}
	
	
	if(pointNum!=0)
	{
		pp_res[0].x=sumX/pointNum;
		pp_res[0].y=sumY/pointNum;	
	}
	else
	{
		pp_res[0].x=-1;
		pp_res[0].y=-1;	
	}
	
	cvCvtColor(mydst,res,CV_GRAY2BGR);
	//memcpy(res_data, res->imageData, res->imageSize);
	cvReleaseImage(&hsv);
	//cvReleaseImage(&mydst);
	//cvReleaseImage(&mysrc);
}
*/

int main(int argc,char*argv[])
{
	IplImage*src;
	IplImage*dst;
	dst=cvCreateImage(cvSize(320,240),8,3);
	/*
	cvNamedWindow("trackbar");
	cvNamedWindow("src");
	
	thresh=new int[6];
	
	for(int i=0;i<6;i++)
		thresh[i]=0;
	
	cvCreateTrackbar("Hmin","trackbar",&thresh[0],180,0);
	cvCreateTrackbar("Hmax","trackbar",&thresh[1],180,0);
	cvCreateTrackbar("Smin","trackbar",&thresh[2],255,0);
	cvCreateTrackbar("Smax","trackbar",&thresh[3],255,0);
	cvCreateTrackbar("Vmin","trackbar",&thresh[4],255,0);
	cvCreateTrackbar("Vmax","trackbar",&thresh[5],255,0);
	
	
	dst=cvCreateImage(cvSize(320,240),8,1);
	
	
	
	cvSetMouseCallback("src",fun_mouse_callback,hsv);
	*/
/*	char*path=new char[100];
	
	char*path_save=new char[100];
	
	for(int i=1;i<1000;i++)
	{
		sprintf(path,"./pic_src_2/%04d.bmp",i);
		sprintf(path_save,"./pic/%04d.bmp",i);
		src=cvLoadImage(path);
		//mysrc=src;
		//mydst=dst;
		for(int xy=0;xy<320*240;xy++)
		{
			dst->imageData[3*(320*240-xy)+0]=src->imageData[3*xy+0];
			dst->imageData[3*(320*240-xy)+1]=src->imageData[3*xy+1];
			dst->imageData[3*(320*240-xy)+2]=src->imageData[3*xy+2];
		}
		//hc_marathon_simple();
		cvSaveImage(path_save,dst);
		
	}
	
*/	
	
	return 0;
}

