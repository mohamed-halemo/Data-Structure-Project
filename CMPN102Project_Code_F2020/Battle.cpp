#include "Battle.h"
#include <time.h>
#include <fstream>
#include "Fighter.h"
#include "Healer.h"
#include "Freezer.h"
#include "Generic_DS/Queue.h"


Battle::Battle()
{
	EnemyCount = 0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	DemoListCount = 0;
	CurrentTimeStep = 0;
	pGUI = NULL;
}

void Battle::AddtoDemoList(Enemy* Ptr)
{
	DemoList[DemoListCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It just enqueue a pointer that is already allocated into the queue
}


Castle* Battle::GetCastle()
{
	return &BCastle;
}


void Battle::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();

	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		Interactive();
		break;
	case MODE_STEP:
		Step();
		break;
	case MODE_SLNT:
		Silent();
		break;
	case MODE_DEMO:
		Just_A_Demo();

	}

	delete pGUI;

}

void Battle::Interactive()
{

	pGUI->PrintMessage("Please Enter The File's Name To Load The Input Data: ");
	//(TO DO) IMPLEMENT HOW TO GET THE NAME AND STORE IT AND CHECK THE EXISTENCE OF THE FILE HERE.
	int NumberOfShots = 5; //Number Of Shots Shot By Castle (assumed a random number which is 5 till we implement save/load)
	CurrentTimeStep = 0;
	BCastle.setNumberOfEnemiesBeingAttacked(NumberOfShots);
	while (BCastle.getNumberOfEnemiesBeingAttacked() > 0)
	{
		if (!Pri_Q_Fighters.isEmpty())
		{
			Fighter* fighter;
			Pri_Q_Fighters.dequeue(fighter);
			fighter->SetHealth(fighter->GetHealth() - BCastle.getDamage());
			if (fighter->GetHealth() <= 0)
			{
				fighter->SetKillTimeStep(CurrentTimeStep);
				fighter->SetStatus(KILD);
			}

		}

	}

}

void Battle::Step()
{

}


void Battle::Silent()
{

}



//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{

	pGUI->PrintMessage("Just a Demo. Enter Enemies Count(next phases should read I/P filename):");
	EnemyCount = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Enemies randomly... In next phases, Enemies should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();

	CurrentTimeStep = 0;
	//
	// THIS IS JUST A DEMO Function
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	//

	srand(time(NULL));
	int Enemy_id = 0;
	int ArrivalTime = 1;
	Enemy* pE = NULL;
	//Create Random enemies and add them all to inactive queue
	for (int i = 0; i < EnemyCount; i++)
	{
		ArrivalTime += (rand() % 3);	//Randomize arrival time
		pE = new Enemy(++Enemy_id, ArrivalTime);
		pE->SetStatus(INAC); //initiall all enemies are inactive
		Q_Inactive.enqueue(pE);		//Add created enemy to inactive Queue
	}

	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive

	pGUI->waitForClick();

	while (KilledCount < EnemyCount)	//as long as some enemies are alive (should be updated in next phases)
	{
		CurrentTimeStep++;
		ActivateEnemies();

		Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes only)

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);
		Sleep(250);
	}
}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{
	//Add inactive queue to drawing list
	int InactiveCount;
	Enemy* const* EnemyList = Q_Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
		pGUI->AddToDrawingList(EnemyList[i]);

	//Add other lists to drawing list
	//TO DO
	//In next phases, you should add enemies from different lists to the drawing list
	//For the sake of demo, we will use DemoList
	for (int i = 0; i < DemoListCount; i++)
		pGUI->AddToDrawingList(DemoList[i]);
}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy* pE;
	while (Q_Inactive.peekFront(pE))	//as long as there are more inactive enemies
	{
		if (pE->GetArrvTime() > CurrentTimeStep)	//no more arrivals at current time
			return;

		Q_Inactive.dequeue(pE);	//remove enemy from the queue
		pE->SetStatus(ACTV);	//make status active
		AddtoDemoList(pE);		//move it to demo list (for demo purposes)
	}
}
//Read data from the file (for input) MENNAA
void Battle::InputFile(string FileName)
{
	ifstream input;
	input.open(FileName);
	if (input.is_open())
	{
		input >> CastleHealth >> MaxEnemy >> CastlePower;
		input >> EnemyCount;
		int ID, TYP, AT, H, POW, RLD, SPD;
		Enemy* enemytype;
		for (int i = 0; i < EnemyCount; i++)
		{
			input >> ID >> TYP >> AT >> H >> POW >> RLD >> SPD;
			if (TYP == 0)
			{
				enemytype = new Fighter(ID, AT, H, POW, RLD, SPD);
				Q_Inactive.enqueue(enemytype);
			}
			else if (TYP == 1)
			{
				enemytype = new Healer(ID, HEALER, AT, H, POW, RLD, SPD);
				Q_Inactive.enqueue(enemytype);
			}
			else if (TYP == 2)
			{
				enemytype = new Freezer(ID, AT, H, POW, RLD, SPD);
				Q_Inactive.enqueue(enemytype);
			}
		}

	}
	input.close();
}

///Output MENNAA
void Battle::OutputFile(GUI* pGUI)
{
	pGUI->PrintMessage("Enter the Output File Name");
	string name = pGUI->GetString() + ".txt";
	ofstream Output;
	Output.open(name);
	Castle* C;
	if (KilledCount == EnemyCount)
	{
		Output << "Game is WIN" << endl;
	}
	else if (C->GetHealth() == 0)
	{
		Output << "Game is LOSS" << endl;
	}
	else
	{
		Output << "Game is DRAWN" << endl;
	}
	Output << "KTS ID FD KD LT" << endl;
	Enemy* E;

	for (int i = 0; i < KilledCount; i++)
	{
		if (!Q_Killed.isEmpty())
		{
			Q_Killed.peekFront(E);
			int KTS, ID, FD, KD, LT;

			KTS = E->GetKillTimeStep();
			ID = E->GetID();
			FD = E->GetFirstShotDelay();
			KD = E->GetKillDelay();
			LT = E->GetLifeTime();
			Output << KTS << " " << ID << " " << FD << " " << KD << " " << LT << endl;
			Q_Killed.dequeue(E);
		}
	}
}

//Randomly update enemies distance/status (for demo purposes)
void Battle::Demo_UpdateEnemies()
{
	Enemy* pE;
	int Prop;
	//Freeze, activate, and kill propablities (for sake of demo)
	int FreezProp = 5, ActvProp = 10, KillProp = 1;
	srand(time(0));
	for (int i = 0; i < DemoListCount; i++)
	{
		pE = DemoList[i];
		switch (pE->GetStatus())
		{
		case ACTV:
			pE->DecrementDist();	//move the enemy towards the castle
			Prop = rand() % 100;
			if (Prop < FreezProp)		//with Freeze propablity, change some active enemies to be frosted
			{
				pE->SetStatus(FRST);
				ActiveCount--;
				FrostedCount++;
			}
			else	if (Prop < (FreezProp + KillProp))	//with kill propablity, kill some active enemies
			{
				pE->SetStatus(KILD);
				ActiveCount--;
				KilledCount++;
			}

			break;
		case FRST:
			Prop = rand() % 100;
			if (Prop < ActvProp)			//with activation propablity, change restore some frosted enemies to be active again
			{
				pE->SetStatus(ACTV);
				ActiveCount++;
				FrostedCount--;
			}

			else	if (Prop < (ActvProp + KillProp))			//with kill propablity, kill some frosted enemies
			{
				pE->SetStatus(KILD);
				FrostedCount--;
				KilledCount++;
			}

			break;
		}
	}
}
