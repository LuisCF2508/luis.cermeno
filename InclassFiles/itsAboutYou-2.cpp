//Objective:  input 4 values: integer, decimal, text, and a character
//Name: Teacher
//Course: COMSC-110-8269
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
using namespace std;

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
  int age;  //a persons age [whole number only] 
  double gpa; //a persons grade point average [0.0-4.0]
  string name; //a persons name  [full name: first, middle initial, last]
  char favLetter; //a persons favorite letter in the alphabet [A-Z or a-z]

  // introduction
  cout << "Objective: This program will input 4 values: integer, decimal, text, and a character.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //input 4 values: integer, decimal, text, and a character
  // read an integer value from the keyboard
  cout << "What is your age [whole positive numbers only]? ";
  cin >> age;
  cin.ignore(1000, 10);
  // read a decimal value from the keyboard
  cout << "What is your grade point average [0.0-4.0]? ";
  cin >> gpa;
  cin.ignore(1000, 10);
  // read a text value from the keyboard
  cout << "What is your name [full name: first, middle initial, last]? ";
  getline(cin, name);
  // read a character value from the keyboard
  cout << "What is your favorite letter in the ? [A-Z or a-z]: ";
  cin >> favLetter;
  cin.ignore(1000, 10);

  //output user input  
  cout << endl << "You entered the following information: " << endl;
  cout << "your name is " << name << endl;
  cout << "your age is " << age << endl;
  cout << fixed << setprecision(1) << "your GPA is " << gpa << endl;
  cout << "your favorite letter in the alphabet is " << favLetter << endl;
}//main