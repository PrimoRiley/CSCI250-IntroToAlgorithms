#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
using namespace std;

class HexFormatException : public runtime_error
{
public:
  HexFormatException(char ch) : runtime_error("Not a hex number")
  {
  }

  char getCh()
  {
    return ch;
  }

private:
  char ch;
};

// The function returns an int for a hex digit. 
// Throws HexFormatException(ch) if the hex character is invalid
int convertHexToDec(char ch)
{
  if (ch >= '0' && ch <= '9')
        return (int)(ch - '0');
  if (ch >= 'A' && ch <= 'F')
        return (int)(ch - 'A' + 10);
  if (ch >= 'a' && ch <= 'f')
        return (int)(ch - 'a' + 10);
  throw HexFormatException(ch);
}

int hex2Dec(const string& hexString)
{
  int value = convertHexToDec(hexString[0]);
  for (int i = 1; i < hexString.size(); i++)
  {
    value = value * 16 + convertHexToDec(hexString[i]);
  }

  return value;
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
  catch (runtime_error& ex)
  {
    cout<<ex.what()<<endl;
  }

  return 0;
}