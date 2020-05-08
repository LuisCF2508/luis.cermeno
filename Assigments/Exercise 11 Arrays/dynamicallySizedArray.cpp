//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <iostream>
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

//main program
int main()
{

  //user introduction
  string objective = "Objective: Input number of scores to be input, then input that many scores, calculate the maximum score, average score, minimum score, and how many A grade scores.\n";
  introduction(objective);
  cout << "You will be prompted to enter a certain number of grades, you can choose how many grades you want to enter." << endl;

  //initialize values
  int size; //(integer)the number of values to be input 
  int sum = 0; //(integer)total of inputed values 
  double average; //(integer)average value of inputed values
  int nGradeA = 0; //(integer)number of scores that are A grade
  int temp; //(integer)used for temporarily storing one of the values in the array in the swapping process to sort 
  int count = 0; //(integer)count input values 
  int i; //(integer)outer loop index for sorting
  int j; //(integer)inner loop index for sorting

  //input loop
  cout << endl << "How many scores? " << endl;
  cin >> size;
  cin.ignore(1000,10);
  int* arrayScore = new int[size];
  for (count = 0; count < size ; count++)
  {
    cout << "Enter a score: ";
    cin >> arrayScore[count];
    if (arrayScore[count] < 0 || arrayScore[count] > 100)
    {
      cout << "Invalid input, please try again..." << endl;
      continue;
    }
    sum = sum + arrayScore[count];
  }
  
  //calculate average
  if (size > 0) average = double(sum) / size;

  // calculate the number of scores that are an A grade
  for (count = 0; count < size; count++)
  {
    if (arrayScore[count] > 90) nGradeA = nGradeA + 1;
  }

  //sort loops
  for (i = 0; i < (size - 1); i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if (arrayScore[i] > arrayScore[j])
      {
        temp = arrayScore[i];
        arrayScore[i] = arrayScore[j];
        arrayScore[j] = temp;
      } //if
    } // inner j for loop
  } // outter i for loop
  
  //output results
  cout << endl << "Sorted: ";
  for (count = 0; count < size; count++)
  {
    cout << arrayScore[count] << ", ";
  }
  cout << endl << "Minimum: " << arrayScore[0] << endl;
  cout << "Maximum: " << arrayScore[size - 1] << endl;
  cout << "Average: " << average << endl;
  cout << "Number of A grades: " << nGradeA << endl;

}//main



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