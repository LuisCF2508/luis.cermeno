//Objective:  randomly generate 3 random integers between 1 and 10, and sum those 3 numbers, and output the 3 random numbers and the sum
//Name: Teacher
//Course: COMSC-110-8269
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //console IO
using namespace std;
#include <cstdlib> //random number generator
#include <ctime>  //random number genrator

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
  //Data
  srand(time(0)); //initialize random number generator
  int n1; //randomly generated between 1 and 10
  int n2; // randomly generated between 1 and 10
  int n3; //randomly generated between 1 and 10
  int sum; //total of n1, n2, and n3

  // introduction
  cout << "Objective: This program will randomly generate 3 random integers between 1 and 10, and sum those 3 numbers, and output the 3 random numbers and the sum.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //generate 3 random numbers between 1 and 10 and sum them
  n1 = 1 + rand() % 10;
  n2 = 1 + rand() % 10;
  n3 = 1 + rand() % 10;
  sum = n1 + n2 + n3;

  //output appropriately labeled 3 random numbers and the sum
  cout << n1 << " + " << n2 << " + " << n3 << " = " << sum;

}//main