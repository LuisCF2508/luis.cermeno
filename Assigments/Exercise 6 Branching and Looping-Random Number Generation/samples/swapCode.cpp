#include <iostream>
using namespace std;

int main() //swap code to sort three numbers (page 99 Burns)
{
  int a = 9;
  int b = 5;
  int c = 3;
  int temp;

  //Swap elements
  if (a > b)
  {
    temp = a;
    a = b;
    b = temp;
  }
  if (a > c)
  {
  temp = a;
  a = c;
  c = temp;
  }

  if (b > c)
  temp = b;
  b = c;
  c = temp;
  //output result
  cout << "order from lowest to highest: " << a << " < " << b << " < " << c << endl;
} // the highest value is now in "c"