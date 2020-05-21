//Objective:  calculate the miles/gallon depending on user input of fuel tank capacity, miles driven, and gallons of fuel used.
//Name: Teacher
//Course: COMSC-110-8269
//Compiler: TDM MinGW
//Editor: NotePad

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
  // output my name and objective and program information
  cout << "Objective: This program will calculate the miles/gallon \n depending on user input of fuel tank capacity, \n miles driven, and gallons of fuel used.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: VC++ 2013 Express\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //data
  int fuelTankCapacity; // = how many gallons fuel tank holds (integer)
  double milesDriven; // = how many miles did the user drive (decimal)
  double gallonsUsed; // = how many gallons of fuel used on trip (decimal)
  double mpg; // = miles per gallon vehicle performance on trip (decimal)
  double range; // = miles you can drive based on fuel remaining in tank (decimal)
  double fuelRemaining; // = gallons of fuel left in the tank after trip (decimal)


  //input from user fuelTankCapacity, milesDriven, gallonsUsed
  cout << "How many gallons fuel does your vehicle tank hold? ";
  cin >> fuelTankCapacity;
  cin.ignore(1000, 10);
  cout << "How many miles did you drive your vehicle? ";
  cin >> milesDriven;
  cin.ignore(1000, 10);
  cout << "How many gallons used on this trip? ";
  cin >> gallonsUsed;
  cin.ignore(1000, 10);


  //calculate mpg = milesDriven / gallonsUsed
  //calculate fuelRemaining = fuelTankCapacity - gallonsUsed
  //calculate range = fuelRemaining * mpg
  mpg = milesDriven / gallonsUsed;
  fuelRemaining = fuelTankCapacity - gallonsUsed;
  range = fuelRemaining * mpg;

  //output mpg, fuelRemaining, range with labels
  cout << endl << "Your fuel tank capacity is " << fuelTankCapacity << endl;
  cout << "Miles driven: " << milesDriven << endl;
  cout << "Gallons used on this trip: " << gallonsUsed << endl;
  cout << "MPG: " << mpg << endl;
  cout << "Fuel remaining in fuel tank: " << fuelRemaining << " gallons" << endl;
  cout << "Range of vehicle with fuel remaining: " << range << endl;

}//main