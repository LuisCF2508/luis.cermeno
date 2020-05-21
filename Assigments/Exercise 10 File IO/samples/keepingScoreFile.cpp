//Objective:  keep track of users wins and losses
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
  string scoreFile = "scores.txt"; //input filename
  ifstream fin; //represents input file
  ofstream fout; //represents output file
  int wins; //number of times user wins
  int losses; //number of times user lost
  string objective = "keep track of users wins and losses"; //program objective
  string instructions =""; //user instructions

  //user introduction
  introduction(objective, instructions); 

  // input
  fin.open(scoreFile.c_str()); 
  if (!fin.good()) throw "I/O error"; 
  fin >> wins; 
  fin.ignore(1000, 10); 
  fin >> losses; 
  fin.ignore(1000, 10); 
  fin.close(); 

  // play the game(s) in a loop here (MISSING)
  // ...for each win, do wins++; 
  // ...for each loss, do losses++; 
 
  // output results
  cout << "You lost " << losses << " time(s)." << endl; 
  fout.open(scoreFile.c_str()); 
  if (!fout.good()) throw "I/O error"; 
  fout << wins << endl; 
  fout << losses << endl; 
  fout.close(); 

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
  cout << ins << endl << endl; 
}//introduction