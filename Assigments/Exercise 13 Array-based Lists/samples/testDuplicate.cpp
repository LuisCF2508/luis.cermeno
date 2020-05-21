//Objective:  test program to test for duplicate guesses
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
bool checkValid(int target, int uG, int* guess, int n); //input validation
bool checkDuplicate(int uG, int* guess, int n); //check if user guess is a duplicate guess


//main program
int main()
{
  //Data
  string objective = "test program to test for duplicate guesses"; //program objective
  string directions = "I'm thinking of a number between 1 and 100. Guess what it is: "; //user instructions if needed
  const int MAX_GUESSES = 100; //list capacity
  int nGuesses = 0; //empty list
  int guess[MAX_GUESSES]; //list container array
  int target = 37; //correct answer  
  int userGuess; //user's guess

  //user introduction
  introduction(objective, directions); 

  //game loop
  do
  {
    //get guess
    cin >> userGuess;
    cin.ignore(1000, 10);

    //input validation
    if (checkValid(target, userGuess, guess, nGuesses))
    {
      //update list of non-duplicate guesses
      guess[nGuesses++] = userGuess;

      //provide user feedback
      if (userGuess == target)
      {
        cout << "you guessed it!" << endl;
      }//guess is correct
     else if (userGuess > target)
     {
       cout << "That's too high--guess again: ";
     }
     else
     {
        cout << "That's too low--guess again: ";
     }
    }//checkValid
  }while(userGuess != target); //game loop
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
  cout << endl << dir;
}//introduction

//input valid
bool checkValid(int target, int uG, int* guess, int n)
{
  //data
  //target is the correct answer
  //uG is the user's guess
  //guess is the list of non-duplicate guesses
  //n is the size counter of the list
  bool result = true; //false is not valid, true is valid input

  //input validation
  if (uG < 1 || uG > 100)
  {
    result = false;
    cout << "not a valid value--guess again [1-100]: ";
  }// if valid
  if (checkDuplicate(uG, guess, n)) 
  {
    result = false;
    cout << "you already guessed " << uG << " -- guess again: ";
  }//check duplicate

  return result;
}//checkValid

//check if user guess is a duplicate guess
bool checkDuplicate(int uG, int* guess, int n)
{
  //data
  //guess is the list of non-duplicate guesses
  //n is the size counter of the list
  //uG is the user guess
  bool result = false; //false is not a duplicate, true is a duplicate guess
  int i; //loop index for traversing the list

  //check if duplicate guess
  for(i=0; i < n; i = i + 1)
  {
    if (uG == guess[i])
    {
      result = true;
    }//if
  }//for i
  return result;
}//checkDuplicate