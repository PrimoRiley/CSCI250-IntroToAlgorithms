//  Elevator.cpp
//  Created by Sherine Antoun on 4/21/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.
/* 
I declare that all material in this assessment task is my work except where there is clear acknowledge-
ment or reference to the work of others. I further declare that I have complied and agreed to the CMU
Academic Integrity Policy at the University website.
http://www.coloradomesa.edu/student-services/documents
Author’s Name: Riley Primeau UID(700#): 700510762 Date: 3/26/2022
*/
   
#include "Elevator.h"
#include <iostream>
using namespace std;
// constructor for number of floors - no default constructor

Elevator::Elevator(int floors)
{
    if(floors >= 0)
    {
        maxfloor = floors;
    }
    else
    {
        maxfloor = 1;
    }
	currentfloor = 0;
	currentdirection = 0;
	dooropen = false;
    //creates button arrays 
    floorup = new int[floors+1];	// array for up buttons on floor
    floordown = new int[floors+1];	// array for down buttons
    button = new int[floors+1];
    //sets button arrays
    for(int i =0; i<floors+1; i++)
    {
        floorup[i]=0;
        floordown[i]=0;
        button[i]=0;
    }
}

//Destructor
Elevator::~Elevator()
{
  delete[] floorup;
  delete[] floordown;
  delete[] button;
}

// report current status: floor, direction, door status
void Elevator::Move()
{
  // bools to detmine where request are from
  bool requestAbove = false;
  bool requestBelow = false; 
  //dont move with open door
  if(dooropen)
  {
    dooropen = false; 
  }
  //work out which floor is requesting the elevator
  for(int i=currentfloor; i<=maxfloor; i++)
  {
      //looking for button pushed above our floor
      if((floorup[i] || floordown[i] || button[i]) && (maxfloor!=currentfloor) && (i != currentfloor))
      {
        requestAbove = true;
      }
  }
  for(int i=currentfloor; i>=0; i--)
  {
      //looking for button pushed above our floor
      if((floorup[i] || floordown[i] || button[i]) && (0!=currentfloor) && (i != currentfloor))
      {
        requestBelow = true;
      }
  }
  //keep direction up 
  if((currentdirection == 1) && requestAbove)
  {
      currentdirection = 1;
      currentfloor++;
  }
  //current direction is up but all requests are below
  else if(currentdirection == 1 && !requestAbove && requestBelow)
  {
      currentdirection = -1;
      currentfloor--; 
  }
  //keep direction down
  else if((currentdirection == -1) && requestBelow)
  {
      currentdirection = -1;
      currentfloor--;
  }
  //current direction is dowm but all requests are above
  else if(currentdirection == -1 && !requestBelow && requestAbove)
  {
      currentdirection = 1;
      currentfloor++; 
  }
  //deal with no request to go into idle mode
  else if(!requestAbove && !requestBelow)
  {
      currentdirection = 0; 
  }
  //stopped looking for requests above
  else if(currentdirection == 0 && requestAbove)
  {
      currentdirection = 1;
      currentfloor++;
  }
  //stopped looking for requests below
  else if(currentdirection == 0 && requestBelow)
  {
      currentdirection = -1;
      currentfloor--;
  }
  //clear the flags
  requestAbove = false;
  requestBelow = false; 
  //move completed so again determine where requests are coming from (pretty sure this section is unessecary)
  for(int i=currentfloor; i<=maxfloor; i++)
  {
      //look for buttons pushed from above 
      if((i!=currentfloor) && (floorup[i] || floordown[i] || button[i]) && (maxfloor != currentfloor))
      {
          requestAbove = true;
      }
  }
  for(int i=currentfloor; i>=0; i--)
  {
      //looking for button pushed below our floor
      if((i!=currentfloor) && (floorup[i] || floordown[i] || button[i]) && (0 != currentfloor))
      {
          requestBelow= true;
      }
  }
  //check current floor for requests
  if(floorup[currentfloor])
      requestAbove = true;
  if(floordown[currentfloor])
      requestBelow = true;
  
  //keep direction up 
  if((currentdirection == 1) && requestAbove)
  {
      currentdirection = 1;
  }
  //current direction is up but all requests are below
  else if(currentdirection == 1 && !requestAbove && requestBelow)
  {
      currentdirection = -1;
  }
  //keep direction down
  else if((currentdirection == -1) && requestBelow)
  {
      currentdirection = -1;
  }
  //current direction is dowm but all requests are above
  else if(currentdirection == -1 && !requestBelow && requestAbove)
  {
      currentdirection = 1; 
  }
  //enter idle if no requests 
  else if(!requestAbove && !requestBelow)
  {
      currentdirection = 0; 
  }
  //stopped looking for requests above
  else if(currentdirection == 0 && requestAbove)
  {
      currentdirection = 1;
  }
  //stopped looking for requests below
  else if(currentdirection == 0 && requestBelow)
  {
      currentdirection = -1;
  }
  //check button to do with currrent floor to open door while going up
  if(button[currentfloor] && currentdirection == 1)
  {
      currentdirection = 0;
      dooropen = true;
      button[currentfloor] = false; 
  }
  //check button to do with currrent floor to open door while going down
  if(button[currentfloor] && currentdirection == -1)
  {
      currentdirection = 0;
      dooropen = true;
      button[currentfloor] = false; 
  }
  //floorup reset
  if(floorup[currentfloor] && currentdirection == 1)
  {
      currentdirection = 0;
      if(!dooropen)
          dooropen = true;
      floorup[currentfloor] = false; 
  }
  //floordown reset
  if(floordown[currentfloor] && currentdirection == -1)
  {
      currentdirection = 0;
      if(!dooropen)
          dooropen = true;
      floordown[currentfloor] = false; 
  }

}

//talk to the driver program
void Elevator::Status(int& currentFloor, int& currDir,int& doorIsOpen)
{
    //provides main with current status
    currentFloor = this->currentfloor;
    //cout<<"Floor"<<currentFloor<<endl; 
    currDir = this->currentdirection;
    //cout<<"Direction"<<currDir<<endl;
    doorIsOpen = this->dooropen;
    //cout<<"Door is "<<doorIsOpen<<endl; 
}

// handle rider request outside elevator
void Elevator::DirectionSelect(int floorNum, int direction)
{
    //fills array with which floor the request is from and whether it is up or down 
    if(direction == UP)
    {
        floorup[floorNum] = 1;
    }
    else if (direction == -1)
    {
        floordown[floorNum] = 1;
    }
}
// handle rider request inside elevator
void Elevator::ChooseFloor(int floorchosen)
{
    button[floorchosen] = 1; 
}





