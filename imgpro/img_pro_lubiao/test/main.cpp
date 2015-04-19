#include<imgpro.h>
#include<stdlib.h>
#include<stdio.h>
/*
void hc_marathon_international_lubiao2(IplImage*src, double*init_data,double*res_data)
{
	IplImage* gray1=cvCreateImage(cvGetSize(src),8,1);
	IplImage* temp1=cvCreateImage(cvGetSize(src),8,1);
	IplImage* temp2=cvCreateImage(cvGetSize(src),8,1);
	unsigned char*pg1,*pt1,*pt2;
	cvCvtColor(src,gray1,CV_BGR2GRAY);
	
	if(init_data[1]>0)//黑框白路标
	{
		int BW_thresh=init_data[1];
		for(int y=0;y<gray1->height;y++)
		{
			pg1=(unsigned char*)(gray1->imageData+y*gray1->widthStep);
			pt1=(unsigned char*)(temp1->imageData+y*temp1->widthStep);
			for(int x=0;x<gray1->width;x++)
			{
				if(pg1[x]>BW_thresh)
				{
					pt1[x]=255;
				}
				else
				{
					pt1[x]=0;
				}
			}
		}
	}
	else if(init_data[1]<0)//白框黑路标
	{
		int BW_thresh=-init_data[1];
		for(int y=0;y<gray1->height;y++)
		{
			pg1=(unsigned char*)(gray1->imageData+y*gray1->widthStep);
			pt1=(unsigned char*)(temp1->imageData+y*temp1->widthStep);
			for(int x=0;x<gray1->width;x++)
			{
				if(pg1[x]<BW_thresh)
				{
					pt1[x]=255;
				}
				else
				{
					pt1[x]=0;
				}
			}
		}
	}
	
	cvNamedWindow("kuang");
	cvShowImage("kuang",temp1);
	
	cvDilate(temp1,temp2,0,2);
	
	for(int y=0;y<gray1->height;y++)
	{
		
		pt1=(unsigned char*)(temp1->imageData+y*temp1->widthStep);
		pt2=(unsigned char*)(temp2->imageData+y*temp2->widthStep);
		for(int x=0;x<gray1->width;x++)
		{
			pt2[x]=pt2[x]-pt1[x];
		}
	}
	
		//temp2此时存的边缘
	CvMemStorage *storage = cvCreateMemStorage();  
    CvSeq *lines = 0; 
	lines = cvHoughLines2(temp2,storage,CV_HOUGH_PROBABILISTIC,1,CV_PI/180,40,10,10);
	if(lines->total==0)
    {
		cvReleaseImage(&gray1);
		cvReleaseImage(&temp1);
		cvReleaseImage(&temp2);
		cvReleaseMemStorage(&storage);
		return;
	}
	//
	
	int line_bianyuan[4];
	
	double x_min=240;
	double x_max=0;
	double y_min=320;
	double y_max=0;
	for (int i=0;i<lines->total;i++)  
    {  
        CvPoint *line = (CvPoint *)cvGetSeqElem(lines,i);  
        //cvLine(temp2,line[0],line[1],cvScalar(150),1,CV_AA);
        double x_mid=(line[0].x+line[1].x)/2;
        double y_mid=(line[0].y+line[1].y)/2;
        if(x_min>x_mid)
        {
        	x_min=x_mid;
        	line_bianyuan[0]=i;
        }
        if(x_max<x_mid)
        {
        	x_max=x_mid;
        	line_bianyuan[1]=i;
        }
        
        if(y_min>y_mid)
        {
        	y_min=y_mid;
        	line_bianyuan[2]=i;
        }
        if(y_max<y_mid)
        {
        	y_max=y_mid;
        	line_bianyuan[3]=i;
        }
    }
    
    if(x_min>x_max||y_min>y_max)
    {
    	cvReleaseImage(&gray1);
		cvReleaseImage(&temp1);
		cvReleaseImage(&temp2);
		cvReleaseMemStorage(&storage);
		return;
    }
    
    CvPoint center;
    center.x=0;
    center.y=0;
    
    for(int i=0;i<4;i++)
    {
    	CvPoint *line = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[i]);
        cvLine(temp2,line[0],line[1],cvScalar(150),1,CV_AA);
        center.x+=line[0].x;
        center.x+=line[1].x;
        center.y+=line[0].y;
        center.y+=line[1].y;
    }
    center.x/=8;
    center.y/=8;
    
    
    
    
    cvNamedWindow("temp2");
    cvShowImage("temp2",temp2);
	
	double k_shu[2];
	double k_heng[2];
	
	if(line_bianyuan[0]==line[1]_bianyuan)
	{
		CvPoint *line = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[0]);
        if(line[0].x-line[1].x==0)
        {
        	k_shu[0]=0;
        }
        else
        {
        	k_shu[0]=1;
        	k_shu[1]=(double)(line[0].y-line[1].y)/(double)(line[0].x-line[1].x);
        }
       
    }
    else
    {
    	CvPoint *line = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[0]);
    	CvPoint *line1 = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[1]);
        if(line[0].x-line[1].x==0&&line1[0].x-line1[1].x==0)
        {
        	k_shu[0]=0;
        }
        else
        {
        	k_shu[0]=1;
        	k_shu[1]=(((double)(line[0].y-line[1].y)/(double)(line[0].x-line[1].x))
        			+((double)(line1[0].y-line1[1].y)/(double)(line1[0].x-line1[1].x)))/2;
        }
    }
    
    
    if(line_bianyuan[2]==line[3]_bianyuan)
	{
		CvPoint *line = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[2]);
      
        k_heng[0]=1;
        k_heng[1]=(double)(line[0].y-line[1].y)/(double)(line[0].x-line[1].x);
        
       
    }
    else
    {
    	CvPoint *line = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[2]);
    	CvPoint *line1 = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[3]);
        
        k_heng[0]=1;
        k_heng[1]=(((double)(line[0].y-line[1].y)/(double)(line[0].x-line[1].x))
        		+((double)(line1[0].y-line1[1].y)/(double)(line1[0].x-line1[1].x)))/2;
        
    }
    cvPoint RU_y;
    cvPoint LU_y;
    cvPoint	LD_x;
    cvPoint LU_x;
    
    CvPoint *line = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[3]);
    	if(line[0].x<line[1].x)
    	{
    		RU_y.x=line[0].x;
    		RU_y.y=line[0].y;
    		LU_y.x=line[1].x;
    		LU_y.y=line[1].y;
    	}
    	else
    	{
    		RU_y.x=line[1].x;
    		RU_y.y=line[1].y;
    		LU_y.x=line[0].x;
    		LU_y.y=line[0].y;
    	}
    	CvPoint *line1 = (CvPoint *)cvGetSeqElem(lines,line_bianyuan[1]);
    	if(line1[0].y<line1[1].y)
    	{
    		LD_x.x=line[0].x;
    		LD_x.y=line[0].y;
    		LU_x.x=line[1].x;
    		LU_x.y=line[1].y;
    	}
    	else
    	{
    		LD_x.x=line[1].x;
    		LD_x.y=line[1].y;
    		LU_x.x=line[0].x;
    		LU_x.y=line[0].y;
    	}
    
    
    int num=0;
    
	if(k_shu[0]==0)
	{
		for(int x=LU_y.x;x<RU_y.x;x--)
		{
			pt1=(unsigned char*)(temp1->imageData+x);
			for(int y=LU_x.y;y<LD_x.y;y--)
	   		{
				if(pt1[y*temp1->widthStep]==0)
				{
					if(x<center.x)
						num--;
					else if(x>center.x)
					{
						num++;
					}
					break;
				}
			}
	   	}
	}
    else
    {
    	for(int x=LU_y.x;x<RU_y.x;x--)
    	{
    		pt1=(unsigned char*)(temp1->imageData+x
    			+((int)(k_heng[1]*(x-LU_y.x))+LU_y.y)*temp1->widthStep);
    		for(int m_y=0;m_y<LU_x.y-LD_x.y;m_y++)
    		{
    			*(pt1+m_y*shu)
    		}
    	}
    }
    
    
	
	
	cvReleaseImage(&gray1);
	cvReleaseImage(&temp1);
	cvReleaseImage(&temp2);
	cvReleaseMemStorage(&storage);
}*/

void hc_marathon_international_lubiao3(IplImage*src,IplImage*res,double*init_data,double*res_data)
{
	IplImage* gray1=cvCreateImage(cvGetSize(src),8,1);
	IplImage* temp1=cvCreateImage(cvGetSize(src),8,1);
	IplImage* temp2=cvCreateImage(cvGetSize(src),8,1);
	unsigned char*pg1,*pt1,*pt2,*pr;
	
	cvCvtColor(src,gray1,CV_BGR2GRAY);
	
	Border*border=new Border(gray1);
	border->find_border1(temp1);
	delete border;
	
	
	//通过阈值找图标，外框和背景色差大就取外框，否则就取框内的图标。设置ROI
	for(int y=0;y<temp1->height;y++)
	{
		pt1=(unsigned char*)(temp1->imageData+y*temp1->widthStep);
		pt2=(unsigned char*)(temp2->imageData+y*temp2->widthStep);
		for(int x=0;x<temp1->width;x++)
		{
			if(pt1[x]>=init_data[0])
			{
				pt2[x]=255;
			}
			else
			{
				pt2[x]=0;
			}
		}
	}
	
	cvDilate(temp2,temp2,0,3);
	cvCvtColor(temp2,res,CV_GRAY2BGR);
	
	CBlobResult blobs;
	CBlob *blob;
	CvRect rect;
	
	
	
	blobs = CBlobResult(temp2,0,0);
	
	blobs.Filter(
		blobs,
		B_EXCLUDE, 
		CBlobGetArea(), 
		B_LESS,
		100
	);
	
	int num_blobs = blobs.GetNumBlobs();
	
	if(num_blobs==0)
	{
		res_data[0]=0;
		cvReleaseImage(&gray1);
		cvReleaseImage(&temp1);
		cvReleaseImage(&temp2);
		return;
	}
	
	for(int i=0; i<num_blobs; i++) 
	{
		blob = blobs.GetBlob(i);
		int max_area=0,area=0;
		area=blob->Area();
		
		
		if(area>max_area) 
		{
			max_area=area;
			rect = blob->GetBoundingBox();
			
		}
	}
	
	
	cvRectangle(res,cvPoint(rect.x,rect.y)
					,cvPoint(rect.x+rect.width,rect.y+rect.height)
					,cvScalar(0,0,255),3);
					
					
	res_data[0]=1;
	cvReleaseImage(&gray1);
	cvReleaseImage(&temp1);
	cvReleaseImage(&temp2);
					
}




int main()
{
	char file[100];
	
	IplImage *src,*dst,*resize,*hsv;
	IplImage *thresh_dst;
	IplImage*gray=cvCreateImage(cvSize(320,240),8,1);
	IplImage*res=cvCreateImage(cvSize(320,240),8,3);
	
	int thresh[6]={100,120,150,255,0,255};
	double a[2];
	double b[2];
	a[0]=250;
	for(int i=1;i<=6800;++i)
	{
		cvZero(res);
		sprintf(file,"pic_lubiao3/%04d.bmp",i);
		printf("%s\n",file);
		src=cvLoadImage(file);
		
		
		cvNamedWindow("src");
		cvShowImage("src",src);
		hc_marathon_international_lubiao3(src,res,a,b);
		cvNamedWindow("res");
		cvShowImage("res",res);
		cvWaitKey(0);
		
	}
	return 0;
}



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
