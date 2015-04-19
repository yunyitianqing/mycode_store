#include"../include/engines_control.h"
#include<stdio.h>
#include<stdlib.h>
EnginesControl* EnginesControl::m_UniqueInstance = new EnginesControl();


EnginesControl::EnginesControl():Module("Engines_Control"),Engines()
{
	engines_old = new Engines();
	linux_cm730 = new LinuxCM730(U2D_DEV_NAME0);
	cm730 = new CM730(linux_cm730);
	if(cm730->Connect() == false)
	{
		if(DEBUG_PRINT == true)
			fprintf(stderr, "Fail to connect CM-730\n");
		exit(0);
	}
	//Manager::GetInstance()->add_module(this);
}

EnginesControl::~EnginesControl()
{
	delete engines_old;
	delete cm730;
	delete linux_cm730;
	//Manager::GetInstance()->del_module(this->name);
}

void EnginesControl::M_thread()
{
	for(int times=0;times<3;times++)
	{
		for(int i=1;i<=20;i++)
		{
			if(CM730::SUCCESS!=cm730->ReadByte(i, MX28::P_ID, &engines[i].READ_DATA[Engine::ID], 0))
			{
				printf("times %d: Engine %d connect failed\n",times,i);
				sleep(3);
				break;
			}
		
		}
		break;
	}
	while(1)
	{
		for(int i=0;i<Engines::NUMBER_OF_ENGINE;i++)
		{
			engines[i].GOAL_POSITION=MX28::Angle2Value(Angle[i]);
		}
		
		for(int i=1;i<=20;i++)
		{
			cm730->ReadWord(i, MX28::P_PRESENT_POSITION_L, &engines[i].READ_DATA[Engine::PRESENT_POSITION],0);
			cm730->ReadWord(i, MX28::P_PRESENT_SPEED_L, &engines[i].READ_DATA[Engine::PRESENT_SPEED],0);
			cm730->ReadWord(i, MX28::P_PRESENT_LOAD_L, &engines[i].READ_DATA[Engine::PRESENT_LOAD],0);
			cm730->ReadByte(i, MX28::P_PRESENT_TEMPERATURE, &engines[i].READ_DATA[Engine::PRESENT_TEMPERATURE],0);
			if(engines[i].LED!=engines_old->engines[i].LED)
			{
				engines_old->engines[i].LED=engines[i].LED;
				cm730->WriteByte(i, MX28::P_LED, engines[i].LED,0);
			}
			if(engines[i].TORQUE_ENABLE!=engines_old->engines[i].TORQUE_ENABLE)
			{
				engines_old->engines[i].TORQUE_ENABLE=engines[i].TORQUE_ENABLE;
				cm730->WriteByte(i, MX28::P_TORQUE_ENABLE, engines[i].TORQUE_ENABLE,0);
			}
			if(engines[i].GOAL_POSITION!=engines_old->engines[i].GOAL_POSITION)
			{
				engines_old->engines[i].GOAL_POSITION=engines[i].GOAL_POSITION;
				cm730->WriteWord(i, MX28::P_GOAL_POSITION_L, engines[i].GOAL_POSITION,0);
			}
			if(engines[i].MOVING_SPEED!=engines_old->engines[i].MOVING_SPEED)
			{
				engines_old->engines[i].MOVING_SPEED=engines[i].MOVING_SPEED;
				cm730->WriteWord(i, MX28::P_MOVING_SPEED_L, engines[i].MOVING_SPEED,0);
			}
		
		}
		
		usleep(7000);
	}
	
}
