#ifndef _CAMERA_
#define _CAMERA_
#include<cv.h>
#include<highgui.h>
class Camera
{
	
	CvCapture*capture;
public:
	Camera();
	~Camera();
	IplImage*get_frame();
};

#endif
