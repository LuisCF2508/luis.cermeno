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
  string inputFileName;
  string lineFromFile;
  const int MAX_NAMES = 5; //list capacity
  int nNames = 0;// initially empty list
  string name[MAX_NAMES];// array-based list with a capacity of 5 integers
  int i;
  int j;

  //user introduction
  introduction(objective);

  //prompt for input file
  inputFileName = getFileName();

  //store the names
  bool noDuplicate = true;
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
    }
    nNames++;
  }//while fin.good

  //sort loops
  string temp;
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