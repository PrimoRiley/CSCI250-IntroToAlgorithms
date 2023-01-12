// See assignment specs

#ifndef _STUDLIST_H
#define _STUDLIST_H

#include "Student.h"
#include "SubjList.h"



const int MAX_STUDENT = 100;


class StudentList
{
   public:
      StudentList();
      ~StudentList();
      int ReadFile();
      void PrintStudentsInSubject(char SubjectCode[]);
      int PrintStudentDetails(char SubjectCode[]);
      void PrintStudentsBasedOnCredit(int CPLimit,SubjectList &Subjects);

   private:
    Student *Students[MAX_STUDENT];
    int NumOfStudents;
    int creditPoints;


};


#endif


