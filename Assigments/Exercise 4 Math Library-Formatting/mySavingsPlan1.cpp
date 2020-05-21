//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <iomanip>
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
  //Data definitions

  int deposit = 100; //how much money you will add to your savings account each month (integer)
  double interestRate = 0.075; //annual interest rate you can expect (check google.com: for example 0.04 is 4%) (decimal)
  int years = 10; //how many more years until you retire (integer)
  double amountSaved; //how much money you have when you retire (decimal) (formatted to 2 digits past decimal point)
  int time; //number of months in years (integer)

  //User introduction
  cout << endl;
  cout << "Objective: calculate how much money to save every month for number of years before retirement and how much money would you have when you retire.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Calculate amount of money to save every month

  interestRate = interestRate / 12;
  time = years * 12;
  amountSaved = deposit * ((pow(1 + interestRate, time) - 1) / interestRate);
  interestRate = (interestRate * 100) * 12;

  //Output result

  cout << "In " << years << " years at " << interestRate << "%, $" << deposit << " deposited per month will grow to $";
  cout.setf(ios::fixed|ios::showpoint); // turning on formating for the upcoming output
  cout << setprecision(2); // formating the outpout so that amountSaved is displayed with two digits after decimal point.
  cout << amountSaved << endl;
}//main