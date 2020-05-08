//Objective:  output a right triangle of user selected number of rows
//Name: Teacher
//Course: COMSC-110-8269
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
  int n; // print this many rows

  // introduction
  cout << "Objective: This program will serve as a template for all programs\n written in this course.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //input user selected number of rows to output
  cout << "How many rows to print? ";
  cin >> n;
  cin.ignore(1000, 10);

  //output right triangle with user selected number of rows
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < (i + 1); j++)
    {
      cout << '*';
    }//for j inner loop
    cout << endl;
  } // for i outer loop
} // main
