// Search for "WRITE YOUR CODE" to complete this program
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template <typename ForwardIterator, typename T>
void replace(ForwardIterator beg, ForwardIterator end,
  const T &oldValue, const T &newValue);

template <typename ForwardIterator, typename T>
void replace(ForwardIterator beg, ForwardIterator end,
  const T &oldValue, const T &newValue)
{
  while(beg != end)
  {
      if(*beg == oldValue)
          *beg = newValue;
      ++beg;  
  }
}

template <typename ForwardIterator, typename boolFunction, typename T>
void replace_if(ForwardIterator beg, ForwardIterator end,
  boolFunction f, const T &newValue);

template <typename ForwardIterator, typename boolFunction, typename T>
void replace_if(ForwardIterator beg, ForwardIterator end,
  boolFunction f, const T &newValue)
{
  while(beg != end)
  {
      if(f(*beg))
        *beg = newValue;
      ++beg;  
  }
}

bool greaterThan4(double value)
{
  return value > 4;
}

int main()
{
  double values[6] = {0};
  double values1[6] = {0};
  cout << "Enter six integers: ";
  for (unsigned i = 0; i < 6; i++)
  {
    cin >> values[i];
    values1[i] = values[i];
  }
  ostream_iterator<double> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 6, output);

  replace(values, values + 6, values[3], 51.5);
  cout << "\nAfter the replace function, values: ";
  copy(values, values + 6, output);

  cout << "Initial contents, values1: ";
  copy(values1, values1 + 6, output);

  replace_if(values1, values1 + 6, greaterThan4, 555);
  cout << "\nAfter the replace function, values: ";
  copy(values1, values1 + 6, output);

  return 0;
}
