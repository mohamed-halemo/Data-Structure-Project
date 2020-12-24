#include "Castle.h"




void Castle::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Castle::GetHealth() const
{
	return Health;
}
//////////////////////////////////////////////////////////
void Castle::setPower(double P){
	Power=P;
}
double Castle::getPower(){
	return Power;
}
void Castle::setNumberOfEnemiesBeingAttacked(int N){
	NumberOfEnemiesBeingAttacked=N;
}
int  Castle::getNumberOfEnemiesBeingAttacked(){
	return NumberOfEnemiesBeingAttacked;
}
int Castle::getNumberOfKilledEnemies(){
	return NumberOfKilledEnemies;
}
