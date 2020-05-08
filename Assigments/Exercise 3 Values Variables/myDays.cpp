//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

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
  int yearsLived; //(integer) the number of years in which you've lived, including your birth year and.
  int nLeapYears; //(integer) the number os leap years in your life.
  int nDaysBY; //(integer) the number os days in your life.
  int nDaysRemaining; //(integer) the number of days remaining inthe current year after de due date for this lab excluding that day.
  string dateOfBirth = "May 31,1993"; //(string) person's date of birth [month, date, year].
  string dueDate = "September 20, 2014"; //(string) assignment due date [month, date, year].
  int days = 0; //(integer) how many days old a person would be by the due date of the assignment.

  //Introduction
  cout << endl;
  cout << "Objective: Calculate how many days old a person would be by the due date of this assignment.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Input yearsLived, nLeapyears, nDaysBY, nDaysRemaining 
  yearsLived = 22; 
  nLeapYears = 5;
  nDaysBY = 151;
  nDaysRemaining = 102;

  //Calculation of how many the person would be by the due date.
  days = days + (365 * yearsLived);
  days = days +  nLeapYears;
  days = days - nDaysBY;
  days = days - nDaysRemaining;

  //Output values of dateOfBirth, dueDate, days
  cout << endl;
  cout << "Date of Birth: " << dateOfBirth << endl;
  cout << "Due Date: " << dueDate << endl;
  cout << "Age in days: " << days << endl;
  cout << endl;



}//main