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
string getFileName();//prompt for text file

//main program
int main()
{
  //Data
  string objective = "Objective: Decode a text file line by line so that each character ASCII value is substracted with a sequence of characters retrieved from text file named offset.txt.\n";
  string userText; //(text) the text to decode entered by the user
  string userFile; //(text) the name of the file to open for input
  int i; //(integer) counter for the decoding main loop 
  int j; //(integer) counter for traversing repeatedly arraySequence
  int randomSize = 0;
  int read; //(int) temporal variable only used to retrieve arraySequence
  ifstream fin; //defining object for file input

  //User introduction
  introduction(objective);

  //Retrieving encoding sequence from offset.txt
  fin.open("offset.txt");
  if (!fin.good()) throw "I/O error";
  while(fin.good()) //loop to retrieve size of arraySequence
  {
    fin >> read;
    fin.ignore(1000,10);
    randomSize++;
  }
  if (randomSize < 5) cout << "ERROR: Unfortunately offset.txt is not working properly" << endl;
  else
  {
    int* arraySequence = new int[randomSize]; //declare arraySequence
    fin.close();
    fin.clear();
    fin.open("offset.txt"); //reopening the file to traverse it again
    cout << "Text will be decoded with the following coding sequence of " << randomSize << " numbers: ";
    for (i = 0; i < randomSize; i++)
    {
      fin >> arraySequence[i];
      fin.ignore(1000,10);
      cout << arraySequence[i] << ",";
    }
    fin.close();
    fin.clear();

    //Text file input
    userFile = getFileName();

    //Decoding 
    fin.open(userFile.c_str()); //opening the file
    if (!fin.good()) throw "I/O error";
    cout << endl << "Text Decoded: " << endl;
    while (fin.good())
    {
      getline(fin,userText);
      for (i = 0; i < userText.length(); i = i + 1)
      {
        j = i % randomSize; // j will get values only between 0<=j<randomSize
        userText[i] = userText[i] - arraySequence[j]; // sum the ASCII code b by each value of arraySequence
      }//for i
      cout << userText << endl;
    }
    fin.close();
  }//else
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
    cout << endl << "Please enter the name of the text file to decode including the extension [e.g. secret.txt]: ";
    getline(cin, read);
  }while(!(read.length() >=5)); //do-while
  return read;
}// // prompt for text file name