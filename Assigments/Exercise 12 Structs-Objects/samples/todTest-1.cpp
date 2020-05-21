//Objective:  output time of day
//Name: Teacher
//Course: COMSC-110-5003
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip> //formatting
#include <iostream> //console IO
using namespace std; 

//Programmer defined data types
//time of day
struct Tod 
{ 
  int hour; //hour of the day [2 digits]
  int minute; //minute of the day [2 digits]
  int second; //seconds of the day [2 digits]
}; // tod 

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string ins); //user introduction
void outputTod(Tod& t); //output time of day

//main program
int main()
{
  //Data
  string objective = "output time of day"; //program objective
  string instructions = ""; //user instructions
 Tod noon = {12}; //record noon which hour 12 minute 0 second 0 PM

  //user introduction
  introduction(objective, instructions); 

  //output values in record noon
  outputTod(noon); 

}//main

// introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective from main program

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

//output time of day
void outputTod(Tod& t) 
{ 
  //data
  //record t of programmer defined data type Tod (time of day) containing 3 fields: hour, minute, second

  //output formatted time of day
  cout << "The time of day is ";
  cout.fill('0'); 
  cout << setw(2) << t.hour << ':' 
    << setw(2) << t.minute << ':' 
    << setw(2) << t.second << endl; 
  cout.fill(' '); // set back to a space 
}//outputTod 
