#include"findcolor.h"


WitFindColor::WitFindColor(WitFindColor & last)
{
	this->channel1min=last.channel1min;
	this->channel1max=last.channel1max;
	this->channel2min=last.channel2min;
	this->channel2max=last.channel2max;
	this->channel3min=last.channel3min;
	this->channel3max=last.channel3max;
	this->src=last.src;
	this->dst=last.dst;
}

void WitFindColor::findByBGR2BGR(const int* setColor){
	unsigned char *psrc,*pdst;
	pointNum=0;
	sumX=sumY=0;
	for(int y=0;y<src->height;++y){
		psrc=(unsigned char *)(src->imageData+y*src->widthStep);
		pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);
		for(int x=0;x<src->width;++x){
			if(psrc[3*x]<=channel1max&&psrc[3*x]>=channel1min
			&&psrc[3*x+1]<=channel2max&&psrc[3*x+1]>=channel2min
			&&psrc[3*x+2]<=channel3max&&psrc[3*x+2]>=channel3min)
			{
				pdst[3*x]=setColor[0];
				pdst[3*x+1]=setColor[1];
				pdst[3*x+2]=setColor[2];
				pointNum++;
				sumX+=x;
				sumY+=y;
			}

		}
	}
	if(pointNum==0)
	{
		averagePoint.x=-1;
		averagePoint.y=-1;
	}
	else
	{
	averagePoint.x=sumX/pointNum;
	averagePoint.y=sumY/pointNum;
	}
}


void WitFindColor::findByBGR2GRAY(){
	unsigned char *psrc,*pdst;
	pointNum=0;
	sumX=sumY=0;
	for(int y=0;y<src->height;++y){
		psrc=(unsigned char *)(src->imageData+y*src->widthStep);
		pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);
		for(int x=0;x<src->width;++x){
			if(psrc[3*x]<=channel1max&&psrc[3*x]>=channel1min
			&&psrc[3*x+1]<=channel2max&&psrc[3*x+1]>=channel2min
			&&psrc[3*x+2]<=channel3max&&psrc[3*x+2]>=channel3min)
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
	if(pointNum==0)
	{
		averagePoint.x=-1;
		averagePoint.y=-1;
	}
	else
	{
	averagePoint.x=sumX/pointNum;
	averagePoint.y=sumY/pointNum;
	}
}


void WitFindColor::findByGRAY2GRAY()
{
	unsigned char *psrc,*pdst;
	pointNum=0;
	sumX=sumY=0;
	for(int y=0;y<src->height;++y){
		psrc=(unsigned char *)(src->imageData+y*src->widthStep);
		pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);
		for(int x=0;x<src->width;++x){
			if(psrc[x]<=channel1max&&psrc[x]>=channel1min)
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
	if(pointNum==0)
	{
		averagePoint.x=-1;
		averagePoint.y=-1;
	}
	else
	{
	averagePoint.x=sumX/pointNum;
	averagePoint.y=sumY/pointNum;
	}
}


void WitFindColor::findByHSV2BGR(const int* setColor)
{
	unsigned char *psrc,*pdst;
	pointNum=0;
	sumX=sumY=0;
	if(channel1max>=channel1min){
		for(int y=0;y<src->height;++y){
			psrc=(unsigned char *)(src->imageData+y*src->widthStep);
			pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);	
			for(int x=0;x<src->width;++x){
				if(psrc[3*x]<=channel1max&&psrc[3*x]>=channel1min
				&&psrc[3*x+1]<=channel2max&&psrc[3*x+1]>=channel2min
				&&psrc[3*x+2]<=channel3max&&psrc[3*x+2]>=channel3min)
				{
					pdst[3*x]=setColor[0];
					pdst[3*x+1]=setColor[1];
					pdst[3*x+2]=setColor[2];
					pointNum++;
					sumX+=x;
					sumY+=y;
				}
				
			}
		}
	}
	else{
		for(int y=0;y<src->height;++y){
			psrc=(unsigned char *)(src->imageData+y*src->widthStep);
			pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);	
			for(int x=0;x<src->width;++x)
			{
				if(((psrc[3*x]<=channel1max&&psrc[3*x]>=0)||(psrc[3*x]>=channel1min&&psrc[3*x]<=180))
					&&psrc[3*x+1]<=channel2max&&psrc[3*x+1]>=channel2min
					&&psrc[3*x+2]<=channel3max&&psrc[3*x+2]>=channel3min)
				{
					pdst[3*x]=setColor[0];
					pdst[3*x+1]=setColor[1];
					pdst[3*x+2]=setColor[2];
					pointNum++;
					sumX+=x;
					sumY+=y;
				}

			}
		}
	}
	if(pointNum==0)
	{
		averagePoint.x=-1;
		averagePoint.y=-1;
	}
	else
	{
	averagePoint.x=sumX/pointNum;
	averagePoint.y=sumY/pointNum;
	}
}


void WitFindColor::findByHSV2GRAY()
{
	unsigned char *psrc,*pdst;
	pointNum=0;
	sumX=sumY=0;
	if(channel1max>=channel1min){
		for(int y=0;y<src->height;++y){
			psrc=(unsigned char *)(src->imageData+y*src->widthStep);
			pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);	
			for(int x=0;x<src->width;++x){
				if(psrc[3*x]<=channel1max&&psrc[3*x]>=channel1min
				&&psrc[3*x+1]<=channel2max&&psrc[3*x+1]>=channel2min
				&&psrc[3*x+2]<=channel3max&&psrc[3*x+2]>=channel3min)
				{
					pdst[x]=255;
					pointNum++;
					sumX+=x;
					sumY+=y;
				}
				else{
					pdst[x]=0;
				}
			}
		}
	}
	else{
		for(int y=0;y<src->height;++y){
			psrc=(unsigned char *)(src->imageData+y*src->widthStep);
			pdst=(unsigned char *)(dst->imageData+y*dst->widthStep);	
			for(int x=0;x<src->width;++x)
			{
				if(((psrc[3*x]<=channel1max&&psrc[3*x]>=0)||(psrc[3*x]>=channel1min&&psrc[3*x]<=180))
					&&psrc[3*x+1]<=channel2max&&psrc[3*x+1]>=channel2min
					&&psrc[3*x+2]<=channel3max&&psrc[3*x+2]>=channel3min)
				{
					pdst[x]=255;
					pointNum++;
					sumX+=x;
					sumY+=y;
				}
				else{
					pdst[x]=0;
				}
			}
		}
	}
	if(pointNum==0)
	{
		averagePoint.x=-1;
		averagePoint.y=-1;
	}
	else
	{
	averagePoint.x=sumX/pointNum;
	averagePoint.y=sumY/pointNum;
	}
}



void WitFindColor::loadImage(IplImage*src,IplImage*dst)
{
	this->src=src;
	this->dst=dst;
}


void WitFindColor::loadImageDst(IplImage*dst)
{
	this->dst=dst;
}

void WitFindColor::loadImageSrc(IplImage*src)
{
	this->src=src;
}


void WitFindColor::loadThreshold(int* threshold)
{
	channel1min=threshold[0];
	channel1max=threshold[1];
	channel2min=threshold[2];
	channel2max=threshold[3];
	channel3min=threshold[4];
	channel3max=threshold[5];
}


inline CvPoint WitFindColor::returnAveragePoint()
{
	return averagePoint;
}


inline int WitFindColor::returnPointNum()
{
	return pointNum;
}


WitThreshold::WitThreshold()
{
	

	H12_H=new int[255];
	H12_1=new int[255];
	H12_2=new int[255];
	y_H=new int[255];
	for(int i=0;i<255;++i){
		H12_H[i]=0;
		H12_1[i]=0;
		H12_2[i]=0;
	}
	for(int i=0;i<NUM;i++){
		dataH[i]=-1;
		dataS[i]=-1;
		dataV[i]=-1;
		dataInH[i]=-1;
		dataInS[i]=-1;
		dataInV[i]=-1;
	}
	
}

void WitThreshold::AIchangeThresholdBW()
{
	if(control[0]==1)
		Light=(averageB+averageW)/2;
}


void WitThreshold::AIchangeThresholdH()
{
	if(control[0]==0)
		return;
	int thisAverageH;
	int	thisAverageInH;//ÕâÒ»´ÎµÄdataInHÊý×éÀïÃæËùÓÐÊý¾ÝµÄÆ½¾ùÖµ
	int add=0;
	int addIn=0;


	for(int i=NUM-1;i>0;i--)
	{
		dataH[i]=dataH[i-1];
		dataInH[i]=dataInH[i-1];
	}

	
	dataH[0]=averageH;
	dataInH[0]=averageInH;

	for(int i=0; i<NUM;++i)
	{
		if(dataH[i]<0||dataInH[i]<0)
			return;
	}

		for(int i=0;i<NUM;++i)
	{
		add+=dataH[i];
		addIn+=dataInH[i];
	}
	thisAverageH=add/NUM;
	thisAverageInH=addIn/NUM;
	
	//if(Hmax>=Hmin)//Èç¹û±ä»¯¹ý´ó£¬ÔòÅÅ³ý´Ë´ÎÑ¡Ïî¡£
	//	if(thisAverageInH-averageInH>(Hmax-Hmin)/2)
	//		return;
	//if(Hmax<Hmin)
	//	if(thisAverageInH-averageInH>(Hmax+180-Hmin)/2)
	//		return;

	int t=averageInH-thisAverageInH;
	if(Hmax>=Hmin)
	{
		int max=Hmax;
		int min=Hmin;
		if(t>0)
		{
			
			for(int i=0;i<t;i++)
			{
				if(max+i<=180)
				{
					if(H12_H[max+i]<H12_H[Hmax])Hmax=max+i;
					if(H12_H[min+i]<H12_H[Hmin])Hmin=min+i;
				}
				else
				{
					if(H12_H[max+i-180]<H12_H[Hmax])Hmax=max+i-180;
					if(H12_H[min+i]<H12_H[Hmin])Hmin=min+i;
				}
			}
		}
		if(t<0)
		{
			for(int i=0;i>t;i--)
			{
				if(min+t>=0)
				{
					if(H12_H[max+i]<H12_H[Hmax])Hmax=max+i;
					if(H12_H[min+i]<H12_H[Hmin])Hmin=min+i;
				}
				else
				{
					if(H12_H[max+i]<H12_H[Hmax])Hmax=max+i;
					if(H12_H[min+i+180]<H12_H[Hmin])Hmin=min+i+180;
				}
			}
		}
	}
	
	
	if(Hmax<Hmin)
	{
		int max=Hmax;
		int min=Hmin;
		if(t>0)
		{
			for(int i=0;i<t;i++)
			{
				if(min+i<=180)
				{
					if(H12_H[max+i]<H12_H[Hmax])Hmax=max+i;
					if(H12_H[min+i]<H12_H[Hmin])Hmin=min+i;
				}
				else
				{
					if(H12_H[max+i]<H12_H[Hmax])Hmax=max+i;
					if(H12_H[min+i-180]<H12_H[Hmin])Hmin=min+i-180;
				}
			}
		}
		if(t<0)
		{
			for(int i=0;i>t;i--)
			{
				if(max+i>=0)
				{
					if(H12_H[max+i]<H12_H[Hmax])Hmax=max+i;
					if(H12_H[min+i]<H12_H[Hmin])Hmin=min+i;
				}
				else
				{
					if(H12_H[max+i+180]<H12_H[Hmax])Hmax=max+i+180;
					if(H12_H[min+i]<H12_H[Hmin])Hmin=min+i;
				}
			}
		}
	}
//	cvSetTrackbarPos("Hmax","trackbar",Hmax);
//	cvSetTrackbarPos("Hmin","trackbar",Hmin);
	//cvSetTrackbarPos("Smax","trackbar",Smax);
	//cvSetTrackbarPos("Smin","trackbar",Smin);
	//cvSetTrackbarPos("Vmax","trackbar",Vmax);
	//cvSetTrackbarPos("Vmin","trackbar",Vmin);
}


void WitThreshold::AIchangeThresholdHSVbyConstLongLimit(bool isAI_H=0,bool isAI_S=0,bool isAI_V=0)
{
	if(control[0]==0)
		return;
	if(isAI_H==1)
	{	
		if(limitHmax>=limitHmin)
		{
			
			
				if(averageInH+longH/2<=limitHmax)
					Hmax=averageInH+longH/2;
				else Hmax=limitHmax;
			
			
			
				if(averageInH-longH/2>=limitHmin)
					Hmin=averageInH-longH/2;
				else Hmin=limitHmin;
			
		}
		else	//limitHmax<limitHmin
		{
			
			if(averageInH>=Hmin)
			{
				//Hmax
				if(averageInH+longH/2>180)
				{
					if(averageInH+longH/2-180<=limitHmax)
						Hmax=averageInH+longH/2-180;
					else Hmax=limitHmax;
				}
				else Hmax=averageInH+longH/2;
				//Hmin
				if(averageInH-longH/2>=limitHmin)
					Hmin=averageInH-longH/2;
				else Hmin=limitHmin;
			}
			if(averageInH<=Hmax)
			{
				//Hmin
				if(averageInH-longH/2<0)
				{
					if(averageInH-longH/2+180>=limitHmin)
						Hmin=averageInH-longH/2+180;
					else Hmin=limitHmin;
				}
				else Hmin=averageInH-longH/2;
				//Hmax
				if(averageInH+longH/2<=limitHmax)
					Hmax=averageInH+longH/2;
				else Hmax=limitHmax;
			}
		}
	}
	if(isAI_S==1)
	{
		if(averageInS+long1/2<=limitSmax)Smax=averageInS+long1/2;
		else Smax=limitSmax;
		if(averageInS-long1/2>=limitSmin)Smin=averageInS-long1/2;
		else Smin=limitSmin;
	}
	if(isAI_V==1)
	{
		if(averageInV+long2/2<=limitVmax)Vmax=averageInV+long2/2;
		else Vmax=limitVmax;
		if(averageInV-long2/2>=limitVmin)Vmin=averageInV-long2/2;
		else Vmin=limitVmin;
	}
//	cvSetTrackbarPos("Hmax","trackbar",Hmax);
//	cvSetTrackbarPos("Hmin","trackbar",Hmin);
//	cvSetTrackbarPos("Smax","trackbar",Smax);
//	cvSetTrackbarPos("Smin","trackbar",Smin);
//	cvSetTrackbarPos("Vmax","trackbar",Vmax);
//	cvSetTrackbarPos("Vmin","trackbar",Vmin);
}


void WitThreshold::AIsetLimit()
{
	if(control[2]==1)
	{
		if(Hmax+longH<=180)limitHmax=Hmax+longH;
		else limitHmax=Hmax+longH-180;
		if(Hmin-longH>=0)limitHmin=Hmin-longH;
		else limitHmin=Hmin-longH+180;
		
		if(Smax+long1<255)limitSmax=Smax+long1;
		else limitSmax=255;
		if(Smin-long1>0)limitSmin=Smin-long1;
		else limitSmin=0;
		
		if(Vmax+long2<255)limitVmax=Vmax+long2;
		else limitVmax=255;
		if(Vmin-long2>0)limitVmin=Vmin-long2;
		else limitVmin=0;
		
		control[2]=0;
	}
}

void WitThreshold::AIsetLong()
{
	if(control[1]==1)
	{
		if(Hmax>=Hmin)
		{
			longH=Hmax-Hmin;
		}
		else longH=Hmin-Hmax;
		
		long1=3*(Smax-Smin);
		long2=5*(Vmax-Vmin);
		
		control[1]=0;
	}
}


WitThreshold::WitThreshold(WitThreshold&last)
{
	

	H12_H=new int[255];
	H12_1=new int[255];
	H12_2=new int[255];
	y_H=new int[255];
	for(int i=0;i<255;++i){
		H12_H[i]=last.H12_H[i];
		H12_1[i]=last.H12_1[i];
		H12_2[i]=last.H12_2[i];
	}
	for(int i=0;i<NUM;++i){
		dataH[i]=last.dataH[i];
		dataS[i]=last.dataS[i];
		dataV[i]=last.dataV[i];
		dataInH[i]=last.dataInH[i];
		dataInS[i]=last.dataInS[i];
		dataInV[i]=last.dataInV[i];
	}
	
	
}


void WitThreshold::loadControl(int*control)
{
		if(control==0)return;
		this->control=control;
}

void WitThreshold::loadImage(IplImage*srcHSV){

	this->srcHSV=srcHSV;
}


void WitThreshold::loadLongH12(int*longH12)
{
	if(longH12==0)return;
	longH=longH12[0];
	long1=longH12[1];
	long2=longH12[2];
}


void WitThreshold::loadThresholdBWmainB(int*threshold)
{
	
	Light=threshold[1];
}

void WitThreshold::loadThresholdHSV(int*threshold)
{
	Hmin=threshold[0];
	Hmax=threshold[1];
	Smin=threshold[2];
	Smax=threshold[3];
	Vmin=threshold[4];
	Vmax=threshold[5];
}

void WitThreshold::loadThresholdLimit(int*limit)
{
	if(limit==0)return;
	limitHmin=limit[0];
	limitHmax=limit[1];
	limitSmin=limit[2];
	limitSmax=limit[3];
	limitVmin=limit[4];
	limitVmax=limit[5];
}


void WitThreshold::returnThresholdBWmainB(int *threshold)
{
	threshold[0]=0;
	threshold[1]=Light;
}


void WitThreshold::returnThresholdHSV(int*threshold)
{
	threshold[0]=Hmin;
	threshold[1]=Hmax;
	threshold[2]=Smin;
	threshold[3]=Smax;
	threshold[4]=Vmin;
	threshold[5]=Vmax;
}


void WitThreshold::valueStatisBW()
{
	unsigned char * psrc;
	int addB=0,addW=0;
	int numB=0,numW=0;
	for(int i=0;i<255;++i){
		
		H12_1[i]=0;
		H12_2[i]=0;
	}
	
	for(int y=0;y<srcHSV->height;++y)
	{
		psrc=(unsigned char*)(srcHSV->imageData+y*srcHSV->widthStep);
		for(int x=0;x<srcHSV->width;++x)
		{
			
			H12_1[psrc[x]]++;
			
		}
	}
	
	for(int i=0;i<255;i++)
	{
		if(i<=Light)
		{
			addB+=H12_1[i]*i;
			numB+=H12_1[i];
		}
		else
		{
			addW+=H12_1[i]*i;
			numW+=H12_1[i];
		}
	}
	
	if(numB==0||numW==0)
		return;
	averageB=addB/numB;
	averageW=addW/numW;
	
}


void WitThreshold::valueStatisH12(){
	
	unsigned char * psrc;
	int addH=0,addS=0,addV=0;
	int numH=0,numS=0,numV=0;
	int addInH=0,addInS=0,addInV=0;
	int inNumH=0,inNumS=0,inNumV=0;
	int hmax,smax,vmax;
	for(int i=0;i<255;++i){
		H12_H[i]=0;
		H12_1[i]=0;
		H12_2[i]=0;
	}
	hmax=smax=vmax=0;
	for(int y=0;y<srcHSV->height;++y)
	{
		psrc=(unsigned char*)(srcHSV->imageData+y*srcHSV->widthStep);
		for(int x=0;x<srcHSV->width;++x){
			H12_H[psrc[3*x]]++;
			H12_1[psrc[3*x+1]]++;
			H12_2[psrc[3*x+2]]++;
		}
	}
	for(int i=0;i<255;++i){
		if(hmax<H12_H[i]){hmax=H12_H[i];}
		if(smax<H12_1[i]){smax=H12_1[i];}
		if(vmax<H12_2[i]){vmax=H12_2[i];}
	}
	for(int i=0;i<255;++i)
	{
		y_H[i]=255-(H12_H[i]*255/hmax);
	}
	
	

	for(int i=0;i<255;++i)
	{
		if(Hmax>=Hmin){
			if(i<=Hmax&&i>=Hmin){
				inNumH+=H12_H[i];
				addInH+=i*H12_H[i];
			}
		}
		else
		{
			if(i<=Hmax||i>=Hmin){
				inNumH+=H12_H[i];
				if(i<=Hmax)
					addInH+=((i+180)*H12_H[i]);
				if(i>=Hmin)
					addInH+=i*H12_H[i];
			}
		}
		if(i<=Smax&&i>=Smin){
			addInS+=i*H12_1[i];
			inNumS+=H12_1[i];
		}
		if(i<=Vmax&&i>=Vmin){
			inNumV+=H12_2[i];
			addInV+=i*H12_2[i];
		}
		addH+=i*H12_H[i];
		addS+=i*H12_1[i];
		addV+=i*H12_2[i];
	}
	
	averageH=addH/(srcHSV->width*srcHSV->height);
	averageS=addS/(srcHSV->width*srcHSV->height);
	averageV=addV/(srcHSV->width*srcHSV->height);
	
	if(inNumH==0||inNumS==0||inNumV==0)
		return;
	averageInH=addInH/inNumH;
	averageInS=addInS/inNumS;
	averageInV=addInV/inNumV;
//	printf("%d\n",averageInH);
}


void WitThreshold::valueStatisMainH(){
	
	unsigned char * psrc;
	int addH=0,addS=0,addV=0;
	int numH=0,numS=0,numV=0;
	int addInH=0,addInS=0,addInV=0;
	int inNumH=0,inNumS=0,inNumV=0;
	int hmax,smax,vmax;
	for(int i=0;i<255;++i){
		H12_H[i]=0;
		H12_1[i]=0;
		H12_2[i]=0;
	}
	hmax=smax=vmax=0;
	for(int y=0;y<srcHSV->height;++y)
	{
		psrc=(unsigned char*)(srcHSV->imageData+y*srcHSV->widthStep);
		for(int x=0;x<srcHSV->width;++x){
			H12_H[psrc[3*x]]++;
			if(Hmax>=Hmin)
				if(psrc[3*x]<=Hmax&&psrc[3*x]>=Hmin)
				{
					H12_1[psrc[3*x+1]]++;
					H12_2[psrc[3*x+2]]++;
				}
			if(Hmax<Hmin)
				if((psrc[3*x]<=Hmax&&psrc[3*x]>=0)||(psrc[3*x]>=Hmin&&psrc[3*x]<=180))
				{
					H12_1[psrc[3*x+1]]++;
					H12_2[psrc[3*x+2]]++;
				}
		}
	}
	for(int i=0;i<255;++i){
		if(hmax<H12_H[i]){hmax=H12_H[i];}
		if(smax<H12_1[i]){smax=H12_1[i];}
		if(vmax<H12_2[i]){vmax=H12_2[i];}
	}
	for(int i=0;i<255;++i)
	{
		y_H[i]=255-(H12_H[i]*255/hmax);
	}
	
	
	
	

	for(int i=0;i<255;++i)
	{
		if(Hmax>=Hmin){
			if(i<=Hmax&&i>=Hmin){
				inNumH+=H12_H[i];
				addInH+=i*H12_H[i];
			}
		}
		else
		{
			if(i<=Hmax||i>=Hmin){
				inNumH+=H12_H[i];
				if(i<=Hmax)
					addInH+=((i+180)*H12_H[i]);
				if(i>=Hmin)
					addInH+=i*H12_H[i];
			}
		}
		if(i<=Smax&&i>=Smin){
			addInS+=i*H12_1[i];
			inNumS+=H12_1[i];
		}
		if(i<=Vmax&&i>=Vmin){
			inNumV+=H12_2[i];
			addInV+=i*H12_2[i];
		}
		addH+=i*H12_H[i];
		addS+=i*H12_1[i];
		addV+=i*H12_2[i];
	}
	
	averageH=addH/(srcHSV->width*srcHSV->height);
	averageS=addS/(srcHSV->width*srcHSV->height);
	averageV=addV/(srcHSV->width*srcHSV->height);
	
	if(inNumH==0||inNumS==0||inNumV==0)
		return;
	averageInH=addInH/inNumH;//Õâ¸öÖµ¿ÉÄÜ´óÓÚ180
	averageInS=addInS/inNumS;
	averageInV=addInV/inNumV;
//	printf("%d\n",averageInH);
}


WitThreshold::~WitThreshold()
{

	delete []H12_H;
	delete []H12_1;
	delete []H12_2;
	delete []y_H;
}
