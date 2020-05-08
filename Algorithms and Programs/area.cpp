//Objective:  calculate the area of a circle
//Name: Teacher 1234567
//Course: COMSC-110-5003
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
#include <cmath>

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
  double r; //radius of circle
  double area; //area of circle
  double pi = 4 * atan(1.0); // 4 times the angle whose tangent is 1

  // introduction
  cout << "Objective: This program will calculate the area of a circle.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  // input a circle's radius
  cout << "Enter the radius of a circle: ";
  cin >> r;
  cin.ignore(1000,10);

  //calculate the area of the circle and output results
  area = pi * r * r;
  cout << " The area of the circle is " << area << endl;

}//main