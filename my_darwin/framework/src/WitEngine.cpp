#include"WitEngine.h"

Engine::Engine()
{
	
	LED=0;
	GOAL_POSITION=0;
	MOVING_SPEED=0;
	TORQUE_ENABLE=0;
	for(int i=0;i<NUMBER_OF_READ_DATA;i++)
	{
		READ_DATA[i]=0;
	}
};

Engines::Engines()
{
	engines=new Engine[NUMBER_OF_ENGINE];
	for(int i=1;i<NUMBER_OF_ENGINE;i++)
	{
		engines[i].READ_DATA[0]=i;
		Angle[i]=0;
	}
}
