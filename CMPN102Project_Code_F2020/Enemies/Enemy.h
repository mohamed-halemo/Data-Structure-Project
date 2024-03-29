﻿#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
class Castle;
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
	double MaxHealth; //Enemy's maximum health


	///////yousef
	double original_health;
	ENMY_TYPE Enemy_Type;    //Fighter, Healer or Freezer															
	bool Active_Enemy;       //is an enemy with Arrival Time ≤ current time step & Health > 0.
	bool Frosted_Enemy;      //Frosted enemies cannot move or attack castle.														
	///////yousef


	//added by ABDELHALEM    ////////////////////////////////////////////////////////////////////////
	double Power;			 //The power of the enemy.
	int Reload_Period;		 //Time for an enemy to reload its weapon.
	int Speed;				 //number of meters an enemy can move in a single time step.
	int AttackTime;//the seconds when enemy is attacking                           xxxxxx
	int FirstShotDelay; //First Shot Delay FD = Tfirst_shot - Tarrival             xxxxxxx
	int KillTimeStep; //Kill Time Step                                             xxxxxx
	int KillDelay; //KillDelay KD = Tenemy_killed - Tfirst_shot                    xxxxxx
	int LifeTime; //Life Time (FD+KD)                                               xxxxxxx
	int FrostedTime;//frosted Time (castle1st frost shot+frosting time)
	float Priority;

	//    /////////////////////////////////////////////////////////////////////////////



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

	//////yousef
	double getoriginal_health();
	void setoriginal_health(double);
	void SetEnemyType(ENMY_TYPE t);
	ENMY_TYPE GetEnemyType();
	void SetActive_Enemy(bool);
	bool GetActive_Enemy();
	void SetFrosted_Enemy(bool);
	bool GetFrosted_Enemy();


	/////yousef

	//	Added by ABDELHALEM            ///////////////////////////////////////////////////////////

	//void SetArrvTime(int);  (ASK do it or not)

	//void SetID(int);        (ask do it or not)  



	void SetHealth(double);
	double GetHealth() const;
	void SetMaxHealth(double);
	double GetMaxHealth() const;
	int GetPower() const;
	void SetPower(int);
	int GetReload_Period() const;
	void SetReload_Period(int);
	int GetSpeed() const;
	void SetSpeed(int);



	void SetAttackTime(int);
	int GetAttackTime() const;
	void SetPriority(float);
	float GetPriority() const;

	void SetFirstShotDelay(int F);
	int GetFirstShotDelay() const;
	void SetKillTimeStep(int T);
	int GetKillTimeStep() const;
	void SetKillDelay(int kd);
	int GetKillDelay() const;
	int GetLifeTime() const;
	void SetFrostedTime(int);
	int GetFrostedTime() const;


	// Virtual Functions: ----------------
	virtual void Move(int);	    //All enemies can move
	virtual void Act(int, Castle&);
	//until here            /////////////////////////////////////////////////////////////////////////////////
	//virtual void Move(int) = 0;	//All enemies can move
	//virtual void Act(int,Castle&) = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

