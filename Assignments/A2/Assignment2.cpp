/************************************************************************
*	Driver program to test the class Elevator			*
*	Written by Sherine Antoun					*
*	Note that this is NOT the way the simulation would normally	*
*	be carried out.  It is a quick fix just for test purposes.	*
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Elevator.h"

int random(int,int);

const int NOTYET = -1, WAIT=0, ON=1, OFF=2;
struct RiderType
{
	int arrivetime;
	int floorstart;
	int floorfinish;
	int status;
};

const int NRIDERS = 12, MAXFLOOR = 10;

int main(int argc, char * argv[])
{	
	RiderType rider[NRIDERS];
	Elevator e(MAXFLOOR);
	int i, t, floor, direction, door, lastrider = 0;
	bool finished = false;
	long seed;
	
	seed = 54321;
	srand(seed);	// change this to use time(0) to try other simulations

//	Generate the riders, when they arrive, what floor they get in, get out

	t = 0;
	cout << "Start of simulation of elevator. " << MAXFLOOR+1 << " floors.\n\n";

	for (i=0;i<NRIDERS;i++)
	{
		t = t + random(0,5);
		rider[i].arrivetime = t;
		rider[i].floorstart = random(0,MAXFLOOR);
		do
			rider[i].floorfinish = random(0,MAXFLOOR);
		while (rider[i].floorfinish == rider[i].floorstart);
		rider[i].status = NOTYET;
	}
	
//	Start the simulation, set the clock ticking
	t = 0;
	while (!finished )	// terminate when all riders' journeys finished
	{
		//Determine where the elevator is, and its state

		e.Move();
		e.Status(floor,direction,door);
		cout << "T" << t << ".\tElevator is on floor " << floor << " with the doors ";
		if (door)
			cout << "open.";
		else
			cout << "closed.";
		if (direction == UP)
			cout << " Going up.";
		else if (direction == DOWN)
			cout << " Going down.";
		else
			cout << " Stopped.";
		cout << endl;
		
		//See if a rider is to arrive at this time

		i = lastrider;
		while (i < NRIDERS && rider[i].arrivetime <= t)
		{
			if (rider[i].status == NOTYET)
			{
				rider[i].status = WAIT;
				cout << "\tRider " << i+1 << " arrives at floor " << rider[i].floorstart
					<< " and presses the button to go ";
				lastrider = i;
				if (rider[i].floorfinish > rider[i].floorstart)
				{
					cout << "up." << endl;
					e.DirectionSelect(rider[i].floorstart,UP);
				}
				else
				{
					cout << "down." << endl;
					e.DirectionSelect(rider[i].floorstart,DOWN);
				}
			}
			i++;
		}

		//See what riders currently in the system are doing

		finished = true;
		for (i=0;i<=lastrider;i++)
		{
			if ((rider[i].status == WAIT) && (rider[i].floorstart == floor) && door)
			{
				if ((rider[i].floorfinish-rider[i].floorstart)*direction >= 0 || random(0,1) == 0)
				{
					cout << "\tRider " << i+1 << " enters elevator and presses floor " 
						<< rider[i].floorfinish << " button." << endl;
					e.ChooseFloor(rider[i].floorfinish);
					rider[i].status = ON;
				}
				else
					cout << "\tRider " << i+1 << " continues to wait." << endl;
			}
			else if ((rider[i].status == ON) && (rider[i].floorfinish == floor))
			{
				cout << "\tRider " << i+1 << " leaves elevator." << endl;
				rider[i].status = OFF;
			}
			if (rider[i].status != OFF) finished = false;
		}
		t++;		// tick the clock forward
	}
	cout << "END OF SIMULATION" << endl;
	return 0;
}

// Function to generate random number in the range a to b

int random(int a, int b)
{
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
	return (rand()%(b-a+1) + a);
}
