#include<iostream>
using namespace std;

int count(const string&, char);
int count(const string&, char, int);


int main()
{
    string s;
    char ch;
    cout<<"Enter a string and a character"<<endl;
    cin>>s>>ch;
    cout<<"Number of "<<ch<<"'s in "<<s<<" is "<<count(s, ch)<<endl;
}

int count(const string& s, char a)
{
    return count(s, a, s.size() - 1);
}

int count(const string& s, char a, int high)
{
    if(high < 0)
    {
        return 0;
    }
    else
    {
        int c = count(s, a, high-1);
        if (s[high] == a)
        {
            c++;
        }
        return c;
    }

}

