#pragma once
#include"Enemies/Enemy.h"
////////////////////////////////Done By AbdelHALEM
class Fighter :   public Enemy
{
public:
	Fighter(int ID, ENMY_TYPE , int AT, int H, int POW, int reload, int speed);

	virtual void Move(int) ;	    //All enemies can move
	virtual void Act(int, Castle&) ;


};

