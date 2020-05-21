//Objective:  add 2 numbers input from user
//Name: Teacher
//Course: COMSC-110-8215
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
  //data
  int n1; //first number from user
  int n2; //second number from user
  int sum; //sum of first and second numbers

  // output my name and objective and program information
  cout << "Objective: This program will add 2 numbers.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: VC++ 2010 Express\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << "You will be asked to provide 2 whole numbers and the result will be the sum of these numbers." << endl << endl;

  //user input
  cout << "Enter a number [any positive or negative whole number]: ";
  cin >> n1;
  cin.ignore(1000, 10);
  cout << "Enter another number [any positive or negative whole number]: ";
  cin >> n2;
  cin.ignore(1000, 10);

  //calculate sum
  sum = n1 + n2;

  //output results
  cout << "Simple addition with console input" << endl;
  cout << n1 << " + " << n2 << " = " << sum << endl;

}//main