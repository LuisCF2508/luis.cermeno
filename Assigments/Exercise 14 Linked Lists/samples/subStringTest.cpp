//Objective:  substring test
//Name: Teacher
//Course: COMSC-110-5003
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
void introduction(string obj, string ins); //user introduction

//main program
int main()
{
  //Data
  string objective = "substring test"; //program objective
  string instructions = ""; //user instructions if needed
  string fileName = "test.txt";
  string last4; //last 4 characters

  introduction(objective, instructions); //user introduction

  //test string if last 4 characters = ".txt"
  last4=fileName.substr(fileName.length()-4, 4);
  cout << "fileName = " << fileName << endl;
  cout << "last 4 characters is " << last4 << endl;

}//main

// introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective from main program
  //ins is the optional user instructions

  //output user introduction
  cout << "Objective: This program will ";
  cout << obj << endl; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << endl << ins << endl << endl;
}//introduction
