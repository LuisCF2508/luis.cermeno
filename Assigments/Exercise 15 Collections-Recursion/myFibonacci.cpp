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
int outputFibonacci(int index); //function to output last term of Fibonacci series

//main program
int main()
{
  //Data
  string objective = "Objective: Display all the numbers of a Fibonacci series with index chosen by the user\n";
  int index; // (integer) is the index for the fibonacci serios input by the user, has to be equal to zero or greater
  int i; // (integer) a counter to output each term of the fibonacci series

  //user introduction
  introduction(objective);

  //prompt user for index
  while (true)
  {
    cout << "Enter an index [0 or greater]: ";
    cin >> index;
    cin.ignore(1000, 10);
    if (index >= 0) break;
    else cout << "Invalid input, please try again.." << endl;
  }//while true for input validation

  //output fibonacci series and the number at the position of the index
  for (i = 0; i <= index; i++) 
	{
	  cout << outputFibonacci(i) << " ";
	}
	cout << endl << "The fibonacci number at index " << index << " is " << outputFibonacci(index) << endl; 
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
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "This program will prompt you to input an index for a Fibonacci series, please enter on whole numbers greater than 0" << endl << endl;

}//introduction function

//function to output last term of Fibonacci series
int outputFibonacci(int index) 
{ 
	if (index <= 1) return index; // base case for the two first numbers of the fibonacci series 0 and 1
	else 
	{
	  return outputFibonacci(index-1) + outputFibonacci(index-2); 
	}
} //function to output last term of Fibonacci series