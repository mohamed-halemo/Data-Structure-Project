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



public:

	void SetHealth(double h);
	double GetHealth() const;

	//
	// TODO: Add More Member Functions As Needed
	//

};

