/********************************************************
*	Interface file for the class Elevator.		*
*	Written by Sherine Antoun.			*
*	Do NOT alter this header file.			*
********************************************************/

#ifndef ELEVATOR_H
#define ELEVATOR_H

const int UP = 1, DOWN = -1, STOPPED = 0;

class Elevator
{
	public:
	// constructor for number of floors - no default constructor
		Elevator(int);
	// destructor
		~Elevator();
	// move one floor in required direction
		void Move();
	// report current status: floor, direction, door status
		void Status(int&,int&,int&);
	// handle rider request outside elevator
		void DirectionSelect(int, int);
	// handle rider request inside elevator  
		void ChooseFloor(int);

	private:
		int maxfloor;	// highest numbered floor in the building
		int currentfloor;
		int currentdirection;
		int dooropen;
		int* floorup;	// array for up buttons on floor
		int* floordown;	// array for down buttons
		int* button;	// array of internal buttons
};

#endif
