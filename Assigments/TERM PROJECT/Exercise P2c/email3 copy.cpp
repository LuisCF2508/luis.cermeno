//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3
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
string getFileName(string filetype, string dFileName);//input function (for either input or output)
void readFile(string iFileName);//reads input file until EOF that calls function processLine for each line read from the input file
int processLine(string lineFromFile);//function to find a @, then find the start of an email addres, then find the end of the email and extract

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
  cout << endl << "This program will prompt you for two text file names, an input and an output file. The program will read your input file and then show the lines containing the character '@'.Please filetype the name of each file correctly including the extension .txt. No other file extension is yet supported." << endl << endl;
}//introduction function


//input function (for either input or output)
string getFileName(string filetype, string dFileName)
{
  //Data
  bool valid; // (boolean) is true when the input is already processed by validation function
  string userInput = "No name";// (text) is the text entered by the user
  //User input
  while(true)
  {
    if (filetype == "input")  cout << "Enter input filename [Press ENTER for default: " << dFileName << " ]: ";
    else if (filetype == "output") cout << "Enter output filename [Press ENTER for default: " << dFileName << " ]: ";
    getline(cin,userInput);
    //Interpretation of ENTER key
    if (userInput.length() == 0)
    {
      userInput = dFileName;
      break;
    }
    //Input Validation
    else
    {
      bool valid = false; // (boolean) is true when the input is valid
      //Evaluation
      if ( (userInput.length() < 5) || (userInput[userInput.length()-1] != 't' || userInput[userInput.length()-2] != 'x' || userInput[userInput.length()-3] != 't' || userInput[userInput.length()-4] != '.') )
      {
    cout << "Sorry, that is an invalid name." << endl << "The file name must have the .txt extension. Try again please." << endl << endl;
      }
      else valid = true;
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
  string lineFromFile; //(text) is a line read from the input file
  int nLines = 0; // (integer) number of lines of the file
  int nATs; // (integer) number of '@' character found in each line, returned to readFile subprogram
  int i; //(integer) is a counter used to process the line read a look for '@'s

  //Open and read the file
  fin.open(iFileName.c_str());
  if (!(fin.good())) throw "I/O error";
  while (fin.good())
    {
      getline(fin, lineFromFile);
      //Process lineFromFile to check for '@'
      nATs = processLine(lineFromFile);
      for (i = 0; i < nATs; i++) cout << lineFromFile << endl;
      nLines++;
    }//while fin.good
  fin.close();
}//reads input file until EOF that calls function processLine for each line read from the input file

int processLine(string lineFromFile)
{
  int i; //(integer) is a counter used to process each character of the line and find an '@', start and end
  int nEmails = 0; // (integer) number of valid Email adresses found, value returned to main program
  int s; //(integer) is the character position in lineFromFile for the start of a possible email
  int e; //(integer) is the character position in lineFromFile for the end of a possible email

  for (i = 0; i < lineFromFile.length() ; i++)
  {
    if (lineFromFile[i] == 64) //compare each character with ASCII64 which is '@'
    {
      for (i; i >= 0 ; i--) //i goes backwards from the position of the @ until it reaches a space(start of email)
      {
        if (lineFromFile[i] == 32) //compare each character with ASCII64 which is an space
        {
          s = i;
          for (i; i < lineFromFile.length();i++) // i goes forward from the position of s until it reaches a space(end of email)
          {
            if (lineFromFile[i] == 32) //compare each character with ASCII64 which is an space
            {
              e = i;
              //here the program shoul go to function isValidEmailChar 
              break; 
            }
          }// loop to look for the end of email
          break;
        }
      }//loop to look for the start of email
    }
  }//loop to look for an '@'
  cout << s << endl;
  cout << e << endl;
  return nEmails;
  
}


