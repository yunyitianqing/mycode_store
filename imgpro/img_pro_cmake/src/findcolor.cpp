#include<findcolor.h>

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
	if(src->nChannels!=3)
		return;
	if(dst->nChannels!=3)
		return;
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



void WitFindColor::findByBGR2GRAY(IplImage*dst){
	if(src->nChannels!=3)
		return;
	if(dst->nChannels!=1)
		return;
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

void WitFindColor::findByBGR2GRAY(){
	if(src->nChannels!=3)
		return;
	if(dst->nChannels!=1)
		return;
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
	if(src->nChannels!=1)
		return;
	if(dst->nChannels!=1)
		return;
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

void WitFindColor::findByGRAY2GRAY(IplImage*dst)
{
	if(src->nChannels!=1)
		return;
	if(dst->nChannels!=1)
		return;
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
	if(src->nChannels!=3)
		return;
	if(dst->nChannels!=3)
		return;
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
	if(src->nChannels!=3)
		return;
	if(dst->nChannels!=1)
		return;
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


void WitFindColor::findByHSV2GRAY(IplImage*dst)
{
	if(src->nChannels!=3)
		return;
	if(dst->nChannels!=1)
		return;
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

void WitFindColor::loadImageSrc(IplImage*src)
{
	this->src=src;
}

void WitFindColor::loadImageDst(IplImage*dst)
{
	this->dst=dst;
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

inline int WitFindColor::returnPointNum()
{
	return pointNum;
}

inline CvPoint WitFindColor::returnAveragePoint()
{
	return averagePoint;
}

///MapFindColor_Base
Map_FindColor_Base::Map_FindColor_Base(int v1 ,int v2,int v3,int v4,int v5,int v6)
{
	ColorMap=new bool[181][256];
	
	
	for(int y=0;y<=180;++y)
		for(int x=0;x<=255;++x)
		{
			ColorMap[y][x]=0;
			if(v1<=v2)
			{
				if(y>=v1&&y<=v2&&x>=v3&&x<=v4)
					ColorMap[y][x]=1;
			}
			if(v1>v2)
			{
				if((y>=v1||y<=v2)
					&&x>=v3&&x<=v4)
					ColorMap[y][x]=1;
			}
		}
}

Map_FindColor_Base::Map_FindColor_Base(int*thresh)
{
	ColorMap=new bool[181][256];
	
	
	for(int y=0;y<=180;++y)
		for(int x=0;x<=255;++x)
		{
			ColorMap[y][x]=0;
			if(thresh[0]<=thresh[1])
			{
				if(y>=thresh[0]&&y<=thresh[1]&&x>=thresh[2]&&x<=thresh[3])
					ColorMap[y][x]=1;
			}
			if(thresh[0]>thresh[1])
			{
				if((y>=thresh[0]||y<=thresh[1])
					&&x>=thresh[2]&&x<=thresh[3])
					ColorMap[y][x]=1;
			}
		}
}


Map_FindColor_Base::Map_FindColor_Base()
{
	ColorMap=new bool[181][256];
	for(int y=0;y<=180;++y)
		for(int x=0;x<=255;++x)
			ColorMap[y][x]=0;
}


///FindColor_Base
void FindColor_Base::loadThresh(int v1min,int v1max,int v2min,int v2max,int v3min ,int v3max)
{
	this->v1min=v1min;
	this->v1max=v1max;
	this->v2min=v2min;
	this->v2max=v2max;
	this->v3min=v3min;
	this->v3max=v3max;
}


void FindColor_Base::loadThresh(int*thresh)
{
	this->v1min=thresh[0];
	this->v1max=thresh[1];
	this->v2min=thresh[2];
	this->v2max=thresh[3];
	this->v3min=thresh[4];
	this->v3max=thresh[5];
}

bool FindColor_Base::inThreshHSV(int H,int S, int V )
{
	if(v1max>=v1min)
	{
		if(H<=v1max&&H>=v1min)
			if(S<=v2max&&S>=v2min)
				if(V<=v3max&&V>=v3min)
					return 1;
		return 0;
	}
	else 
	{
		if((H<=v1max&&H>=0)||(H>=v1min&&H<=180))
			if(S<=v2max&&S>=v2min)
				if(V<=v3max&&V>=v3min)
					return 1;
		return 0;
	}
}


///Blob_FindColor
Blob_FindColor::Blob_FindColor(int num)
{
	//k=0.7;
	BlobNum=num;
	BlobPix=new int[BlobNum+1][2];
	BlobMap=0;
	for(int y=0;y<2;++y)
		for(int x=0;x<BlobNum+1;++x)
			BlobPix[y][x]=0;
}

Blob_FindColor::Blob_FindColor(int num,IplImage*BlobMap):FindColor_Base()
{	
	//k=0.7;
	BlobNum=num;
	this->BlobMap=BlobMap;
	BlobPix=new int[BlobNum+1][2];
	for(int y=0;y<BlobNum+1;++y)
		for(int x=0;x<2;++x)
			BlobPix[y][x]=0;
			
	
}

Blob_FindColor::~Blob_FindColor()
{
	delete []BlobPix[2];
}

int Blob_FindColor::loadBlobMap(IplImage*map)
{
	if(map->nChannels!=1)
		return -1;
	this->BlobMap=map;
	return 1;
}

int Blob_FindColor::findByHSV2GRAY(IplImage*src,IplImage*dst,double percent)
{
	if(BlobMap==0)
		return -1;
	for(int y=0;y<BlobNum+1;++y)
		for(int x=0;x<2;++x)
			BlobPix[y][x]=0;
	unsigned char* psrc,*pdst,*pmap;
///按区块统计像素。
	
	for(int y=0;y<BlobMap->height;++y)
	{
		psrc=(unsigned char*)(src->imageData+y*src->widthStep);
		
		pmap=(unsigned char*)(BlobMap->imageData+y*BlobMap->widthStep);
		for(int x=0;x<BlobMap->width;++x)
		{	
			if(pmap[x]==255)continue;
			//printf("%d ",pmap[x]);
			BlobPix[pmap[x]][0]++;
			if(v1min<=v1max)
				if(psrc[3*x+0]<=v1max&&psrc[3*x+0]>=v1min)
					if(psrc[3*x+1]<=v2max&&psrc[3*x+1]>=v2min);
						BlobPix[pmap[x]][1]++;
			if(v1min>v1max)
				if((psrc[3*x+0]<=v1max&&psrc[3*x+0]>=0)||(psrc[3*x+0]>=v1min&&psrc[3*x+0]<=180))
					if(psrc[3*x+1]<=v2max&&psrc[3*x+1]>=v2min);
						BlobPix[pmap[x]][1]++;
						
		}
	}
	//printf("\n");
	
///确定哪一个区块是目标	
	bool key[255];
	for(int i=0;i<255;i++)
		key[i]=0;
	for(int i=0;i<BlobNum;i++)
		if((double)BlobPix[i][1]/(double)BlobPix[i][0]>percent)
			key[i]=1;
///画出该区块
		
	for(int y=0;y<BlobMap->height;++y)
	{
		
		pdst=(unsigned char*)(dst->imageData+y*dst->widthStep);
		pmap=(unsigned char*)(BlobMap->imageData+y*BlobMap->widthStep);
		for(int x=0;x<BlobMap->width;++x)
		{
			if(key[pmap[x]]==1)
				pdst[x]=255;
			else 
				pdst[x]=0;
						
		}
	}

	return 1;
	
}
