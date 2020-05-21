//Objective:  read an input file of scores and find average score and number of scores greater than average
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //file IO
#include <iostream> //console IO
#include <string> //manipulate strings
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string dir); //program introduction

//main program
int main()
{
  //Data
  string objective = "read an input file of scores and find average score and number of scores greater than average.";
  string directions = "The file name used is scores.txt.\nPlease make sure you have this file ready.";
  ifstream fin; //represents input file
  const int MAX_SCORES = 100; // array based list capacity 
  int nScores = 0; // number of values on the array based list
  int score[MAX_SCORES]; //array based list of values
  int aScore; // each new score [0..100]
  int i; // loop counter 
  int scoreTotal = 0; //sum of all scores
  double average = 0.0; //average of all scores
  int nGreater = 0;  //number of scores greater than the average score

  //program introduction
  introduction(objective, directions);

  // input scores 
  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  while (fin.good()) 
  { 
    // read a score from the file 
    fin >> aScore; 
    fin.ignore(1000, 10); 
    if (nScores < MAX_SCORES) score[nScores++] = aScore; 
    cout << aScore << " ";
  } // while 
  fin.close(); //close the input file
  cout << endl << endl;
  
  // find the average 
  for (i = 0; i < nScores; i++) scoreTotal += score[i]; 
  if (nScores > 0) average = (double)scoreTotal / nScores; 
  cout << "The average of " << nScores    << " numbers is " << average << endl; 

  // count number of scores > average 
  for (i = 0; i < nScores; i++) if (score[i] > average) nGreater++; 
  cout << nGreater  << " scores are greater than the average." << endl; 

}//main

//program introduction
void introduction(string obj, string dir)
{
  //Data
  //obj = the program objective (text)
  //dir = user instructions (text)

  // output my name and objective and program information
  cout << "Objective: This program "; 
  cout << obj << endl;
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << dir << endl;
}//introduction