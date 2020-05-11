//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <algorithm> //required for conversion to lowercase
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cctype> //required for conversion to lowercase

//Programmer defined data types
ifstream fin;

class toLower //required for conversion to lowercase
{
  public: char operator() (char c) 
  const 
  {
    return tolower(c);
  }
};

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
  string inputFileName; // (text) is the name of the file to read, input by the user
  string lineFromFile; // (text) is a line from the text file
  const int MAX_NAMES = 5; // (integer) is the maximun names that th list name can process
  int nNames = 0;// (integer )is how many names the list has so far
  string name[MAX_NAMES];// (list)  is the list of names
  string temp; // (string) is a temporary varaible to store each name when sorting
  int i; // (integer) a counter to sort the names alphabetically
  int j; // (integer a counter to sort the names alphabetically
  bool noDuplicate = true; // (boolean) is false when the list has a duplicate

  //user introduction
  introduction(objective);

  //prompt for input file
  inputFileName = getFileName();

  //store the names checking for duplciates and blank spaces
  fin.open(inputFileName.c_str());
  if (!(fin.good())) throw "I/O error";
  while (fin.good() && nNames < 5)
  {
    getline(fin, lineFromFile);
    if (lineFromFile.length() > 0)  //to skip blank spaces
    {
      for (i = 0; i < nNames; i ++) //to check for duplicates
      {
        string lc_lineFromFile = lineFromFile;
        string lc_name = name [i];
        transform (lc_lineFromFile.begin(), lc_lineFromFile.end() , lc_lineFromFile.begin(), toLower());
        transform (lc_name.begin(), lc_name.end() , lc_name.begin(), toLower());
        if (lc_lineFromFile == lc_name) noDuplicate = false;
      }
      if (noDuplicate) name[nNames] = lineFromFile;
    nNames++;
    }
    
  }//while fin.good

  //sort alphabetically
  for (i = 0; i < (nNames - 1); i++)
  {
    for (j = i + 1; j < nNames; j++)
    {
      if (toupper(name[i][0]) > toupper(name[j][0]))
      {
        temp = name[i];
        name[i] = name[j];
        name[j] = temp;
      } //if
    } // inner j for loop
  } // outter i for loope
  
  //output names sorted
  for (i = 0; i < nNames; i ++) cout << name[i] << endl;
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
  cout << "Compiler(s) used: Apple clang version 11.0.3 (clang-1103.0.32.59)\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function

//getFileName function
string getFileName()
{
  //Data
  string userInput;
  //User input
  while(true)
  {
    cout << "Enter the name of the file containing names: ";
    getline(cin,userInput);
    //Input validation
    if ( (userInput.length() < 5) || (userInput[userInput.length()-1] != 't' || userInput[userInput.length()-2] != 'x' || userInput[userInput.length()-3] != 't' || userInput[userInput.length()-4] != '.') )
    {
      cout << "Sorry, that is an invalid name." << endl << "The file name must have the .txt extension. Try again please." << endl << endl;
      continue;
    }
    else break;
  }
  return userInput;
}//getFileName function