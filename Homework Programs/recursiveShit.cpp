#include<iostream>
#include<string.h>
using namespace std;

void printStars(int);
long long factorial(int n);
int sum(int);
long power(int, int);
bool containsVowel(string);
string replace(string);

int main()
{
    cout<<containsVowel("car")<<endl;
}

string replace(string sentence)
{
    if(sentence.empty()) return sentence;

    string newString;

    if(sentence[0] == ' ') {
        newString.append("*" + replace(sentence.substr(1)));
    } else {
        newString.append(sentence[0] + replace(sentence.substr(1)));
    }

    return newString;
}

bool containsVowel(string s)
{
    if(s.empty()) return false;
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U')
    {
        return true;
    }
    else
    {
        return containsVowel(s.substr(1, s.size()-1));
    }
}

long power(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n-1);
    }
}

int sum(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return n + sum(n-1);
    }
}

void printStars(int n)
{
    if(n > 0)
    {
        cout<<"*";
        printStars(n - 1);
    }
}

long long factorial(int n)
{
    return n * factorial(n-1);
}