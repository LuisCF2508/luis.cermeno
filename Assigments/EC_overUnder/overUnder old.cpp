//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries

#include <iostream>

using namespace std;

#include <cstdlib>
#include <ctime>

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data and generation of a ramdom number between 1 and 100
  srand(time(0)); //"seed the ramdom number generator"
  int target = 1 + rand() % 100; // (integer) a ramdom number from 1 to 100 generated by the computer 
  int userGuess; //(integer) number guessed each time by the user.


  // Introduction
  cout << "Objective: Ask the user to guess a number between 1 and 100.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  // Game loop where the user guesses and gets feedback.
  cout << "I'm thinking of a number from 1 to 100. Guess what it is [1-100 or 0 to Exit]:";
  while (true)
  {
   cin >> userGuess;
   cin.ignore(1000,10);

   if (userGuess < 1 || userGuess > 100)
   {
    cout << "Invalid input--guess again:";
    continue;
   }//if invalid guess

   else if (userGuess > target)
   {
    cout << "That's too high--guess again:";
    continue;
   }//if guess is too high

   else if (userGuess < target)
   {
    cout << "That's too low--guess again:";
    continue;
   }//if guess is too low

   else if(userGuess == target)
   {
    cout << "That's right--it's " << target << endl;
    break;
   }
  }//while true loop
 
    

}//main