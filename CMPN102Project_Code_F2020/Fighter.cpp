#include "Fighter.h"
#include"Castle/Castle.h"
////////////////////Done By AbdelHalem
Fighter::Fighter( int id, int AT, double H, double POW, int reload, int speed):Enemy(id,AT)
{
	SetEnemyType(FIGHTER);
	Health = H;
	Power = POW;
	Reload_Period = reload;
	Speed = speed;
}

 void Fighter::Move(int d)
{
	
	if (Distance + Speed > MinDistance)
		Distance -= Speed;
	else
		Distance = MinDistance;
}



void Fighter::Act(int T, Castle& C)
{
	if (T == AttackTime)
	{
		double damage = (1.0 / Distance) * Power;
		C.SetHealth(C.GetHealth() - damage);
		AttackTime = AttackTime + Reload_Period + 1; // New Attack Time
	}

	Move(T);
}
void::Fighter::Actualspeed() {
	if (Health < 0.5 * original_health) {
		Speed = 0.5 * Speed;
	}
}
//////////////////////////////////////////////////////////////////////