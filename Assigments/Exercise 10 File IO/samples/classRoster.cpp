//Objective:  create a class roster
//Name: Teacher
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> 
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
  string name; //each student's name [first name, middle initial, last name]
  ofstream fout; //represents output file
  string oFileName = "classRoster.txt"; //output filename
  string objective = "create a class roster"; //program objective
  string instructions = ""; //user instructions

  introduction(objective, instructions); //user introduction

  //input student name(s)
  cout << "What is your name[first name, middle initial, last name]? "; 
  getline(cin, name); 
  
  //output and append new student name to end of classRoster file
  fout.open(oFileName.c_str(), ios::app); 
  if (!fout.good()) throw "I/O error"; 
  fout << name << endl; 
  fout.close(); 
  cout << name << " was added to the file " << oFileName << ". Use your editor to check this file." << endl;

}//main

// introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective from main program
  //ins is the user instructions

  //output user introduction
  cout << "Objective: This program will ";
  cout << obj << endl; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl; 
  cout << ins << endl << endl;
}//introduction