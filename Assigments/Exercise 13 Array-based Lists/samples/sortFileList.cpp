//Objective:  input scores from file and output sorted list of scores
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: MinGW
//Editor: MS NotePad

//libraries
#include <algorithm> //sort function
#include <fstream> //file IO
#include <iostream> //console IO
#include <string> //string functions
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string dir);

//main program
int main()
{
  //data
  ifstream fin; //represents input file
  int aScore; //each score read from input file
  int i; //loop index
  const int MAX_SCORES = 100; //capacity of array based list
  int nScores = 0;  //number of values on array based list
  int score[MAX_SCORES]; //array based list of values
  string objective = "input scores from file and output sorted list of scores"; //program objective
  string directions = "";

  //program introduction
  introduction(objective, directions); 

  //input scores from file and store on list
  cout << "unsorted list: ";
  fin.open("scores.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good())
  {
   fin >> aScore;
   fin.ignore(1000,10);
   if (nScores < MAX_SCORES)  score[nScores++] = aScore;
   cout << aScore << ' ';
  }//while fin.good
  fin.close(); //close input file
  cout << endl << endl;

  sort(score, score + nScores); //sort list

  //output scores in low to high order
  cout << "sorted list: ";
  for (i=0; i < nScores; i++)
  {
    cout << score[i] << ' ';
  }//for
  cout << endl;

} //main

//user introduction
void introduction(string obj, string dir)
{
  //data
  // obj is the program objective
  // dir is the user directions

  //user introduction
  cout << "Objective: This program ";
  cout << obj << ".\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << dir << endl << endl;
} // introduction