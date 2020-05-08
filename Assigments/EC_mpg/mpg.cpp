//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <iomanip>
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
  double maxCap; //(decimal) maximum gallon capacity of the user's car.
  double distanceTravelled; //(decimal) distance already travelled by the user.
  double gallonsUsed; //(decimal) gallon already used in the trip. 
  double efficiency; //(decimal) the miles per gallon ratio of the car.
  double range; //(decimal) the remaining miles the car can travel.

  //User Introduction
  cout << "Objective: Calculate the remaining range of a car given its gas capacity, distance travelled, and gallons used. Author: Luis Cermeno-Farro.\n";
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << endl << "You will be asked to enter some information about your trip. After you type your answers, please hit the ENTER or RETURN key.";

  //Console Input
  cout << endl;
  cout << "Enter the maximum gallon capacity of your car [e.g. 14]:";
  cin >> maxCap;
  cin.ignore(1000,10);
  cout << "How many miles have you already travelled? [e.g. 190.5]:";
  cin >> distanceTravelled;
  cin.ignore(1000,10);
  cout << "How many gallons have you already used? [e.g. 7.1]:";
  cin >> gallonsUsed;
  cin.ignore(1000,10);

  //Calculation of efficiency and range.
  efficiency = distanceTravelled / gallonsUsed;
  range = efficiency * (maxCap - gallonsUsed);

  //Console output of results
  cout.setf(ios::fixed|ios::showpoint); //turning formatting on.
  cout << setprecision(2); // setting the output format to two decimal digits.
  cout << endl << "Your car has an efficiency of " << efficiency << " miles per gallon, which will allow you to travel approximately " << range << " miles more." << endl;

}//main