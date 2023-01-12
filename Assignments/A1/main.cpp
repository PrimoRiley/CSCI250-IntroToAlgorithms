// main.cpp - CSCI112 S, Antoun
// Student Name       : <Riley Primeau>
// Student Number     : <>
// Email              : <rlprimeau@>
// Date Conpleted     : <date of completion>
// Description        : User interface for University Enrolment System
// ****** NOTE: DO NOT MODIFY ANYTHING IN THIS FILE! ******
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "StudList.h"
#include "SubjList.h"
using namespace std;

char Menu();
void ListSubjectsInSemester(SubjectList &Subject);
void ListSubjectDetails(SubjectList &Subject, StudentList &Students);
void ListStudentDetails(StudentList &Students);
void ListStudentsBasedOnCredit(SubjectList &Subjects, StudentList &Students);

int main()
{
	StudentList Students;
	SubjectList Subjects;

	if (!Students.ReadFile()){
		cout<< "Reading students failed!"<< endl;
		exit(1);
	}
	if (!Subjects.ReadFile()){
		cout<< "Reading subjects failed!"<< endl;
		exit(1);
	}

	char Choice;
	while(1){
		Choice = Menu();
		switch(Choice){
			case '1': ListSubjectsInSemester(Subjects); break;
			case '2': ListStudentDetails(Students); break;
			case '3': ListSubjectDetails(Subjects, Students); break;
			case '4': ListStudentsBasedOnCredit(Subjects, Students); break;
			case '5': break;
			default: cout << "Invalid choice!\n\n";
		}
		if (Choice=='5') break;
	}
	cout << "Thank you for using University Enrolment System\n";
	return 0;
}

char Menu()
{
	char Option[20];
	cout << "*** University Enrolment System ***\n\n";
	cout << "1. List all subjects offered in a particular semester\n";
	cout << "2. List the subjects that a particular student has taken\n";
	cout << "3. List all students enrolled in a particular subject\n";
	cout << "4. List students that have taken less than n credit points\n";
	cout << "5. Exit from the system\n";
	cout << "Enter your choice (1..5): ";
	cin.getline(Option,20);
	cout<<endl;
	return Option[0];
}

void ListSubjectsInSemester(SubjectList &Subjects)
{// Asks for semester number and prints all matching subjects
	char Option[20];
	for(;;){
		cout<<"Enter :\n";
		cout<<"0 : for annual subject\n";
		cout<<"1 : for first semester\n";
		cout<<"2 : for second semester\n";
		cout<<"Which semester : ";
		cin.getline(Option,20);
		if(Option[0]=='q') break; // quit option
		cout<<endl;
		int Semester = Option[0]-'0';
		if(Semester>=0&&Semester<=2){
			Subjects.PrintSubjectsInSemester(Semester);
			break;
		}
		cout<<"Invalid choice!\n\n";
	}
	cout<<endl<<endl;
}

void ListStudentDetails(StudentList &Students)
{// Asks for student's ID and prints student's name and subjects
	char StudentID[20];
	for(;;){
		cout<<"Enter student's ID: ";
		cin.getline(StudentID,20);
		cout<<endl;
		if(StudentID[0]=='q') break; // quit option
		if(Students.PrintStudentDetails(StudentID))
			break;
		cout<<"This student does not exist!\n\n";
	}
	cout<<endl<<endl;
}


void ListSubjectDetails(SubjectList &Subjects, StudentList &Students)
{// Asks for subject code and prints subject's name and students
	char SubjectCode[20];
	for(;;){
		cout<<"Which subject code do you want to display? ";
		cin.getline(SubjectCode,20);
		if(SubjectCode[0]=='q') break; // quit option
		cout<<endl;
		if(Subjects.PrintSubjectDetails(SubjectCode)){
			Students.PrintStudentsInSubject(SubjectCode);
			break;
		}
		cout<<"Subject cannot be found!\n\n";
	}
	cout<<endl<<endl;
}


void ListStudentsBasedOnCredit(SubjectList &Subjects, StudentList &Students)
{// Asks for CP limit and prints all students doing less than CP limit
	char Input[20];
	for(;;){
		cout<<"Enter credit point limit: ";
		cin.getline(Input,20);
		if(Input[0]=='q') break; // quit option
		int CPLimit = atoi(Input);
		cout<<endl;
		if(CPLimit>0 && CPLimit < 30){
			Students.PrintStudentsBasedOnCredit(CPLimit,Subjects);
			break;
		}
		cout<<"Invalid Input!\n\n";
	}
}


