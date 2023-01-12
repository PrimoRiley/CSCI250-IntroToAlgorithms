/*
Riley Primeau
primeauriley@gmail.com
*/

#include<iostream>
#include<string>
#include<fstream>
#include<chrono>

using namespace std;

int main()
{
    ifstream ifs("Text.txt");
    string text( (istreambuf_iterator<char>(ifs) ),
                  (istreambuf_iterator<char>()    ) );
    string pattern = "10001";

    
    int occurances = 0;
    int j = 0;
    int i = 0;

    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    while (i < text.length())
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            i = i - (j - 1);
            j = 0;
        }
        if(j == pattern.length())
        {
            cout << i - pattern.length() << endl;
            occurances++;
            j = 0;
            cout<<"i: "<<i<<endl;
            cout<<"j: "<<j<<endl;

        }

    }
    cout<<"Occurances: "<<occurances << endl;

    end = chrono::high_resolution_clock::now();     
    chrono::duration<double> elapsed_seconds = end - start;
    //ends timer

    cout<<"Time to read: "<<elapsed_seconds.count()<<endl<<endl;
}