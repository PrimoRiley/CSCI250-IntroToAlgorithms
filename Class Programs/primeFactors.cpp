#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

void primeFactors(int, stack<int>&);

int main()
{
    int n;
    stack<int> primeStack;
    cout<<"Enter a positive integer: ";
    cin>>n;
    primeFactors(n, primeStack);
    cout<<"Prime Factors in decending order are: ";
    while(!primeStack.empty())
    {
        cout<<primeStack.top()<<" ";
        primeStack.pop();
    }
    cout<<endl;

}

void primeFactors(int n, stack<int>& primeStack)
{
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        primeStack.push(2);
        n = n/2; 
    } 
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            primeStack.push(i);
            n = n/i; 
        } 
    } 
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2)
        primeStack.push(n);
}