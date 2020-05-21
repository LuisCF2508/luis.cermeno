//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <fstream>
#include <iostream>
using namespace std;

//Programmer defined data types
ifstream fin;

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction

//main program
int main()
{
  //Data
  string objective = "Objective: This program will serve as a template for all programs written in this course.\n";
  string fileName; // (text) = input file name
  string line; // (text) = a line from the input file
  double averageScore; // (decimal) = calculated average of all the scores from the input file
  int count; // (integer) = number of scores in the input file
  int totalScores; // (integer) = sum of all the scores in the input file
  int maxScore; // (integer) = highest score of all the scores in the input file
  int minScore; // (integer) = lowest score of all the scores in the input file
  int nGreater; // (integer) = number of scores greater than the average score
  int i; // (integer) = indice for traversing each element in the array
 
  //introduction
  introduction(objective);

  //get input filename from user
  cout << "What is the input file name?: ";
  getline(cin,fileName);

  //determine how many scores are in the input file for storing the values
  count = 0;
  fin.open(fileName.c_str());
  if (!fin.good()) throw "I/O error";  
  while(fin.good())
  {
  fin >> line;
  count++;
  }

  //create dynamic array
  fin.close();
  fin.clear();
  fin.open(fileName.c_str());
  if (count != 0)
  {
    int* scores = new int[count];

    //input all the scores into the array
    i = 0;
    while(fin.good())
    {
      fin >> scores[i] ;
      fin.ignore(1000,10);
      i++;
    }

    //sum all the scores
    totalScores = 0;
    maxScore = scores[0];
    minScore = scores[0];
    for (i = 0; i < count;i++)
    {
      totalScores = totalScores + scores[i];
      if (maxScore < scores[i]) maxScore = scores[i];
      if (minScore > scores[i]) minScore = scores[i];
    }

    //calculate average score
    averageScore = double(totalScores) / count;

    //calculate the number of scores greater than the average
    nGreater = 0; 
    for (i = 0; i < count;i++)
    {
      if (scores[i] > averageScore) nGreater = nGreater + 1;
      i++;
    }    

    //output results
    cout << "The scores from the file " << fileName << " are: ";
    for (i = 0; i < count;i++)
    {
      cout << scores[i] << ",";
    }     
    cout << endl << "The average of " << count << " scores is: " << averageScore << endl;
    cout << "The highest score is: " << maxScore << endl;
    cout << "The lowest score is: " << minScore << endl;
    cout << "The number of scores greater than the average is: " << nGreater << endl;

  }//if
  else cout << endl << "Sorry the file is empty.";

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
