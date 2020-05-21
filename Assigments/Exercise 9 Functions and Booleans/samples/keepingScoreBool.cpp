//Objective:  User does 5 addition problems
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>  //for console input output
using namespace std;
#include <cstdlib> //use random number generator
#include <ctime> //use random number generator

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); // Introduction
bool additionProblem(int topNumber, int bottomNumber); // provide user with addition problem

//main program
int main()
{
  //Data
  string objective = "provide user with 5 math problems to solve."; //program objective
  srand(time(0)); //seed the random number generator 
  int score = 0; //keep track of correct user answers
  int i; //loop index

  //user introduction
  introduction(objective); 

  //provide 5 addition problems
  for(i=0; i < 5; i=i+1)
  {
    if (additionProblem(rand() % 10, rand() % 10)) score++; 
  }//for i

  //output final score  
  cout << "\n      TOTAL SCORE: " << score << " out of 5" << endl; 
}//main

//introduction
void introduction(string obj)
{
  //data
  //obj is the program objective

  cout << "Objective: This program will "; 
  cout << obj << endl;
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//introduction

// provides user with an addition problem
bool additionProblem(int topNumber, int bottomNumber) 
{ 
  //data
  //topNumber is the first number in the addition problem randomly generated
  //bottomNumber is the second number in the addition problem randomly generated
  bool result = false; // assume answer will be wrong   
  int userAnswer; //user response
  int theAnswer; //the correct answer

  //output addition problem
  cout << "\n\n\n      " << topNumber << " + " << bottomNumber << " = "; 
  cin >> userAnswer; 
  cin.ignore(1000, 10); 
  
  //calculate correct answer and evaluate user answer
  theAnswer = topNumber + bottomNumber; 
  if (theAnswer == userAnswer) 
  { 
    cout << "      Correct!" << endl; 
    result = true; // answer is right! 
  } 
  else 
  {
    cout << "      Very good, but a better answer is " << theAnswer << endl; 
  }// if 
  
  return result; 
} // additionProblem 
