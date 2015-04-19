#ifndef _ENGINES_CONTROL_
#define _ENGINES_CONTROL_
#include "WitModule.h"
#include "WitEngine.h"
#include "WitManager.h"
#include "CM730.h"
#include "LinuxCM730.h"
#include"MX28.h"
#define U2D_DEV_NAME0       "/dev/ttyUSB0"
#define U2D_DEV_NAME1       "/dev/ttyUSB1"

class EnginesControl :public Module ,public Engines
{
	Engines *engines_old;
	CM730*cm730;
	LinuxCM730*linux_cm730;
	static EnginesControl* m_UniqueInstance;
	
public:
	static EnginesControl* GetInstance() { return m_UniqueInstance; };
	EnginesControl();
	void M_thread();
	~EnginesControl();
};


#endif //_ENGINES_CONTROL_
