#include"51_proctrl.h"
#include<stdio.h>
#include<stdlib.h>

ProCtrl::ProCtrl():S_port()
{
	if(-1==open())
	{
		printf("sport open error \n");
		exit(1);
	}
}

ProCtrl::~ProCtrl()
{
	close();
}

void ProCtrl::turn_left()
{
	this->write_byte('4');
}
void ProCtrl::turn_right()
{
	this->write_byte('3');
}
void ProCtrl::go()
{
	this->write_byte('1');
}
void ProCtrl::back()
{
	this->write_byte('2');
}
void ProCtrl::stop()
{
	this->write_byte('0');
}
