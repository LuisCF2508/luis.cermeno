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
void introduction(string obj);//user introduction

//main program
int main()
{
  //Data
  string objective = "Calculate how many weeks it would take to be a billionaire, millionaire and a thousandaire if each week that passes the amount saved duplicates.\n";
  double amountSaved = 0;
  double amountWeek = 0.05;
  int numberWeek = 0; // (integer) number of weeks that has passed so far
  int thousandWeeks; // (integer) number of weeks that will take to become a thousandaire
  int millionWeeks; // (integer) number of weeks that will take to become a millionaire
  int billionWeeks; // (integer) number of weeks that will take to become a billionaire
  bool thousand_notFoundYet = true; // (boolean) is false if the amount of weeks to be a thousandaire has been found
  bool million_notFoundYet = true; // (boolean) is false if the amount of weeks to be a millionaire has been found
  bool billion_notFoundYet = true; // (boolean) is false if the amount of weeks to be a billionaire has been found

  //user introduction
  introduction(objective);

  //calculation of number of weeks

  do
  {
    numberWeek++;
    amountSaved = amountSaved + amountWeek;
    if (amountSaved > 1000 && thousand_notFoundYet) 
    {
      cout << "In " << numberWeek << " weeks, I will be a thousandaire!" << endl;
      thousand_notFoundYet = false;
    }

    if (amountSaved > 1000000 && million_notFoundYet)
    {
      cout << "In " << numberWeek << " weeks, I will be a millionaire!" << endl;
      million_notFoundYet = false;
    }

    if (amountSaved > 1000000000) 
    {
      cout << "In " << numberWeek << " weeks, I will be a billionaire!" << endl;
      billion_notFoundYet = false;
    }
    amountWeek = amountWeek * 2;
  } while (billion_notFoundYet);

}//main


//introduction function
void introduction(string obj)//user introduction
{
  //data
  //obj is the program objective

  //introduction
  cout << obj; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function