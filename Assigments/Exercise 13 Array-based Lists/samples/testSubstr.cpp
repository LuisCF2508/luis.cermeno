//Objective:  extract last 4 characters of a string
//Name: Teacher
//Course: COMSC-110-1021
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
void introduction(string obj, string dir); //user introduction

//main program
int main()
{
  //Data
  string objective = "extract last 4 characters of a string"; //program objective
  string directions = ""; //user instructions if needed
  string fileName = "x.txt"; //programmer selected fileName
  string fileExtension; //last 4 characters of fileName

  introduction(objective, directions); //user introduction

  //get fileName fileExtension
  fileExtension = fileName.substr(fileName.length()-4, 4);
  cout << "fileName = " << fileName << endl;
  cout << "fileExtension = " << fileExtension << endl;
}//main

// introduction
void introduction(string obj, string dir)
{
  //data
  //obj is the program objective from main program
  //dir is the optional user instructions

  //output user introduction
  cout << "Objective: This program will ";
  cout << obj << endl; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << endl << dir << endl << endl;
}//introduction
