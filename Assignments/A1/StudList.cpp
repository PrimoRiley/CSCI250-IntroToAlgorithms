// See assignment specs

#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "StudList.h"
using namespace std;

const char STUDENT_FILE[] = "student.txt";

StudentList::StudentList()
{
	NumOfStudents = 0;
    ReadFile();
}

StudentList::~StudentList()
{
}

int StudentList::ReadFile()    //can use >> for the numbers but include fin.ignore() to ignore the '/n'
{// Loads Student array from file
    char ID[7];
    char studName[26];
    char throwaway[26];
    char lineContents[30];
    int numSubjects;

    //priming read outside EOF look test
    //enter loop
    //process data read
    //read again

    ifstream stf("student.txt");
    stf >> ID;
    stf.getline(throwaway, 26);
    stf.getline(studName, 26);  //read first student
    int i = 0;
    
    while(stf.peek() != EOF)
    {
        Students[i] = new Student;
        Students[i]->setID(ID);
        Students[i]->setName(studName);  
        stf >> numSubjects;
        stf.getline(lineContents, 30);
        Students[i]->setSubjectIDs(lineContents); 
        //iterate to next student    
        i++; 
        stf >> ID;
        stf.getline(throwaway, 26);
        stf.getline(studName, 26);
        
    }
    NumOfStudents = i;
    stf.close();
	return 1;
}

void StudentList::PrintStudentsInSubject(char SubjectCode[])
{// Prints name of all students enrolled in SubjectCode
    cout<<"Enrolled Students"<<endl;
    cout<<"-----------------"<<endl;
    for(int i = 0; i < StudentList::NumOfStudents; i++)
    {
        if(strstr(Students[i]->getSubjectIDs(), SubjectCode))
        {
            cout<<Students[i]->getName()<<endl;;
        }
    }
    
}

int StudentList::PrintStudentDetails(char StudentID[])
{// Prints name and subjects codes belonging to StudentID
    for(int x=0; x<StudentList::NumOfStudents; x++)
    {
        if(strcmp(StudentID, Students[x]->getID()) == 0)
        {
            cout<<"Student ID: "<<Students[x]->getID()<<endl;
            cout<<"Student Name: "<<Students[x]->getName()<<endl;
            cout<<"Enrolled Subjects:";
            Students[x]->displaySubjects();
            cout<<endl;
            
        }
    }
    return 1;
}

void StudentList::PrintStudentsBasedOnCredit(int CPLimit,SubjectList &Subjects)
{
    int num = 0;
    cout<<"Students who have taken less than "<<CPLimit<<" credit points:"<<endl<<endl;
    for(int x=0; x<NumOfStudents; x++)
    {
        if(Students[x]->GetCreditPoints(Subjects) < CPLimit)
        {
            cout<<setw(30)<<left<<Students[x]->getName()<<setw(20)<<Students[x]->GetCreditPoints(Subjects)<<endl;
            num++;
        }
    }
    cout << "----------------------------------------------------------" << endl;
    cout<<"There are "<<num<<" students in this category."<<endl<<endl;
    
}

