#include"camera.h"

Camera::Camera()
{
	capture=cvCreateCameraCapture(1);
}

IplImage*Camera::get_frame()
{
	return cvQueryFrame(capture);
}

Camera::~Camera()
{
	cvReleaseCapture(&capture);
}
