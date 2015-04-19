#include<imgpro.h>

///Base
Base::Base()
{
	src=0;
};

Base::Base(IplImage*src)
{
	this->src=src;
};

void Base::loadImgSrc(IplImage*src)
{
	this->src=src;
};


///Border
Border::Border(IplImage*src):Base(src)
{

};

int Border::find_border1(IplImage*dst)
{
	if(dst==0||src==0)
		return -1 ;
	if(dst->width!=src->width
		||dst->height!=src->height
		||dst->widthStep!=src->widthStep)
		return -2 ;
	
	float a[9]={1.0,2.0,1.0,
				0.0,0.0,0.0,
				-1.0,-2.0,-1.0};
	float b[9]={-1.0,0.0,1.0,
				-2.0,0.0,2.0,
				-1.0,0.0,1.0};
	float c[9]={-1.0,-2.0,-1.0,
				0.0,0.0,0.0,
				1.0,2.0,1.0};
	float d[9]={1.0,0.0,-1.0,
				2.0,0.0,-2.0,
				1.0,0.0,-1.0};			
				
	CvMat k=cvMat(3,3,CV_32FC1,a);
	CvMat k2=cvMat(3,3,CV_32FC1,b);
	CvMat k3=cvMat(3,3,CV_32FC1,c);
	CvMat k4=cvMat(3,3,CV_32FC1,d);
	IplImage *tmp1,*tmp2,*tmp3,*tmp4;
	
	tmp1=cvCreateImage(cvGetSize(src),8,1);
	tmp2=cvCreateImage(cvGetSize(src),8,1);
	tmp3=cvCreateImage(cvGetSize(src),8,1);
	tmp4=cvCreateImage(cvGetSize(src),8,1);

	
	cvFilter2D( src, tmp1,
                  &k,
                 cvPoint(-1,-1));
    cvFilter2D( src, tmp2,
                  &k2,
                 cvPoint(-1,-1));
    cvFilter2D( src, tmp3,
                  &k3,
                 cvPoint(-1,-1));
    cvFilter2D( src, tmp4,
                  &k4,
                 cvPoint(-1,-1));
                 
    unsigned char *p1,*p2,*p3,*p4,*p5;
    
    for(int y=0;y<src->height;y++)
    {
    	p1=(unsigned char*)(tmp1->imageData+y*tmp1->widthStep);
    	p2=(unsigned char*)(tmp2->imageData+y*tmp2->widthStep);
    	p3=(unsigned char*)(tmp3->imageData+y*tmp3->widthStep);
    	p4=(unsigned char*)(tmp4->imageData+y*tmp4->widthStep);
    	p5=(unsigned char*)(dst->imageData+y*dst->widthStep);
    	for(int x=0;x<src->width;x++)
    	{
    		if((int)p1[x]+(int)p2[x]+(int)p3[x]+(int)p4[x]<=255
    			&&(int)p1[x]+(int)p2[x]+(int)p3[x]+(int)p4[x]>=0)
    			p5[x]=p1[x]+p2[x]+p3[x]+p4[x];
    		if((int)p1[x]+(int)p2[x]+(int)p3[x]+(int)p4[x]>255)
    			p5[x]=255;
    		//if((int)p1[x]+(int)p2[x]<0)
    		//	p5[x]=0;
    	}
    }
   
   cvReleaseImage(&tmp1);
   cvReleaseImage(&tmp2);
   cvReleaseImage(&tmp3);
   cvReleaseImage(&tmp4);
   
   return 0;
}

///CannelSplit
ChannelSplit::ChannelSplit(IplImage*src):Base(src)
{

}

int ChannelSplit::Channel3to1(IplImage*dst,int channelNum)
{
	if(channelNum>2||channelNum<0)
		return -1;
	
	unsigned char* psrc,*pdst;
	for(int y=0;y<src->height;++y)
	{
		psrc=(unsigned char*)(src->imageData+y*src->widthStep);
		pdst=(unsigned char*)(dst->imageData+y*dst->widthStep);
		for(int x=0;x<src->width;++x)
		{
			pdst[x]=psrc[x*3+channelNum];
		}
	}
	
	return 0;
}


///Corner
Corner::Corner(IplImage*src):Base(src)
{

}

int Corner::find_corner1(IplImage*dst)
{

}



///Thin
Thin::Thin(IplImage*src):Base(src)
{

}

void Thin::scantable()
{
//	assert(src->nChannels==1);  
    int scan[8] = {0};  
    for(int h=1;h<(src->height-1);h++)  
    {  
        for(int w=1;w<(src->width-1);w++)  
        {  
            int index = 0;  
            if(*(src->imageData+(h)*src->widthStep+w)!=0)  
            {  
            if(*(src->imageData+(h-1)*src->widthStep+w-1)==0)  
                scan[0] = 1;  
            else  
                scan[0] = 0;  
            if(*(src->imageData+(h-1)*src->widthStep+w)==0)  
                scan[1] = 1;  
            else  
                scan[1] = 0;  
            if(*(src->imageData+(h-1)*src->widthStep+w+1)==0)  
                scan[2] = 1;  
            else  
                scan[2] = 0;  
            if(*(src->imageData+(h)*src->widthStep+w-1)==0)  
                scan[3] = 1;  
            else  
                scan[3] = 0;  
            if(*(src->imageData+(h)*src->widthStep+w+1)==0)  
                scan[4] = 1;  
            else  
                scan[4] = 0;  
            if(*(src->imageData+(h+1)*src->widthStep+w-1)==0)  
                scan[5] = 1;  
            else  
                scan[5] = 0;  
            if(*(src->imageData+(h+1)*src->widthStep+w)==0)  
                scan[6] = 1;  
            else  
                scan[6] = 0;  
            if(*(src->imageData+(h+1)*src->widthStep+w+1)==0)  
                scan[7] = 1;  
            else  
                scan[7] = 0;  
         
  
            for(int i=0;i<8;i++)  
            {  
                index += scan[i]*npow(i);  
            }  
          //  printf("%d\n" ,index);  
            if(erasetable[index] == 1)  
            {  
                //printf("%d\n" , erasetable[index]);  
                *(src->imageData+h*src->widthStep+w) = 0;  
            }  
            }  
  
        }  
    }  
}


///ImgPro

ImgPro::ImgPro(IplImage*src):Base(src)
{

}
///
int ImgPro::myFlood1(IplImage*src)
{
	unsigned char* psrc;
	int color=0;
	for(int y=1;y<src->height;++y)
	{
		psrc=(unsigned char*)(src->imageData+y*src->widthStep);
		
		for(int x=1;x<src->width;++x)
		{
			if(psrc[x]==0)
			{
				color++;
				cvFloodFill(src,cvPoint(x,y),cvScalar(color),cvScalar(0),cvScalar(0));
			}
		}
	}
	return color;
}

void ImgPro::find_lower(int*thresh,IplImage*dst)
{
	IplImage *temp1,*temp2,*temp3,*temp4,*temp5;
	
	temp1=cvCreateImage(cvGetSize(src),8,3);
	temp2=cvCreateImage(cvGetSize(src),8,1);
	temp3=cvCreateImage(cvGetSize(src),8,1);
	temp4=cvCreateImage(cvGetSize(src),8,1);
	temp5=cvCreateImage(cvGetSize(src),8,1);
	cvCvtColor(src,temp1,CV_BGR2HSV);
	ChannelSplit *channelH=new ChannelSplit(temp1);
	channelH->Channel3to1(temp2,0);
	
	

	
	
	
	
	
	
	Border *border=new Border(temp2);
	
	border->find_border1(temp3);
	
	cvSmooth(temp3,temp3);
	
	WitFindColor *findcolor=new WitFindColor(temp3,temp4,20,255);
	
	findcolor->findByGRAY2GRAY();
	
	cvDilate(temp4,temp4,0,2);
	cvErode(temp4,temp4,0,2);
	
	cvSmooth( temp4, temp5,CV_MEDIAN,3,3);
	
	cvDilate(temp5,temp5,0,2);
	cvErode(temp5,temp5,0,1);
	cvRectangle(temp5,cvPoint(0,0),cvPoint(temp5->width,temp5->height),cvScalar(255),3);
	int blobNum=myFlood1(temp5);
	printf("%d\n",blobNum);
	Blob_FindColor *b_findcolor=new Blob_FindColor(blobNum,temp5);
	b_findcolor->loadThresh(thresh);
	b_findcolor->findByHSV2GRAY(temp5,dst);
//	cvCopy(temp5,dst);
	cvNamedWindow("3");
	cvShowImage("3",temp3);
		

	    
	
		
	
	cvReleaseImage(&temp1);
	cvReleaseImage(&temp2);
	cvReleaseImage(&temp3);
	cvReleaseImage(&temp4);
	cvReleaseImage(&temp5);
	delete channelH;
	delete border;
	delete findcolor;
		
}


ThreshAdaptive::ThreshAdaptive(IplImage*src):Base(src)
{
	
}

void ThreshAdaptive::run(int*thresh)
{
	IplImage *temp1,*temp2,*temp3,*temp4,*temp5,temp6;
	
	temp1=cvCreateImage(cvGetSize(src),8,3);
	temp2=cvCreateImage(cvGetSize(src),8,1);
	temp3=cvCreateImage(cvGetSize(src),8,1);
	temp4=cvCreateImage(cvGetSize(src),8,1);
	temp5=cvCreateImage(cvGetSize(src),8,1);
	temp6=cvCreateImage(cvGetSize(src),8,1);
	cvCvtColor(src,temp1,CV_BGR2HSV);
	ChannelSplit *channelH=new ChannelSplit(temp1);
	channelH->Channel3to1(temp2,0);
	
	

	
	
	cvSmooth(temp2,temp2);
	
	
	
	Border *border=new Border(temp2);
	
	border->find_border1(temp3);
	
	cvDilate(temp3,temp3,0,1);
	cvErode(temp3,temp3,0,1);
	cvDilate(temp3,temp3,0,1);
	cvErode(temp3,temp3,0,1);
	
	cvNamedWindow("ThreshAdaptive1");
	cvShowImage("ThreshAdaptive1",temp3);
	
	Border *border2=new Border(temp3);
	
	
	
	border2->find_border1(temp4);
	
	Statistics*statistics=new Statistics(temp4);
	
	statistics->run();
	
	
	WitFindColor *findcolor=new WitFindColor(temp4,temp5,90,255);
	
	findcolor->findByGRAY2GRAY();
	
	cvDilate(temp5,temp5,0,2);
	cvErode(temp5,temp5,0,2);
	
	cvNamedWindow("ThreshAdaptive2");
	cvShowImage("ThreshAdaptive2",temp4);
	
	cvNamedWindow("ThreshAdaptive3");
	cvShowImage("ThreshAdaptive3",temp5);
	
	WitFindColor *findcolor_src=new WitFindColor(temp1,temp6);
	
	findcolor_src->loadThreshold(int*thresh);
	
	findcolor_src->findByHSV2GRAY();
	
	
	cvReleaseImage(&temp1);
	cvReleaseImage(&temp2);
	cvReleaseImage(&temp3);
	cvReleaseImage(&temp4);
	cvReleaseImage(&temp5);
	delete channelH;
	delete border;
	delete border2;
	delete findcolor;
	delete findcolor_src;
	delete statistics;
	
}


void ThreshAdaptive::run_canny(int *thresh)
{
	IplImage *temp1,*temp2,*temp3,*temp4,*temp5,*temp6;
	
	temp1=cvCreateImage(cvGetSize(src),8,3);
	temp2=cvCreateImage(cvGetSize(src),8,1);
	temp3=cvCreateImage(cvGetSize(src),8,1);
	temp4=cvCreateImage(cvGetSize(src),8,1);
	temp5=cvCreateImage(cvGetSize(src),8,1);
	temp6=cvCreateImage(cvGetSize(src),8,1);
	cvCvtColor(src,temp1,CV_BGR2HSV);
	ChannelSplit *channelH=new ChannelSplit(temp1);
	channelH->Channel3to1(temp2,0);
	
	cvNamedWindow("ThreshAdaptive1");
	cvShowImage("ThreshAdaptive1",temp2);
	
	cvSmooth(temp2,temp2);
	cvSmooth(temp2,temp2);
	cvSmooth(temp2,temp2);
	cvCanny(temp2,temp3,160,255,5);
	
	
	cvDilate(temp3,temp3,0,2);
	cvErode(temp3,temp3,0,2);
	
	
	
	
	Border *border=new Border(temp2);
	
	border->find_border1(temp4);
	
	
	
	cvNamedWindow("ThreshAdaptive2");
	cvShowImage("ThreshAdaptive2",temp3);
	
	cvNamedWindow("ThreshAdaptive3");
	cvShowImage("ThreshAdaptive3",temp4);
	
	
	WitFindColor *findcolor_src=new WitFindColor(temp1,temp5);
	
	findcolor_src->loadThreshold(int*thresh);
	
	findcolor_src->findByHSV2GRAY();
	
	
	CBlobResult blobs;
	
	CBlob *blob;
	
	blobs=CBlobResult(temp3, NULL, 255);
	
	blobs.Filter(
		low_blobs, 
		B_EXCLUDE, 
		CBlobGetArea(), 
		B_LESS, 
		20
	);
	
	int num_blobs = blobs.GetNumBlobs();
	
	int * num_colors=new int[num_blobs+1];
	
	for(int i=0;i<num_blobs;i++)
	{
		num_colors[i]=0;
	}
	
	if(num_blobs>100)
	{
		goto f1;
	}
	
	cvZero(temp6);
	
	for(int i=0;i<num_blobs;i++)
	{
		blob=blobs.GetBlob(i);
		
		blob.FillBlobs(temp6,cvScalar(i+1));
		
		
		
	}

	unsigned char*pt5,*pt6;

	for(int y=0;y<temp5->height;y++)
	{
		pt5=(unsigned char*)(temp5->imageData+y*temp5->widthStep);
		pt6=(unsigned char*)(temp6->imageData+y*temp6->widthStep);
		for(int x=0;x<temp5->width;x++)
		{
			if(pt5[x]==255)
			{
				num_colors[pt6[x]]++;
			}
		}
	}
	
	
	bool * catch_colors=new bool[num_blobs+1];
	
	for(int i=0;i<num_blobs;i++)
	{
		catch_blobs[i]=0;
	}
	
	for(int i=1;i<num_blobs;i++)
	{
		if((double)num_colos[i]/blobs.GetBlob(i-1).Area()>0.7)
		{
			catch_blobs[i]=1;
		}
	}
	
	
	unsigned char* psrc;
	
	int maxH=0,minH=180,maxS=0,minS=255,maxV=0,minV=255;
	
	if(thresh[0]<=thresh[1])
	{
	
		for(int y=0;y<temp5->height;y++)
		{
			psrc=(unsigned char*)(src->imageData+y*src->widthStep);
			pt6=(unsigned char*)(temp6->imageData+y*temp6->widthStep);
			for(int x=0;x<temp5->width;x++)
			{
				if(catch_blobs[pt6[x]])
				{
					if(psrc[3*x+0]>maxH)
						maxH=psrc[3*x+0];
					if(psrc[3*x+0]<minH)
						minH=psrc[3*x+0];
					if(psrc[3*x+1]>maxS)
						maxS=psrc[3*x+1];
					if(psrc[3*x+1]<minS)
						minS=psrc[3*x+1];
					if(psrc[3*x+2]>maxV)
						maxV=psrc[3*x+2];
					if(psrc[3*x+2]<minV)
						minV=psrc[3*x+2];
				}
			}
		}
		if(maxH-minH>90)
		{
			int temp=minH;
			minH=maxH;
			maxH=temp;
		}
	}
	else
	{
		for(int y=0;y<temp5->height;y++)
		{
			psrc=(unsigned char*)(src->imageData+y*src->widthStep);
			pt6=(unsigned char*)(temp6->imageData+y*temp6->widthStep);
			for(int x=0;x<temp5->width;x++)
			{
				if(catch_blobs[pt6[x]])
				{
					if(psrc[3*x+0]>maxH)
						maxH=psrc[3*x+0];
					if(psrc[3*x+0]<minH)
						minH=psrc[3*x+0];
					if(psrc[3*x+1]>maxS)
						maxS=psrc[3*x+1];
					if(psrc[3*x+1]<minS)
						minS=psrc[3*x+1];
					if(psrc[3*x+2]>maxV)
						maxV=psrc[3*x+2];
					if(psrc[3*x+2]<minV)
						minV=psrc[3*x+2];
				}
			}
		}
		if(maxH-minH>90)
		{
			int temp=minH;
			minH=maxH;
			maxH=temp;
		}
	}
	
	
	
	
	
	
	delete catch_colors;

f1:	
	
	cvReleaseImage(&temp1);
	cvReleaseImage(&temp2);
	cvReleaseImage(&temp3);
	cvReleaseImage(&temp4);
	cvReleaseImage(&temp5);
	cvReleaseImage(&temp6);
	delete channelH;
	delete border;
	delete findcolor_src;
	delete num_colors;
	
}


Statistics::Statistics(IplImage*src):Base(src)
{
	data=new int[256];
}

void Statistics::run()
{
	for(int i=0;i<=255;i++)
		data[i]=0;
	unsigned char *p;
	for(int y=0;y<src->height;y++)
	{
		p=(unsigned char*)(src->imageData+y*src->widthStep);
		for(int x=0;x<src->width;x++)
		{
			data[p[x]]++;
		}
	}
	
	show();
	
}




void Statistics::show()
{
	IplImage*img=cvCreateImage(cvSize(256,256),8,1);
	
	cvZero(img);
	
	int max=0;
	for(int i=0;i<=255;i++)
	{
		if(data[i]>max)
			max=data[i];
		
	}
	
	if(max==0)
	{
		
		cvReleaseImage(&img);
		return;
	}
	printf("max:%d\n",max);
	for(int i=0;i<=255;i++)
	{
		data[i]=data[i]*255/max;
	}
	printf("222222222\n");
	int Y[256];
	
	for(int i=0;i<=255;i++)
	{
		Y[i]=255-data[i];
	}
	printf("33333333\n");
	unsigned char*p=(unsigned char*)img->imageData;
	
	for(int x=0;x<=255;x++)
	{
		
		for(int i=0;i<Y[x];i++)
			p[x+i*img->widthStep]=255;
		
		
	}
	
	printf("44444444\n");
	cvNamedWindow("Statistics");
	cvShowImage("Statistics",img);
	
	
	
	
	cvReleaseImage(&img);
}

