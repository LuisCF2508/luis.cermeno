//Objective: Prompt a person for their lucky number,favorite movie, age, first letter on their name and then output the values of the variables.
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <string>
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
  int luckyNumber; //(integer) user's lucky number.
  string favMovie; //(text) user's favorite movie name.
  double age; //(decimal) user's age
  char initial; //(character) user's first letter of their name.

  // Introduction
  cout << "Objective: Prompt a person for their lucky number,favorite movie, age, first letter on their name and then output the values of the variables.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // User input of luckyNumber,favMovie,age,initial
  cout << "Enter your lucky number as whole number [8]: ";
  cin >> luckyNumber;
  cin.ignore(1000,10);
  cout << "Enter you favorite movie name [Forrest Gump]: ";
  getline(cin,favMovie);
  cout << "Enter your age in years[20]: ";
  cin >> age;
  cin.ignore(1000,10);
  cout << "Enter the first letter on yout name [L]: ";
  cin >> initial;
  cin.ignore(1000,10);

  // Output values of luckyNumber,favMovie,age,initial
  cout << endl;
  cout << "Your lucky number is " << luckyNumber << " ,your favorite movie is " << favMovie << " ,you are " << age << " years old and the first letter of your name is " << initial;

}//main