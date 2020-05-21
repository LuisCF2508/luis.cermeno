#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  ifstream fin; //represents input file
  ofstream fout;
  string userInput; //user selected input filename
  string lineFromFile;


  userInput = getFileName();
  fin.open(userInput.c_str());
  if (!(fin.good())) throw "I/O error"; //error handling
  
  while (fin.good())
    {
      getline(fin, lineFromFile);
      //...do stuff....//


      
    }//while fin.good
  fin.close();


  //open file
  fout.open(userInput.c_str());
  fout.open(userInput.c_str(), ios::app); //in case of appending
  //do stuff
  fout.close();



}

string getFileName()
{
  //data
  string userInput; //user specified filename
  while(true)
  {
  cout << "Please enter an input filename [i.e.: x.txt]: ";
  getline(cin,userInput);
  if ( (userInput.length() < 5) || (userInput[userInput.length()-1] != 't' || userInput[userInput.length()-2] != 'x' || userInput[userInput.length()-3] != 't' || userInput[userInput.length()-4] != '.') )
  {
    cout << "Sorry, that is an invalid name." << endl << "The file name must have the .txt extension. Try again please." << endl << endl;
  }
  else break;
  }
return userInput;
}



