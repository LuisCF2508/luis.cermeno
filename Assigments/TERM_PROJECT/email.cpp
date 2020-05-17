//Objective:  Extract email addresses embedded in an input text file, and copy them to an output text file.
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3
//Editor: TextEdit

//libraries
#include <algorithm> //required for conversion to lowercase
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cctype> //required for conversion to lowercase

//Programmer defined data types
ifstream fin; //object for file input
ofstream fout; //object for file output

struct list
{
  string email; // (text) is the text of the email
}; // list

class toLower { public: char operator() (char c) const {return tolower(c);} }; //required for conversion to lowercase

//Special compiler dependent definitions
//NONE

// global constants/variables
//NONE

//Programmer defined functions
void ibntroduction(string obj);//user introduction
string getFileName(string filetype, string dFileName);//Input function (for either input or output)
void readFile (deque<list>& nonDup, string iFileName);//Reads input file until EOF that calls function processLine for each line read from the input file
void processLine(deque<list>& nonDup, string lineFromFile);//To find a @, then find the start of an email addres, then find the end of the email, and extract
bool isValidEmailChar(char c); //Returns true if c is a valid email address character, else false
void isDuplicate (deque<list>& nonDup, string aEmail); //Checks anEmail whether it is a duplicate email address using case sensitive comparison to create list of non-duplicate email addresses
string changeCase(string s); //Converts string to all one case for case dependent comparisons
void sortList(deque<list>& nonDup); //Sorts list of non-duplicate email addresses
void outputList(deque<list>& nonDup, string oFileName); //Outputs the list of non-duplicate email addresses to the screen and output file meeting all output requirements

//main program
int main()
{
  //Data definitions
  string objective = "Objective: Extract email addresses embedded in an input text file, and copy them to an output text file.\n";
  string iFileName; // (text) :  is the input file name
  string oFileName; // (text) :  is the output file name
  string dFileName = "fileContainingEmails.txt"; // (text) :  is the default file name
  string wait; // (text) : just a variable to read the ENTER key at the end of the program.
  deque<list> nonDup; // (collection of text) collection of non duplicate emails

  //User introduction
  introduction(objective);
  
  //Get filenames (input and output) using variable prompts and default filenames (subprogram getFileName)
  iFileName = getFileName("input",dFileName);
  if (iFileName == dFileName) dFileName = "copyPasteMyEmails.txt";
  else dFileName = iFileName;
  oFileName = getFileName("output",dFileName);

  //Output filenames and pause program execution until user presses enter key
  cout << "-> Input file: " << iFileName << endl;
  cout << "-> Output file: " << oFileName << endl;
  cout << "Press ENTER key to continue:";
  getline(cin,wait);
  cout << endl;

  //Read input file (subprogram readFile)
  readFile(nonDup, iFileName);

  //Sort collection of non-duplicate email alphabetically (subprogram sortList)
  sortList(nonDup);

  //Output list of emails to output file and to console giving instructions on how to use it (subprogram outputList)
  if (nonDup.size() == 0) cout << "Sorry, no email addresses were found in the file " << iFileName << endl << endl;
  else outputList(nonDup, oFileName);
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
  cout << "Compiler(s) used: Apple clang version 11.0.3\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "                                          WELCOME TO EMAIL.CPP" << endl << endl;
  cout << "This program is created to make it easier to send an email to multiple recipients when they are not already in your conctacts list." << endl ;
  cout << "When the list of your recipients are inside a webpage; for example, you would need to copy one by one into your 'to' field." << endl;
  cout << "With email.cpp, you just need to copy the content of the webpage into a text file and select it as the input file for the program."<< endl;
  cout << "The program will automatically extract all emails embedded and write them into one line in your selected input file. "<< endl; 
  cout << "Now its all ready to just copy paste that into your 'to' field. No more effort needed." << endl << endl;
  cout << "INSTRUCTIONS:" << endl;
  cout << "This program will prompt you for two text file names, an input and an output file." << endl;
  cout << "Please type the name of each file correctly including the extension .txt. No other file extension is yet supported." << endl;
  cout << "If you do not specify your output file, your input file will be overwritten with the emails extracted." << endl <<endl;
}//introduction function

//function getFileName: Input function (for either input or output)
string getFileName(string filetype, string dFileName)
{
  //Data
  bool valid; // (boolean) is true when the input is already processed by validation function
  string userInput = "No name";// (text) is the text entered by the user

  //User input
  while(true)
  {
    if (filetype == "input")  cout << "Enter input filename [Press ENTER for default: " << dFileName << "]: ";
    else if (filetype == "output") cout << "Enter output filename [Press ENTER for default: " << dFileName << "]: ";
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
}//function getFileName

//function readFile: Reads input file until EOF that calls function processLine for each line read from the input file
void readFile (deque<list>& nonDup, string iFileName)
{
  //Data
  string lineFromFile; //(text) is a line read from the input file
  int nLines = 0; // (integer) number of lines of the file
  int i; //(integer) counter to traverse the collection of emails

  //Read each line in the file and find each @
  fin.open(iFileName.c_str());
  if (!(fin.good())) 
  {
    cout << "Sorry, it seems that the file " << iFileName << " cannot be opened. It might contain an error, not exist in local directory or be locked to access." << endl;
    throw "I/O error";
    cout << endl;
  }
  else
    cout << "Emails found in the file " << iFileName << ": " << endl;
    while (fin.good())
      {
        getline(fin, lineFromFile);
        //Process lineFromFile to check for '@'
        processLine(nonDup, lineFromFile);
        nLines++;
      }//while fin.good
  fin.close();
}//function readFile

//function processLine: To find a @, then find the start of an email addres, then find the end of the email and extract
void processLine(deque<list>& nonDup, string lineFromFile)
{
  //Data
  int i; //(integer) is a counter used to process each character of the line and find an '@' 
  int s; //(integer) is the character position in lineFromFile for the start of a possible email
  int e; //(integer) is the character position in lineFromFile for the end of a possible email
  int dotPos; //(integer) is the character number of lineFromFile in which the dot is
  bool hasDot = false; //(integer) is true if the possible email has a dot on their characters
  string anEmail; //(string) is an sub string of lineFromFile that stores a complete possible email

  //Search each line for @
  for (i = 0; i < lineFromFile.length() ; i++)
  {
    //compare each character with ASCII64 which is '@'
    if (lineFromFile[i] == 64) 
    {
      //Loop to traverse lineFromFile from the character @ to the left until finding an invalid one
      for (s = i - 1; s > 0; s--) 
        if (!(isValidEmailChar(lineFromFile[s]))) 
          {
            s = s + 1;
            break; 
          }
      //Loop to traverse lineFromFile from the character @ to the right until finding an invalid one
      for (e = i + 1; e < lineFromFile.length(); e++) 
        if (!(isValidEmailChar(lineFromFile[e]))) break; 
        else if (lineFromFile[e] == 46)
        {
          hasDot = true;
          dotPos = e;
        }
      //Decide whether to extract the email
      if ( (s < i) && (e > i) && (hasDot) && (dotPos > i + 1) ) 
      {
          anEmail = lineFromFile.substr(s,e - s); 
          isDuplicate(nonDup, anEmail);
      }
      i = e;
    }// if
  }//main loop to traverse the whole lineFromFile
}//function processLine

//function isValidEmail: Returns true if c is a valid email address character, else false
bool isValidEmailChar(char c)
{
  //Check whether a character is a valid email address character (subprogram isValidEmailChar)
  bool result = true; // (boolean) is true if a character is a valid email character
  if( !( (65 <= c) && (c <= 90) )  && !( (97 <= c) && (c <= 122) ) && !(  (48 <= c) && (c <= 57)  ) && (c != 95) && (c != 46) && (c != 45) && (c != 43)) result = false;
  //traslated from ASCII: if( !(c is A - Z)  && !(c is a-z) && !(c is 0-9)  && (c != '_') && (c != '.') && (c != '-') && (c != '+'))
  return result;
} //funcion isValidEmail

//function isDuplicate: Checks anEmail whether it is a duplicate email address using case sensitive comparison to create list of non-duplicate email addresses
void isDuplicate (deque<list>& nonDup, string anEmail)
{
  //Data
  int i; // (integer) counter used to traverse the collection of emails and check for duplicates
  bool duplicate = false; // (bool) is true when a duplicate has been found in the collection

  //Maintain list of non-duplicate email addresses by checking for case independent duplicate email addresses
  for (i = 0; i < nonDup.size(); i ++) if (changeCase(anEmail) == changeCase(nonDup[i].email)) duplicate = true;
  if (!duplicate)
  {
    cout << anEmail << endl; 
    list newEmail; 
    newEmail.email = anEmail; 
    nonDup.push_back(newEmail); 
  }
}//function isDuplicate

//function changeCase: Converts string to all one case for case dependent comparisons
string changeCase(string s) 
{
  //Data
  string lc_s = s; // (text) is a copy of s to be case lowered, value returned to subprogram isDuplicate

  //Change the case of a string for comparisions
  transform (lc_s.begin(), lc_s.end() , lc_s.begin(), toLower()); //transforming the lc_s to lower case
  return lc_s;
}//function changeCase

//function sort: Sorts list of non-duplicate email addresses
void sortList(deque<list>& nonDup)
{
  //Data
  int i;// (integer) a counter to compare each email i with the rest, outer loop
  int j;// (integer) a counter to select an email j to compare with the email i, inner loop
  string temp; //(text) a tempory variable used when swaping email in the collection

	//sorting
	for(i=0;i< nonDup.size();i++)
	{		
		for(j=i+1;j<nonDup.size();j++)
		{
			if(changeCase(nonDup[i].email) > changeCase(nonDup[j].email))
			{
				temp  = nonDup[i].email;
				nonDup[i].email = nonDup[j].email;
				nonDup[j].email = temp;
			} // if for swap code block
		}//j for
	}// i for
}

//function outputList: Outputs the collection of non-duplicate email addresses to the screen and output file meeting all output requirements
void outputList(deque<list>& nonDup, string oFileName)
{
  //Data
  int i; // (integer) a counter to traverse each email in the collection

  //Ouput to console and file
  cout << endl << "SUCCESS! " << nonDup.size() << " emails were found, and copied to the file " << oFileName << " as follows:"  << endl;
  fout.open(oFileName.c_str());
  for (i = 0 ; i < nonDup.size() ; i ++) 
    if (i == nonDup.size() - 1) 
    {
      fout << nonDup[i].email;
      cout << nonDup[i].email << endl << endl;
    }
    else 
    {
      fout << nonDup[i].email << "; ";
      cout << nonDup[i].email << "; ";
    }
  fout.close();
  cout << "Now, you may open the file " << oFileName << " and copy/paste its contents into the 'to', 'cc', or 'bcc' field of any email message." << endl;
  cout << "In order to protect you recipients privacy, we suggest you to use 'bcc' field since it does not show the other recipients you have sent the email to." << endl << endl;
}