//Objective:  Convert Fahrenheit degrees temperature to Celsius degrees temperature
//Name: Teacher 1234567
//Course: COMSC-110-5003
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data
  double c; // degrees Celsius
  double f; // degrees Fahrenheit

  // introduction
  cout << "Objective: This program will Convert Fahrenheit degrees temperature to Celsius degrees temperature.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  // input degrees Fahrenheit temperature
  cout << "Enter the temperature in degrees Fahrenheit: ";
  cin >> f;
  cin.ignore(1000,10);

  //calculate degrees Celsius temperature and output results
  c = 5.0 * (f-32.0) / 9.0;
  cout << f << " degrees Fahrenheit is " << c << " degrees Celsius!" << endl;

}//main