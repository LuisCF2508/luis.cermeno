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
struct Score
{
    int value;
    Score* next; // the link
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction

//main program
int main() 
{ 
  ifstream fin; 
  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  
  // data 
  string objective = "Objective: Read an input file of scores and find average score.\n";
  Score* start = 0; //empty linked list
  double average; //(decimal) is the average score of all the scores in the input file
  int sum = 0; //(integer) is the sum of all the scores in the input file
  int count = 0; //(integer) is the number of score in the input file
  int max; //(integer) is the highest score of all the score in the input file
  int min; //(integer) is the lowest score of all the scores in the input file
  int nScore = 0; //(integer) is the number of scores greater than the average

  //introduction
  introduction(objective);

  //input scores from file scores.txt and sum and count each score 
  while (fin.good()) 
  {
    Score* aScore = new Score; //is each score input from the input file
    fin >> aScore->value; // read a score from the file 
    fin.ignore(1000, 10); 
    cout << aScore->value << " ";
    sum = sum + aScore->value;
    count++;
    aScore->next = start;
    start = aScore;
  } // while 
  fin.close(); 

  //calculate average score
  if (count > 0) 
  {
    average = (double) sum / count;

    //find highest score, lowest score and count number of scores greater than the average
    max = start->value;
    min = start->value;
    Score* p;
    for (p = start; p; p = p->next)
    {
        if (max < p->value) max = p->value;
        if (min > p->value) min = p->value;
        if (p->value > average) nScore++;
    }
    
    //output average score and number of scores greater than the average
    cout << endl << "The maximun score is " << max << endl;
    cout << "The minimun score is " << min << endl;
    cout << "The average of " << count << " numbers is " << average << endl; 
    cout << nScore  << " scores are greater than the average." << endl;
  }//if   
  else cout << "The file was empty.";
} // main 

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
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl; 
  cout << "The file name used is scores.txt" << endl << "Please make sure you have this file ready" << endl << endl;

}//introduction function