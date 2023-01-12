// See assignment specs

#ifndef _STUDENT_H
#define _STUDENT_H

#include "SubjList.h"


class Student
{
   public:
      Student();
      Student(char pID[], char pName[], char pSubjectIDs[][4],int pNumSubjects);
      int GetCreditPoints(SubjectList &Subjects);
      char* getID();
      void setID(char pID[]);  //implement
      char* getName();
      void setName(char pName[]); //implement
      char* getSubjectIDs();
      void displaySubjects();
      void setSubjectIDs(char pSubjectIDs[]); //implement
      int getNumSubjects();
      void setNumSubjects(int pNumSubjects); //implement

   private:
      char ID[7];
      char Name[26];
      char SubjectIDs[7][4];
      int  NumSubjects;
};


#endif

