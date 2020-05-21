//Objective:  output however many letters of the alphabet from A that the user selects
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
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
  int n = 0; // print this many letters
  int i; // loop index variable
  char letter = 'A'; // letters of the alphabet starting with letter A

  // output my name and objective and program information
  cout << "Objective: This program will output however many letters of the alphabet from A that the user selects.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //input how many letters of the English alphabet to output 
  do
  {
    cout << "How many letters to print? [0-26] :";
    cin >> n;
    cin.ignore(1000, 10);
  }
  while (n < 0 || n > 26); //do-while

  //output each letter of the alphabet for number of letters user input
  for (i = 0; i < n; i = i + 1)
  {
    cout << letter;
    letter = letter + 1; // becomes next letter
  } // for
  cout << endl;

}//main