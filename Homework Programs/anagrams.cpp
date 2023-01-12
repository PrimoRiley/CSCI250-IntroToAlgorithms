#include <iostream>

using namespace std;

bool isAnagram(const string& s1, const string& s2);

int main()
{

    string s1, s2;
    cout<<"Enter two strings to test if they are anagrams... "<<endl;
    cout<<"String 1: "<<endl;
    cin>>s1;
    cout<<"String 2: "<<endl;
    cin>>s2;

    //cout<<isAnagram(s1, s2)<<endl;

    if(isAnagram(s1, s2) == 1)
    {
        cout<<endl<<s1<<" and "<<s2<<" are anagrams."<<endl;
    }
    else if(isAnagram(s1, s2) == 0)
    {
        cout<<endl<<s1<<" and "<<s2<<" are not anagrams."<<endl;
    }

}


bool isAnagram(const string& s1, const string& s2)
{
    int sameVals;
    for(int i = 0; i<s1.length(); i++)
    {
        for(int j = 0; j<s1.length(); j++)
        {
            if(s2[i] == s1[j])
            {
                sameVals++;
            }

            if(sameVals == s1.length())
            {
                return true;
            }
            else
            {
                return false;
            }

        }

    }

}
