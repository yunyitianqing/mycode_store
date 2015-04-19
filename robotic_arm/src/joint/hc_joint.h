#ifndef _HC_JOINT_
#define _HC_JOINT_
///this class use to define the joint;
///limit angle & the matrix A;
///maybe a robotic_arm can use it;



class Joint
{
protected:
	double limit_min;
	double limit_max;
	double angle;
public:
	Joint();
	void set_limit(double,double);
	void set_angle(double angle);
	void get_angle(double angle);
	
};

#endif//_HC_JOINT_
