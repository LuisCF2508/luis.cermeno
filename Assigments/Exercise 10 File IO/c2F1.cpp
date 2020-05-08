//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <fstream>
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
  string objective = "Objective: This program will Celcius to Farenheit degrees from a list extracted from a text file named  temps.txt.\n";
  double dCel;// (decimal) Celcius degrees extracted from text file
  double dFar;// (decimal) Farenheit degrees extracted from text file

  //user introduction
  introduction(objective);

  ifstream fin; // creating the object fin
  fin.open("temps.txt"); // opening the text file
  if(!fin.good()) throw "I/O error"; // error handling

  //file input and output
  
  while(fin.good()) // check if the end-of-file is reached
  {
    //read each line
    fin >> dCel;
    fin.ignore(1000,10);
    if (dCel == - 999) break; //check for the sentinel value
    //calculation
    dFar = ( (9.0/5) * dCel ) + 32;

    //output
    cout << endl << "Celcius: " << dCel << " is ";
    cout.setf(ios::fixed|ios::showpoint); //turn on formatting
    cout << setprecision(2); // set 2 decimals for precision
    cout << "Farenheit: " << dFar;
    cout.unsetf(ios::fixed|ios::showpoint); // turn off formating
  }
  fin.close(); // close the file
  cout << endl;
 

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