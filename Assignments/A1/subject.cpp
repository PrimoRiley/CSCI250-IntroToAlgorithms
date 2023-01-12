// See assignment specs

#include <iostream>
#include <cstring>
#include "Subject.h"
using namespace std;

Subject::Subject()
{// Default constructor

}

Subject::Subject(int pSemester, char pIDNumber[4], char pName[26], int pCreditPoints)
{// Initialisation constructor
    Semester = pSemester;
    SubjectCode[4] = pIDNumber[4];
    Name[26] = pName[26];
    CreditPoints = pCreditPoints;
}

int Subject::GetSemester()
{
   return Semester;
}

void Subject::setSemester(int semester)
{
   Semester = semester;
}

void Subject::setIDNumber(char pID[])
{
   memcpy(SubjectCode, pID, sizeof(SubjectCode));
}

char *Subject::GetIDNumber()
{
   return SubjectCode;
}

void Subject::setName(char pName[])
{
   memcpy(Name, pName, sizeof(Name));
}

char *Subject::GetName()
{
   return Name;
}

void Subject::setCreditPoints(int pCreditPoints)
{
   CreditPoints = pCreditPoints;
}

int Subject::getCredPoints()
{
   return CreditPoints;
}

