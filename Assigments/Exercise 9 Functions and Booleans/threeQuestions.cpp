//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
bool askQuestion(string questionToAsk,int correctAnswer);

//main program
int main()
{
  //Data
  string objective = "Objective: Ask three computer science questions and then show their final score.\n";
  string question; // (text) one computer science question
  int userScore = 0; // (integer) the number of correct answer the user has gotten.
 
  //User introduction
  introduction(objective);

  //Ask question and update score

  question = "Q1.Which one is a programming language?: 1)html 2)java 3)binary";
  if (askQuestion(question,2)) userScore ++;
  question = "Q2.Which loop is count controlled?: 1) while-true 2) for";
  if (askQuestion(question,2)) userScore ++;
  question = "Q3.How do you call the name of variables?: 1)label 2)parameter 3)identifier";
  if (askQuestion(question,3)) userScore ++;

  //Output final score
  cout << endl << "TOTAL SCORE: " << userScore << " out of 3." << endl;
   
}//main



//function askQuestion
bool askQuestion(string questionToAsk,int correctAnswer)
{
  //DATA
  bool result = false; //(boolean) whether the user got the answe correct, true or false
  int userAnswer; // (integer) the answer input by the user

  //ASK QUESTION AND CHECK IF USER GOT IT RIGHT
  cout << endl << questionToAsk << endl;
  cin >> userAnswer;
  cin.ignore(1000,10);
  
  if (userAnswer == correctAnswer)
  {
    cout << "Correct!" << endl;
    result = true;
  }
  else
  {
    cout << "Very good,but a better answer is " << correctAnswer << endl ;
  }
  return result;
} // function askQuestion




//introduction function
void introduction(string obj)//user introduction
{
  //data
  //obj is the program objective

  //introduction
  cout << obj; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function