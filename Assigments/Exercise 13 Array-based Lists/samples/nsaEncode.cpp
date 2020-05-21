//Objective:  encode each line of user selected input file
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
void introduction(string obj, string dir); //user introduction

//main program
int main()
{
  //Data
  string objective = "encode each line of user selected input file"; //program objective
  string directions = "Please have your input filename created and ready to specify."; //user instructions if needed
  string inputFileName; // = user selected input filename (text) 
  string line; // = each line read from input file (text) 
  int i = 0; //  = loop index (integer)
  string fileExtension; // = user selected inputFileName file extension (text)
  int lineNumber = 0; // = which line is being read (integer)
  bool emptyFile = false; // = is a flag that is true if the inputFileName is empty (Boolean)
  ifstream fin; //represents the input file
  ofstream fout; //represents the output file secret.txt

  //user introduction
  introduction(objective, directions); 

  //input user selected input filename
  do
  {
    cout << "Enter input file name [i.e.: x.txt]: ";
    getline(cin, inputFileName);
    if (inputFileName.length() < 5)
    {
      cout << "invalid filename!" << endl;
    }
    else 
    {
      fileExtension = inputFileName.substr(inputFileName.length()-4, 4);
      if  (fileExtension != ".txt") cout << inputFileName << " does not end in .txt" << endl;
    }//if 
  }while(inputFileName.length() < 5 || fileExtension != ".txt");
  cout << "input file name is " << inputFileName << endl;

  //read the input file and encrypt each line
  fin.open(inputFileName.c_str());
  if (!fin.good()) throw "I/O error";
  fout.open("secret.txt");
  while(fin.good())
  {
    getline(fin, line);
    lineNumber = lineNumber + 1;
    cout << "line " << lineNumber << " = " << line << end;
    //encode one line
    for(i=0; i < line.length(); 
  }//while fin.good

  //output results to console and to output file secret.txt

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
