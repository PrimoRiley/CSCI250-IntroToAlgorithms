// See assignment specs

#ifndef _SUBJLIST_H
#define _SUBJLIST_H

#include "Subject.h"


const int MAX_SUBJECT = 100;

class SubjectList
{
   public:
      SubjectList();
      ~SubjectList();
      int ReadFile();
      void PrintSubjectsInSemester(int Semester);
      int PrintSubjectDetails(char SubjectCode[]);
      int getCreditPoints(char* SubIDs); //implement
      Subject& operator[](int);

   private:
      Subject *Subjects[MAX_SUBJECT];
      int NoOfSubjects;
};

#endif

