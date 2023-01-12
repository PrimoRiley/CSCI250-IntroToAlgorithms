// See assignment specs

#ifndef _SUBJECT_H
#define _SUBJECT_H

class Subject
{
   public:
      Subject();
      Subject(int pSemester,char pIDNumber[4],char pName[26],int pCreditPoints);
      int GetSemester();
      void setSemester(int);
      char *GetIDNumber();
      void setIDNumber(char pID[]);
      char *GetName();
      void setName(char pName[]);
      void setCreditPoints(int);
      int getCredPoints();

   private:
      int Semester;
      char SubjectCode[4];
      char Name[26];
      int CreditPoints;
};



#endif

