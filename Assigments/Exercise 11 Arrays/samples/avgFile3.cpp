//Objective:  input scores from file 8Scores.txt and calculate the average score and the number of scores > average score
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //file input and output
#include <iostream> //console input and output
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
  const int SIZE = 8; //size of the array

//Programmer defined functions
void introduction(string obj); //program introduction
void readScores(int* s); //input scores from file
double calcAverage(int* s); //calculate average score
int countScoresGreater(int* s, double avgScore);  //calculate the number of scores greater than average score

//main program
int main()
{
  //Data
  string objective = "input scores from file 8Scores.txt and calculate the average score and the number of scores > average score."; //program objective
  int i; //loop index
  int scores[SIZE]; //all the scores input from the file
  int nGreater=0; //number of scores greater than the average score
  double average; //average score

  //user introduction
  introduction(objective);  

  //input scores from input file
  readScores(scores);

  //calculate and output average score 
  average = calcAverage(scores);
  cout << endl << "The average of " << SIZE << " numbers is " << average << endl; 

  //calculate the number of scores greater than average score
  cout << "The number of scores greater than the average score is " << countScoresGreater(scores, average) << endl;
}//main

// introduction
void introduction(string obj)
{
  //data
  //obj is the program objective

  //user introduction
  cout << "Objective: This program will "; 
  cout << obj << endl;
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//introduction

//input scores from file
void readScores(int* s)
{
  //data
  //s is an array of scores (passed from main)
  int i; // loop index 
  int aScore; //each score from input file
  ifstream fin; //represent input file

  //input scores from input file
  fin.open("8Scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  for (i = 0; i < SIZE; i++) 
  { 
    fin >> aScore; 
    fin.ignore(1000, 10); 
    s[i] = aScore;
    cout << aScore << " ";
  } // for 
  fin.close(); 
}//readScores

//calculate average score
double calcAverage(int* s)
{
  //data
  double result; //average score
  //s array of scores from main
  int i; //loop index
  int scoreTotal = 0; //sum of all scores

  //sum all the scores
  for(i = 0; i < SIZE; i=i+1)
  {
   scoreTotal = scoreTotal + s[i];
  }//for i

  //calculate average score
  result = scoreTotal / double(SIZE);
  return result; 
}//calcAverage

//calculate the number of scores greater than average score
int countScoresGreater(int* s, double avgScore)  
{
  //data
  int result; //number of scores greater than the average score
  //s is array of scores from main
  //avgScore is the average score
  int i; //loop index

  //count the scores greater than the average score
  for (i = 0; i < SIZE; i++)
  {
    if (s[i] > avgScore) result = result + 1;
  }//for i
  return result;
}//countScoresGreater