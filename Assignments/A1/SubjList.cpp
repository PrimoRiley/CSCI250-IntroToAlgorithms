// See assignment specs

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Subject.h"
#include "SubjList.h"
using namespace std;

const char SUBJECT_FILE[] = "subject.txt";


SubjectList::SubjectList()
{
   NoOfSubjects=0;
   *Subjects = NULL;
   ReadFile();
}

SubjectList::~SubjectList()
{

}

int SubjectList::ReadFile()
{// Loads subject array from file
    //crete variables to hold data
    char subID[4];
    char subName[26];
    int csemester;
    int cCreditPoints;
    char throwaway[12];
    
    ifstream inf ("subject.txt");
    int i =0;
    while(inf.peek() != EOF) //reads from file and stores information
    {
       //read
       Subjects[i] = new Subject;
        inf >> subID;
        inf.getline(throwaway, 12); 
        inf.getline(subName, 26); 
        inf >> cCreditPoints >> csemester;
        //store 
        Subjects[i]->setIDNumber(subID);
        Subjects[i]->setName(subName);
        Subjects[i]->setCreditPoints(cCreditPoints);
        Subjects[i]->setSemester(csemester);
        i++;
    }
    NoOfSubjects = i;
    inf.close();


   return 1;
}

void SubjectList::PrintSubjectsInSemester(int Semester)
{// Prints all subjects that match Semester
   cout<<"Subjects offered are:\n";
   for(int i=0;i<NoOfSubjects;i++){
      if(Subjects[i]->GetSemester()==Semester){
         cout<<Subjects[i]->GetIDNumber()<<'\t'<<Subjects[i]->GetName()<<endl;
      }
   }
}

int SubjectList::PrintSubjectDetails(char SubjectCode[])
{// Prints subject code & name of subject which matches SubjectCode
    for(int x=0; x<NoOfSubjects; x++)
    {
        if(strcmp(SubjectCode, Subjects[x]->GetIDNumber()) == 0)
        {
         cout<<"Subject Code: "<<Subjects[x]->GetIDNumber()<<endl;
         cout<<"Subject Name: "<<Subjects[x]->GetName()<<endl<<endl;
        }
    }
   return 1;
}

int SubjectList::getCreditPoints(char* SubIDs)
{
   cout<<"Sub List Credit points funct "<<endl;
   cout<<Subjects[13]->GetIDNumber()<<endl;
   cout<<NoOfSubjects<<endl;
   int g;
   for(g = 0; g<NoOfSubjects; g++)
   {
      cout<<" g = "<<g<<endl;
      if(strcmp(Subjects[g]->GetIDNumber(), SubIDs))
      {
         cout<<"Subject Code: "<<Subjects[g]->GetIDNumber()<<endl;
         //cout<<Subjects[g]->getCredPoints()<<endl;
         //return Subjects[g]->getCredPoints();
         //g++;
      }
   }
   cout<<"END Sub List Credit points funct "<<endl;
   return 0;
}

Subject& SubjectList::operator[](int idx)
{
    return *Subjects[idx];
}





