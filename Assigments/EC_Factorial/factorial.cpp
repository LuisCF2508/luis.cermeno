//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3 (clang-1103.0.32.59)
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
int factorial(int n);

//main program
int main()
{
  //Data
  string objective = "Objective: Calculate the factorial of an integer n.\n";
  int n; //(integer) the number to calculate the factorial of

  //User introduction
  introduction(objective);

  //Prompt user for a number
  while (true)
  {
    cout << "Enter a number [only non negative integers, decimals will be truncated to nearest integer]: ";
    cin >> n;
    cin.ignore(1000, 10);
    if (n > 0) break;
    else cout << "Invalid input, please try again..." << endl;
  }
  
  //Calculate and output factorial
  cout << factorial(n) << endl;
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
  cout << "Compiler(s) used: Apple clang version 11.0.3 (clang-1103.0.32.59)\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function


//function factorial: calculates the factorial of then number n
int factorial(int n)
{
  int f = 1; // (integer) is the factorial of the number n)
  int i; // (integer) counter to calculate the factorial
  for (i = n ; i > 1 ; i--) f = f * i;
  return f;
} // factorial