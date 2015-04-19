#ifndef _LWT_
#define _LWT_

#include"findcolor.h"

class FindDoor
{
public:
	IplImage*src;//a BW picture
	
	int door_left,door_right;
	
	FindDoor(IplImage*src);
	FindDoor(){};
	FindDoor(FindDoor&);
	~FindDoor();
	
	void loadImage(IplImage*src);
	void findNearestDoorByBlackAndWhite(int,int);
	void drawNearestDoorLR(IplImage*);
};

class Interface

{
	FindDoor finddoor;
	WitThreshold threshold;
	WitFindColor findcolor;
	
public:
	Interface(){};
	~Interface(){};
	
	void interface1(IplImage*src,// a BGR picture
	int*threshold,	//[0]Hmin [1]Hmax [2]Smin [3]Smax [4]Vmin [5]Vmax
	int*returnData, //[0]door_left [1]door_right
	int*controlforAI,//[0] true is open AIchangeThreshold
					 //[1] true is open AIsetLong
					 //[2] true is open AIsetLimit
	int*controlForFinddoor,//[0] door min distance [1]door height
	
	int*limitThreshold,		//[0]Hmin [1]Hmax [2]Smin [3]Smax [4]Vmin [5]Vmax
	int*limitLong,	//[0]Hlong [1]Slong [2]Vlong
	IplImage*returnimg// a BGR picture
	
	);
	
};


#endif
