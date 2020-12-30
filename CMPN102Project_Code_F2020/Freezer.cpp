#include "Freezer.h"
#include"Castle/Castle.h"
////////////////////Done By AbdelHalem
Freezer::Freezer(int id, ENMY_TYPE F, int AT, int H, int POW, int reload, int speed) :Enemy(id, AT)
{

	Health = H;
	Power = POW;
	Reload_Period = reload;
	Speed = speed;
}

void Freezer::Move(int d)
{

	if (Distance + Speed > MinDistance)
		Distance -= Speed;
	else
		Distance = MinDistance;
}

void Freezer::Act( int Ts, Castle &C)
{
	if (Ts == AttackTime)
	{
		int ability = Power + ((60 - Distance) / 60) * Power;  //////////If power is extermly high number we will need to modify the formula 
		// we might need to remove power+ and change the threeshould in class castle from 2 to 18 or something.  ///
		C.SetSilenceDuration(ability);
		AttackTime = AttackTime + Reload_Period + 1; //set the new attack_time
	}

	Move(Ts);
}