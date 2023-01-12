#include <iostream> // Exercise09_02
using namespace std;

class EvenNumber
{
  public:
    int value;
    EvenNumber();
    EvenNumber(int);
    int getValue();
    int display(EvenNumber x);
    EvenNumber getNext();
    EvenNumber getPrevious();

};

EvenNumber:: EvenNumber()
{
    value = 0;
}

EvenNumber:: EvenNumber(int v)
{
    value = v;
}

int EvenNumber::getValue()
{
    return value;
}

int EvenNumber:: display(EvenNumber x) //I had to create an additional function that could return the int value of the new object
{
    return x.value;
}

EvenNumber EvenNumber::getNext()
{
    EvenNumber nextNum(value + 2);
    return nextNum;
}

EvenNumber EvenNumber::getPrevious()
{
    EvenNumber prevNum(value - 2);
    return prevNum;
}


int main() {

  EvenNumber num(16);

  cout<<num.display(num.getNext())<<endl;
  cout<<num.display(num.getPrevious())<<endl;

  num.getNext();
  cout<<nextNum.value<<endl;


  //cout<<num.getNext()<<endl; was what I tried first and then several other things until I created the new function
  //but now I am wondering if there are any better ways to go about displaying a class object


  return 0;
}
