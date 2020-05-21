//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <iostream>
#include <iomanip>
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
  string objective = "Objective: This program will show the round-off error in C++.\n";
  double x;

  //user introduction
  introduction(objective);

  cout.setf(ios::fixed|ios::showpoint); 
  cout << setprecision(20) << endl;// this helps to identify that the steps are not exactly 0.2.

  //infinite loop
  for(x = 0; x != 2; x += 0.02) //it never stops cause x is never exactly 2
    cout << x << endl; // the steps are not exactly 0.02, this can be shown in the console output
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