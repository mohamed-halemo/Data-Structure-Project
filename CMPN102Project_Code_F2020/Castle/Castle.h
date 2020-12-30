#pragma once
#include "..\Defs.h"
class Castle
{
	double Health;
	
	//
	// TODO: Add More Data Members As Needed
	//
	double Power;
	int NumberOfEnemiesBeingAttacked;
	int FrostingTime; //precent is 20%
	int NumberOfKilledEnemies;
	int SilenceDuration;
	bool Silenced;


public:

	void SetHealth(double h);
	double GetHealth() const;

	//////////////////////////////////////////////////////
	void setPower(double P);
	double getPower();
	void setNumberOfEnemiesBeingAttacked(int N);
	int getNumberOfEnemiesBeingAttacked();
	int getNumberOfKilledEnemies();

	//
	// TODO: Add More Member Functions As Needed
	////////////////////////////////////////////////AbdelHalem
	void SetSilenceDuration(int);
	bool IsSilenced();
	///////////////////////////////////////////
};

