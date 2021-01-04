#pragma once
#include"Enemies/Enemy.h"
////////////////////////////////Done By AbdelHALEM
class Fighter :   public Enemy
{
public:
	Fighter(int id, int AT, double H, double POW, int reload, int speed);

	virtual void Move(int) ;	    //All enemies can move
	virtual void Act(int, Castle&) ;
	virtual void Actualspeed();


};

