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
ifstream fin;

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
string getFileName();


//main program
int main()
{
  //Data
  string objective = "Objective: Read names from a text file and sort them alphabetically\n";
  string inputFileName;
  const int MAX_NAMES = 5; //list capacity
  int nNames = 0;// initially empty list
  string name[MAX_NAMES];// array-based list with a capacity of 5 integers
  

  //user introduction
  introduction(objective);

  //prompt for input file
  inputFileName = getFileName();

  //store the names
  fin.open(inputFileName.c_str());
  if (!(fin.good())) throw "I/O error";
  while (fin.good() && nNames < 5)
  {
    getline(fin, name[nNames]);
    nNames++;
  }//while fin.good



}//main



//introduction function
void introduction(string obj)//user introduction
{
  //data
  //obj is the program objective

  //introduction
  cout << endl;
  cout << obj; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function
string getFileName()
{
  //Data
  bool valid; // (boolean) is true when the input is already processed by validation function
  string userInput;
  //User input
  while(true)
  {
    cout << "Enter input filename: ";
    getline(cin,userInput);
    //Input Validation
    int n = userInput.length(); // (integer) is the number of characters of the text input
    //Evaluation
    if ( (n < 5) || (userInput[n-1] != 't' || userInput[n-2] != 'x' || userInput[n-3] != 't' || userInput[n-4] != '.') )
    {
      cout << "Sorry, that is an invalid name." << endl << "The file name must have the .txt extension. Try again please." << endl << endl;
      continue;
    }
    else break;
  }
  return userInput;
}//input function (for either input or output)