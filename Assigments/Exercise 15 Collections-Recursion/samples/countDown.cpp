//Objective:  counts down from a user selected number > 0
//Name: Teacher
//Course: COMSC-110-5003
//Compiler: MinGW
//Editor: MS NotePad

//libraries
#include <iomanip> //formatting
#include <iostream>  //console IO
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//when pausing for a second, for windows use a library and for any other operating system use the 2nd library
#ifdef _WIN32 
#include <windows.h> 
#else 
#include <unistd.h> 
#endif 

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string ins); //program introduction
void countDown(int x); //count down from user selected number

//main program
int main()
{
  //data
  int n; // =user selected number > 0 
  string objective = "count down from a user selected number > 0"; //program objective
  string instructions = ""; //user instructions

  introduction(objective, instructions);   // output my name and objective and program information

  //input number from user
  while (true)
  {
    cout << " Enter a number > 0: ";
    cin >> n;
    cin.ignore(1000, 10);
    if (n > 0) break;
    else cout << "invalid input..." << endl;
  }//while true

  //perform the countdown sequence  
  cout << endl;
  countDown(n);  //count down from user selected number
  
}//main

//***program introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective
  //ins is the directions 

  //user introduction
  cout << "Objective: This program will "; 
  cout << obj << ".\n";
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << endl << ins << endl << endl; 
}//introduction

//***count down from user selected number
void countDown(int x)
{
  //data
  //x is the user selected number to countdown from
  int i; // =loop index

  //perform countdown sequence
  for (i = x; i > 0; i--)
  {
    cout << i ;
    //pause for one second depending upon operating system
    #ifdef _WIN32 
    Sleep(1000); // one thousand milliseconds
    #else 
    sleep(1); // one second 
    #endif 
    cout << '\r' << "        " << '\r'; //return to beginning of line and wipes out previous output on that line
  }//for i
  cout << endl << "***BLAST OFF!!!***" << endl;
}//countDown