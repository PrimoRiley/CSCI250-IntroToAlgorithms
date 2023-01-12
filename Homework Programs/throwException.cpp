#include<iostream>
#include<stdexcept>
#include<string>
#include<cctype>
using namespace std;

int hex2Dec(const string& hexString);
int convertHexToDec(char ch);

int hex2Dec(const string& hexString) 
{
  int value = 0; 
  for (unsigned int i = 0; i < hexString.size(); i++)
     value = value * 16 + convertHexToDec(toupper(hexString[i]));
  return value;
}

// The function returns an int for a hex digit. 
// Throws an invalid_argument("Not a hex number") if the hex character is invalid
int convertHexToDec(char ch)
{ 
  if (ch >= '0' && ch <= '9')
        return (int)(ch - '0');
  if (ch >= 'A' && ch <= 'F')
        return (int)(ch - 'A' + 10);
  if (ch >= 'a' && ch <= 'f')
        return (int)(ch - 'a' + 10);
  throw invalid_argument("Not a hex number");
}

int main()
{
  string hexString;
	cout<<"Enter hex number as a string: ";
  cin>>hexString;
  try
  {
    cout<<hex2Dec(hexString)<<endl;
  }
  catch(invalid_argument& ex)
  {
    cout<<ex.what()<<endl;
  }

  return 0;
}