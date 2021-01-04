#include "Healer.h"
/////////////////////////yousef

Healer::Healer(int ID, ENMY_TYPE ET, int AT, int H, int POW, int reload, int speed) :Enemy(ID, AT)
{
	Enemy_Type = ET;
	Health = H;
	Power = POW;
	Reload_Period = reload;
	Speed = speed;
	directionOfMovement = 1;

}

void::Healer::Actualspeed() {
	if (Health < 0.5 * original_health) {
		Speed = 0.5 * Speed;
	}
}

void Healer::Move(int d)
{
	if (directionOfMovement == 1) {
		if (Distance + Speed > MinDistance)
			Distance -= Speed;
		else
			directionOfMovement = 0;
		Distance += Speed;
	}
	if (directionOfMovement == 0) {
		if (Distance + Speed > MaxDistance)
			Distance += Speed;
		else {
			directionOfMovement = 1;
			Distance -= Speed;
		}

	}
}
void Healer::Heal(int T, Enemy& E) {

	if (T == AttackTime) {
		if (Health >= 0.5 * original_health) {
			double h = (1.0 / Distance) * Power;
			E.SetHealth(E.GetHealth() + h);
			AttackTime = AttackTime + Reload_Period + 1;
		}
		else {
			double h = (0.5 / Distance) * Power;
			E.SetHealth(E.GetHealth() + h);
			AttackTime = AttackTime + Reload_Period + 1;
		}

	}

}


Healer::~Healer(void)
{
}
