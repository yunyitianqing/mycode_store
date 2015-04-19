#ifndef _WIT_ENGINE_
#define _WIT_ENGINE_

class EnginesControl;

class Engine
{
public:
	Engine();
	enum
	{
		ID=0,
		PRESENT_POSITION=1,
		PRESENT_SPEED=2,
		PRESENT_LOAD=3,
		PRESENT_TEMPERATURE=4,
		NUMBER_OF_READ_DATA
	};
	
	
	int LED;
	int GOAL_POSITION;
	int MOVING_SPEED;
	int TORQUE_ENABLE;
	
	int READ_DATA[NUMBER_OF_READ_DATA];
};

class Engines
{
protected:
	
	friend class EnginesControl;
public:
		enum
		{
			ID_R_SHOULDER_PITCH     = 1,
			ID_L_SHOULDER_PITCH     = 2,
			ID_R_SHOULDER_ROLL      = 3,
			ID_L_SHOULDER_ROLL      = 4,
			ID_R_ELBOW              = 5,
			ID_L_ELBOW              = 6,
			ID_R_HIP_YAW            = 7,
			ID_L_HIP_YAW            = 8,
			ID_R_HIP_ROLL           = 9,
			ID_L_HIP_ROLL           = 10,
			ID_R_HIP_PITCH          = 11,
			ID_L_HIP_PITCH          = 12,
			ID_R_KNEE               = 13,
			ID_L_KNEE               = 14,
			ID_R_ANKLE_PITCH        = 15,
			ID_L_ANKLE_PITCH        = 16,
			ID_R_ANKLE_ROLL         = 17,
			ID_L_ANKLE_ROLL         = 18,
			ID_HEAD_PAN             = 19,
			ID_HEAD_TILT            = 20,
			ID_R_WRIST              = 21,
			ID_L_WRIST              = 22,
			ID_R_HAND               = 23,
			ID_L_HAND               = 24,
			NUMBER_OF_ENGINE
		};
	
	double Angle[NUMBER_OF_ENGINE];
	Engine *engines;
	Engines();
	
};


#endif //_WIT_ENGINE_
