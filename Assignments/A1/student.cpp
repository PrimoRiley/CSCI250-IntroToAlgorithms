// write your students details in here

#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

Student::Student()
{// Default constructor
    ID[7] = '\0';
    Name[26] = '\0';
    SubjectIDs[7][4] = '\0';
    NumSubjects = 0;
}

Student::Student(char pID[], char pName[], char pSubjectIDs[][4],int pNumSubjects)
{// Initialisation constructor
    //ID = &pID;
    memcpy(ID, pID, sizeof(ID));
    memcpy(Name, pName, sizeof(Name));
    memcpy(SubjectIDs, pSubjectIDs, sizeof(SubjectIDs));
    NumSubjects = pNumSubjects;
}

int Student::GetCreditPoints(SubjectList &Subjects)
{
    
    //cout<<"subjects:"<<subjects<<endl;
    int total = 0;
    
    
    
    for(int z = 0; z<14; z++)
    {
        
        if(strstr(SubjectIDs[0], Subjects[z].GetIDNumber()) != NULL)
      {
        total = total + Subjects[z].getCredPoints();
      }
    }
   
        
    
    return total;
}

char* Student::getID()
{
    return ID;
}

void Student::setID(char pID[])
{
    strncpy(ID, pID, 6);
}

char* Student::getName()
{
    return Name;
}

void Student::setName(char pName[])
{
    memcpy(Name, pName, sizeof(Name));
}

char* Student::getSubjectIDs()
{
    return *SubjectIDs;
}

void Student::displaySubjects()
{
    cout<<SubjectIDs[0]<<endl;
}

void Student::setSubjectIDs(char pSubjectIDs[])
{
     memcpy(SubjectIDs, pSubjectIDs, sizeof(SubjectIDs));   
}

int Student::getNumSubjects()
{
    return NumSubjects;
}

void Student::setNumSubjects(int pNumSubjects)
{
    NumSubjects = pNumSubjects;
}



