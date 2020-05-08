//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <fstream>
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
void introduction(string obj);//user introduction

//main program
int main()
{
  //Data
  string objective = "Objective: Decode a text file line by line so that each character is converted to the next character in the ASCII code.\n";
  string userText; //(text) the text to decode entered by the user
  string userFile; //(text) the name of the file to open for input
  int i; //(integer) counter for the decoding main loop 
  ifstream fin; //defining object for file input
  
  //User introduction
  introduction(objective);

  //User input
  cout << "Please enter the name of the text file including the extension [e.g. secret.txt]: ";
  getline(cin,userText);
  
  
  //Decoding 
  fin.open(userText.c_str()); //opening the file
  if (!fin.good()) throw "I/O error";
  cout << "Text Decoded: " << endl;

  while (fin.good())
  {
    getline(fin,userText);
    for (i = 0; i < userText.length(); i = i + 1)
    {
      userText[i] = userText[i] - 1; // sum the ASCII code b by 1
    }//for i
    cout << userText << endl;
  }
  fin.close();

}//main



//introduction function
void introduction(string obj)//user introduction
{
  //data
  //obj is the program objective

  //introduction
  cout << obj; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function