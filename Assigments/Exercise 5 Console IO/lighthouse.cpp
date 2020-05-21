//Objective: Determine how far away a boat can see a lighthouse at sea. 
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
#include <string>
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
  double height; // (decimal) height of the lighthouse entered by the user.
  double distance; // (decimal) maximun distance from what the lighthouse can be seen, calculated by the program.


  // Introduction
  cout << "Objective: Determine how far away a boat can see a lighthouse at sea.Author: Luis Cermeno\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // User input of height
  cout << "What's the lighthouse height in feet? [55.5]:";
  cin >> height;
  cin.ignore(1000,10);

  // Calculation of distance
  distance = sqrt(height*0.8);

  // Output value of distance and height
  cout << setprecision(15); //height has to be shown exactly as the user input it, we are considering the user won't input a number with more than 15 digits
  cout << "A " << height << " foot tall lighthouse can be seen from "; 
  cout.setf(ios::fixed); //setting formatting on to show distance rounded to nearest whole number
  cout << setprecision(0); //setting no decimals
  cout << distance << " miles away.";
  cout << endl;
}//main