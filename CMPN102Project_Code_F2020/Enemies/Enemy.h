#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	const int ID;         //Each enemy has a unique ID (sequence number)
	const int ArrvTime;	//arrival time (time it starts to join battle)

	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	int Distance;	//Horizontal distance between enemy & the tower of its region
					//Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	//added by Medo         ////////////////////////////////////////////////////////////////////////
	double Power;
	int ReloadTime;
	int Speed;
	int AttackTime;//the seconds when enemy is attacking
	int FirstShotDelay; //First Shot Delay FD = Tfirst_shot - Tarrival 
	int KillTimeStep; //Kill Time Step
	int KillDelay; //KillDelay KD = Tenemy_killed - Tfirst_shot 
	int LifeTime; //Life Time (FD+KD)
	int FrostedTime;//frosted Time (castle1st frost shot+frosting time)
	int Priority;
	int EnemyType;
	//                   /////////////////////////////////////////////////////////////////////////////
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy(int id, int arrTime, int d = MaxDistance);
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);

	void DecrementDist();

	void SetDistance(int);
	int GetDistance() const;

	int GetArrvTime() const;

	//	Added by Medo            ///////////////////////////////////////////////////////////

	//void SetArrvTime(int);  (ASK do it or not)

	//void SetID(int);        (ask do it or not)  




	double GetHealth();
	void SetHealth(double h);
	void SetPower(int);
	int GetPower();
	void SetReloadTime(int);
	int GetReloadTime();
	void SetSpeed(int);
	int GetSpeed();
	void SetAttackTime(int);
	int GetAttackTime();
	void SetPriority(int);
	int GetPriority();
	void SetEnemyType(int t);
	int GetEnemyType();
	void SetFirstShotDelay(int F);
	int GetFirstShotDelay();
	void SetKillTimeStep(int T);
	int GetKillTimeStep();
	void SetKillDelay(int kd);
	int GetKillDelay();
	int GetLifeTime();
	void SetFrostedTime(int);
	int GetFrostedTime();
	//until here            ////////////////////////////////////////////////////////////////////////

	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

