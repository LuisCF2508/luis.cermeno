//Objective:  input scores from file 8Scores.txt and calculate the average score and the number of scores > average score
//Name: Teacher
//Course: COMSC-110-5003
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //file input and output
#include <iostream> //console input and output
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string ins); //program introduction

//main program
int main()
{
  //Data
  string objective = "input scores from file 8Scores.txt and calculate the average score and the number of scores > average score."; //program objective
  string instructions = ""; //user instructions
  ifstream fin; //represent input file
  int scoreTotal = 0; //sum of all scores
  int i; // loop index 
  int aScore; //each score from input file
  double average; //calculated average score
  int scores[8]; //all the scores input from the file
  int nGreater=0; //number of scores greater than the average score

  //user introduction
  introduction(objective, instructions);  

  //input scores
  fin.open("8Scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  for (i = 0; i < 8; i++) 
  { 
    fin >> aScore; 
    fin.ignore(1000, 10); 
    scores[i] = aScore;
    scoreTotal += aScore; 
    cout << aScore << " ";
  } // for i
  fin.close(); 

  //calculate and output average score 
  average = scoreTotal / 8.0; 
  cout << endl << "The average of 8 numbers is " << average << endl; 

  //calculate the number of scores greater than average score
  for (i = 0; i < 8; i++)
  {
    if (scores[i] > average) nGreater=nGreater + 1;
  }//for i
  cout << "The number of scores greater than the average score is " << nGreater << endl;
}//main

// introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective
  //ins is the user instructions

  //user introduction
  cout << "Objective: This program will "; 
  cout << obj << endl;
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << ins << endl << endl;
}//introduction
