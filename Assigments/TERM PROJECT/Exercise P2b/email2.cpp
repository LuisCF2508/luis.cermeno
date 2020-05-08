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
ifstream fin; //object for file input

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
bool validateInput(string inputName); //input validation function
string getFileName(string type, string defaultName);//input function (for either input or output)
void readFile(string iFileName);//reads input file until EOF that calls function processLine for each line read from the input file


//main program
int main()
{
  //Data definitions
  string objective = "Objective: Create a program to identify '@' characters and output the lines containing them for the term project.\n";
  string iFileName; // (text) :  is the input file name
  string oFileName; // (text) :  is the output file name
  string dFileName = "fileContainingEmails.txt"; // (text) :  is the default file name
  string enterKey; // (text) : just a variable to read the ENTER key at the end of the program.

  //User introduction
  introduction(objective);
  
  //Input filenames (input and output) using variable prompts and default filenames and input validation
  iFileName = getFileName("input",dFileName);
  if (iFileName == dFileName) dFileName = "copyPasteMyEmails.txt"; // if deafult is already used its changed for another default
  else dFileName = iFileName;
  oFileName = getFileName("output",dFileName);

  //Output filenames and pause program execution until user presses enter key
  cout << "-> Input file: " << iFileName << endl;
  cout << "-> Output file: " << oFileName << endl;
  cout << "Press ENTER key to continue:";
  getline(cin,enterKey);

  //Read input file and output lines with @
  readFile(iFileName);
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
  cout << endl << "This program will prompt you for two text file names, an input and an output file. The program will read your input file and then show the lines containing the character '@'.Please type the name of each file correctly including the extension .txt. No other file extension is yet supported." << endl << endl;
}//introduction function


//input validation function
bool validateInput(string inputName)
{
  //Data
  bool isValid = false; // (boolean) is true when the input is valid
  int n = inputName.length(); // (integer) is the number of characters of the text input
  //Evaluation
  if ( (n < 5) || (inputName[n-1] != 't' || inputName[n-2] != 'x' || inputName[n-3] != 't' || inputName[n-4] != '.') )
  {
    cout << "Sorry, that is an invalid name." << endl << "The file name must have the .txt extension. Try again please." << endl << endl;
  }
  else isValid = true;
  return isValid;
}//input validation function


//input function (for either input or output)
string getFileName(string type, string defaultName)
{
  //Data
  bool valid; // (boolean) is true when the input is already processed by validation function
  string userInput = "No name";// (text) is the text entered by the user
  //User input
  while(true)
  {
    if (type == "input")  cout << "Enter input filename [Press ENTER for default: " << defaultName << " ]: ";
    else if (type == "output") cout << "Enter output filename [Press ENTER for default: " << defaultName << " ]: ";
    getline(cin,userInput);
    //Interpretation of ENTER key
    if (userInput.length() == 0)
    {
      userInput = defaultName;
      break;
    }
    //Input Validation
    else
    {
      valid = validateInput(userInput);
      if (valid) break;
      else continue;
    }
  }
  return userInput;
}//input function (for either input or output)


//reads input file until EOF that calls function processLine for each line read from the input file
void readFile(string iFileName)
{
  //Data
  string readLine; //(text) is a line read from the input file
  int i; //(integer) is a counter used to process the line read a look for '@'
  //Open and read the file
  fin.open(iFileName.c_str());
  if (!(fin.good())) throw "I/O error";
  while (fin.good())
    {
      getline(fin, readLine);
      //Process readLine to check for '@'
      for (i = 0; i < readLine.length() ; i++)
      {
        if (readLine[i] == 64) cout << readLine << endl; //compare each character with ASCII64 which is '@'
      }
    }//while fin.good
  fin.close();
}//reads input file until EOF that calls function processLine for each line read from the input file



