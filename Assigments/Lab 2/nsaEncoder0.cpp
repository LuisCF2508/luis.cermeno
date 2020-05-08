//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

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
void introduction(string obj);//user introduction

//main program
int main()
{
  //Data
  string objective = "Objective: Prompt the user to enter a line of text, of any length, with spaces and punctuation. Then encode the entered text so that each character is converted to the next character in the ASCII code.\n";
  string userText; //(text) the text to encode entered by the user
  int i; //(integer) counter for the encoding main loop 
  
  //User introduction
  introduction(objective);

  //User input
  cout << "Please enter a line of text [E.g. Hello, World]: ";
  getline(cin,userText);
  
  //Encoding 
  for (i = 0; i < userText.length(); i = i + 1)
  {
    userText[i] = userText[i] + 1; // sum the ASCII code b by 1
  }//for i
  
  //output encoded text
  cout << "Encoded text: " << userText << endl;

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