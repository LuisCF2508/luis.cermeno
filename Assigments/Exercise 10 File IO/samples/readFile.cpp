//Objective:  read the contents of an input and output
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
string getFileName(); //get user filename

//main program
int main()
{
  //Data
  string objective = "read the contents of an input and output"; //program objective
  string instructions = ""; //user instructions if needed
  string fileName; //user selected input filename
  ifstream fin; //represents input file
  string line; //one line from input file
  int lineNumber = 0; //number of lines in the input file

  introduction(objective, instructions); //user introduction

  //input and open user selected file name
  fileName = getFileName();
  fin.open(fileName.c_str());
  if (!(fin.good())) throw "I/O error";

  //read and output each line in the input file
  while (fin.good())
  {
    lineNumber = lineNumber + 1;
    getline(fin, line);
    cout << lineNumber << ". " << line << endl;
  }//while fin.good

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
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl; 
  cout << endl << ins << endl << endl;
}//introduction

//get user specified filename
string getFileName()
{
  //data
  string fN; //user specified filename

  //input filename
  do 
  {
    cout << "Please enter an input filename [i.e.: x.txt]: ";
    getline(cin, fN);
  }while(!(fN.length() >=5)); //do-while
  return fN;
}//getFileName