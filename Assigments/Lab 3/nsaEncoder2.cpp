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

#include <cstdlib>
#include <ctime>


//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
string getFileName();// prompt for text file name

//main program
int main()
{
  //Data
  string objective = "Objective: Encode a text file line by line so that each character ASCII value is sumed with a random character.\n";
  string userFile; //(text) the name of the file to open for input
  string userText; //(text) the text to encode entered by the user
  int i; //(integer) counter for the encoding main loop 
  int j; //(integer) convenience variable for traversing repeatedly arraySequence
  ifstream fin; //defining object for file input
  ofstream fout; //defining object for file output
  srand(time(0)); // seed for random number generation

  //User introduction
  introduction(objective);

  //Creation of encoding sequence
  int randomSize = 5 + rand() % 6; //generation of a number from 5-10
  int* arraySequence = new int[randomSize]; // creation of dynamically sized array  with random number of elements
  fout.open("offset.txt");
  cout << "Text will be encoded with the following coding sequence of " << randomSize << " numbers: ";  
  for (i = 0; i < randomSize;i++)
  {
    arraySequence[i] = rand() % 41 - 20; //generation of a number from -20 to 20 and assignment to each element of the array
    cout << arraySequence[i] << ",";
    fout << arraySequence[i];
    if (i < randomSize - 1) fout << endl; //this is to avoid one extra ENTER at the end of the file
  }
  cout << endl;
  fout.close();
  fout.clear();

  //Text file input
  userFile = getFileName();
  
  //Encoding and outputting
  fin.open(userFile.c_str()); //opening the file
  if (!fin.good()) throw "I/O error";
  fout.open("secret.txt");
  cout << endl << "Text Encoded: " << endl;
  while (fin.good())
  {
    getline(fin,userText);
    for (i = 0; i < userText.length(); i = i + 1)
    {
      j = i % randomSize; // j will get values only between 0<=j<randomSize
      userText[i] = userText[i] + arraySequence[j]; // sum the ASCII code b by each value of arraySequence
    }//for i
    fout << userText << endl;
    cout << userText << endl;
  }
  cout << endl << "The encoded text has been saved in a text file named secret.txt." << endl;
  fin.close();
  fout.close();

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

// prompt for text file name
string getFileName() // request name of input file and check for valid input
{
  string read;
  do 
  {
    cout << endl << "Please enter the name of the text file to encode including the extension [e.g. confidential.txt]: ";
    getline(cin, read);
  }while(!(read.length() >=5)); //do-while
  return read;
}// // prompt for text file name