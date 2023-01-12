/* 
    Assignment 4 | Riley Primeau
    After adapting HeapSort and Quicksort to work with an STL container, vector, I compared the
    time it took for each of these methods with the STL sort algorithm. My Program majority of 
    the time shows that the HeapSort just barely takes more time then the STL algorithm
    sort. Quicksort proves to be faster then both of these sorting methods by a good bit. That 
    being said, I would mostly use the STL algorithm sort since it is very convenient and in this
    case proved to be faster then the HeapSort. However, when there is the need to focus on efficiency
    I would no doubt go with QuickSort. 

    One thing to note - the program sorts 2000 int values but only outputs the first 10 for readability. 
*/
 
#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include "myStack.h"
#include "infixToPostfix.h"
#include "HeapSort.h"
#include "QuickSort.h"
  
using namespace std; 

int main(int argc, const char * argv[])
{
    infixToPostfix  InfixExp;
    string infix;

    srand (time(NULL));
/*
    ifstream infile;

    infile.open("infixData.txt");

    if (!infile)
    {
        cout << "Cannot open input file. Program terminates!!!" << endl;
        return 1;
    }

    getline(infile, infix);

    while (infile)
    {
        InfixExp.getInfix(infix);
        InfixExp.showInfix();
        InfixExp.showPostfix();
        cout << endl;

        getline(infile, infix);
    }

    infile.close();
*/
    cout<<"----TASK 1---"<<endl;
    cout << "Enter an Infix expression followed by a semicolon:\n";
    getline(cin, infix);
    InfixExp.getInfix(infix);
    InfixExp.showInfix();
    InfixExp.showPostfix();
    cout << endl;


    cout<<"----TASK 2----"<<endl;
    vector<int> numbers(2000);
    for(int i=0; i<2000; i++)
        numbers[i]=rand() % 3000 + 1;
    
    cout<<"HEAPSORT"<<endl;
    cout<<"Unsorted: ";
    printArray(numbers, 10);

    auto start = chrono::high_resolution_clock::now();
    heapSort(numbers, 2000);
    auto end = chrono::high_resolution_clock::now();

    cout<<"Sorted: ";
    printArray(numbers, 10);
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
  
    cout << "Time taken by program is :" << fixed << time_taken << setprecision(9);
    cout << " sec" << endl << endl;

    cout<<"STL ALGORITHM SORT"<<endl;
    for(int i=0; i<2000; i++) //make values random again
        numbers[i]=rand() % 3000 + 1;
    cout<<"Unsorted: ";
    printArray(numbers, 10);

    auto begin = chrono::high_resolution_clock::now();
    sort(numbers.begin(), numbers.end());
    auto conclude = chrono::high_resolution_clock::now();

    cout<<"Sorted: ";
    printArray(numbers, 10);

    double duration = chrono::duration_cast<chrono::nanoseconds>(conclude - begin).count();
    duration *= 1e-9;
  
    cout << "Time taken by program is :" << fixed << time_taken << setprecision(9);
    cout << " sec" << endl<<endl;

    cout<<"QUICK SORT (Bonus Task)"<<endl;
    for(int i=0; i<2000; i++) //make values random again
        numbers[i]=rand() % 3000 + 1;
    cout<<"Unsorted: ";
    printArray(numbers, 10);

    auto go = chrono::high_resolution_clock::now();
    quickSort(numbers, 0, 2000);
    auto stop = chrono::high_resolution_clock::now();

    cout<<"Sorted: ";
    printArray(numbers, 10);

    double timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stop - go).count();
    timeElapsed *= 1e-9;
  
    cout << "Time taken by program is :" << fixed << timeElapsed << setprecision(9);
    cout << " sec" << endl<<endl;
    return 0;
}
