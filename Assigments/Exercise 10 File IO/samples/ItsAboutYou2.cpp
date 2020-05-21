//Objective:  input 4 values of different data types from input file
//Name: Teacher
//Course: COMSC-110-8076
//Compiler: MinGW
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
void introduction(string obj,string ins);

//main program
int main()
{
  //data
  ifstream fin; //represents input file
  int age; //users age
  double gpa; //users grade point average
  char gender; //users gender M=male, F=female
  string fileName; //input filename
  string name; //users name
  string objective = "input 4 values of different data types from input file"; //program objective
  string instructions = ""; //user instructions

  //user introduction
  introduction(objective, instructions);   // output my name and objective and program information

  //user input of filename
  cout << "What is the input file name? ";
  getline(cin, fileName);

  //open input file
  fin.open(fileName.c_str()); 
  if (!fin.good()) throw "I/O error"; 

  // input data from file 
  fin >> age; 
  fin.ignore(1000, 10); 
  fin >> gpa; 
  fin.ignore(1000, 10);
  getline(fin, name); 
  fin >> gender; 
  fin.ignore(1000, 10); 
  
  fin.close(); //close the input file

  //output results 
  cout << "The input filename is " << fileName << endl;
  cout << "Your name is " << name << endl;
  cout << "Your age is " << age << endl;
  cout << "Your grade point average is " << gpa << endl;
  cout << "Your gender is " << gender << endl;
}//main

//program introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective
  //ins is the optional user instructions

  //user introduction
  cout << "Objective: This program will ";
  cout << obj << endl; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << ins << endl << endl; 
}//introduction
