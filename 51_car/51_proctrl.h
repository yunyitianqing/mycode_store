#ifndef _PROCTRL_
#define _PROCTRL_
#include"sport.h"



class ProCtrl:public S_port
{


public:

	ProCtrl();
	~ProCtrl();
	
	void turn_left();
	void turn_right();
	void go();
	void back();
	void stop();
};

#endif
