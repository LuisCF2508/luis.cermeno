#include <iostream>
using namespace std;

int main()
{
int a;
int b;
int c;
int temp; // temporary variable to store the greatest value when comparing a pair of number
//the highest value will be in c


cout << "Objective: Compare 3 numbers" << endl;
cout << "Enter your numbers : " << endl;
cin >> a;
cin.ignore(1000,10);
cin >> b;
cin.ignore(1000,10);
cin >> c;
cin.ignore(1000,10);

if (a > b)
{
temp = a; // preparing for the swap, now the value of a is secured in temp.
a = b;
b = temp; // now a and b have swapped values.
}


if (a > c)
{
temp = a; // preparing for the swap, now the value of a is secured in temp.
a = c;
c = temp; // now a and b have swapped values.
}

if (b > c)
{
temp = b; // preparing for the swap, now the value of a is secured in temp.
b = c;
c = temp; // now a and b have swapped values.
}

cout << "The order from least to greatest is : " << a << " < " << b << " < "  << c << endl; 

}