#include <iostream>
using namespace std;

int main() //find max and min without swaping (page 98 Burns)
{
  int a = 9;
  int b = 5;
  int c = 3;
  int max;
  int min;

  //find max and min by comparing each element
  max = a;
  if (max < b) max = b;
  if (max < c) max = c;
  min = a;
  if (min > b) min = b;
  if (min > c) min = c;

  //output result
  cout << "max: " << max << " and min: " << min << endl;
} 