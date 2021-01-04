#pragma once
#include"Enemies/Enemy.h"
////////////////////////////yousef
class Healer :public Enemy
{
private:
	bool directionOfMovement;
public:
	Healer(int ID, ENMY_TYPE, int AT, int H, int POW, int reload, int speed);
	virtual void Move(int);
	virtual void Actualspeed();
	virtual void Heal(int, Enemy&);
	~Healer(void);

};

