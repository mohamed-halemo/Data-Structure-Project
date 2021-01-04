#pragma once
//////////////////Done by AbdelHalem
#include"Enemies/Enemy.h"
class Freezer : public Enemy
{
public:
	Freezer(int ID, int AT, int H, int POW, int reload, int speed);
	virtual void Move(int);	    //All enemies can move
	virtual void Act(int, Castle&);
	virtual void Actualspeed();

};

