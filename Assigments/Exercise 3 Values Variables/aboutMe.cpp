//Objective:  Output predetermined values for a person's lucky number,amount saved by the end of life, favorite movie, one initial from ther name.
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
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
  //Data
  int luckyNumber = 8; // (integer) represents a person's lucky number.
  double amountSaved = 1000000000.0; // (decimal) represents how much money a person will have saved by the end of their life.
  string favMovie = "Forrest Gump"; // (text) represent a person's favorite movie.
  char initial = 'L'; // (character) one initial from a person's fist, middle, or last name.
  
  // introduction
  cout << endl;
  cout << "Objective: This program output predetermined values for a person's lucky number,amount saved by the end of life, favorite movie, one initial from ther name.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //output with labels the values of luckyNumber, amountSaved, favMovie, initial
  cout << "Your lucky number is " << luckyNumber << endl;
  cout << "The amount you will save by the end of your life is " << amountSaved << endl;
  cout << "Your favorite movie is " << favMovie << endl;
  cout << "Your initial from yout first, middle , or last name is " << initial << endl;
  cout << endl;

}//main