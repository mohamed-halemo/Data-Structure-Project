#include "Enemy.h"


Enemy::Enemy(int id, int arrTime, int d) :ID(id), ArrvTime(arrTime)
{
	SetDistance(d);
	LifeTime = FirstShotDelay + KillDelay;
}



Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}


void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}


ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}


void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}


//////yousef
void Enemy::SetEnemyType(ENMY_TYPE ET)
{
	Enemy_Type = ET;
}
ENMY_TYPE Enemy::GetEnemyType()
{
	return Enemy_Type;
}
void Enemy::SetActive_Enemy(bool x){
	Active_Enemy=x;
}
bool Enemy::GetActive_Enemy(){
	return Active_Enemy;
}
void Enemy::SetFrosted_Enemy(bool x){
	Frosted_Enemy=x;
}
bool Enemy::GetFrosted_Enemy(){
	return Frosted_Enemy;
}

void Enemy::SetFire_Power(double x){
	Fire_Power=x;
}
double Enemy::GetFire_Power(){
	return Fire_Power;
}

//////yousef

/////////////Added by ABDELHALEM ///////////////////////////////////////////////////////////////////////////////////////////
void Enemy::SetHealth(double H)
{
	Health = H;
}

double Enemy::GetHealth()
{
	return Health;
}
void Enemy::SetPower(int P)
{
	Power = P;
}
int Enemy::GetPower()
{
	return Power;
}
void Enemy::SetReload_Period(int RT)
{
	Reload_Period = RT;
}
int Enemy::GetReload_Period()
{
	return Reload_Period;
}
void Enemy::SetSpeed(int S)
{
	Speed = S;
}
int Enemy::GetSpeed()
{
	return Speed;
}
void Enemy::SetAttackTime(int AT)
{
	AttackTime = AT;
}
int Enemy::GetAttackTime()
{
	return AttackTime;
}
void Enemy::SetPriority(int P)
{
	Priority = P;
}
int Enemy::GetPriority()
{
	return Priority;
}

void Enemy::SetFirstShotDelay(int FirstD)
{
	FirstShotDelay = FirstD;
}
int Enemy::GetFirstShotDelay()
{
	return FirstShotDelay;
}
void Enemy::SetKillTimeStep(int KTS)
{
	KillTimeStep = KTS;
}
int Enemy::GetKillTimeStep()
{
	return KillTimeStep;
}
void Enemy::SetKillDelay(int KD)
{
	KillDelay = KD;
}
int Enemy::GetKillDelay()
{
	return KillDelay;
}
int Enemy::GetLifeTime()
{
	return LifeTime;
}
void Enemy::SetFrostedTime(int FT)
{
	FrostedTime = FT;
}
int Enemy::GetFrostedTime()
{
	return FrostedTime;
}
