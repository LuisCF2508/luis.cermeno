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
//NONE

//main program
int main()
{
  //Data
  int number1; //(integer) the first number of the arithmetic operation.
  int number2; //(integer) the second number of the arithmetic operation.
  int operation; //(integer) the arithmetical operation the user want to calculate, being 1= addition  2= subtraction  3= multiplcation  4= division.
  int result; //(integer) the result of the arithmetical calculation.
  char sentinel; //(character) a letter 'Y' or 'N' that indicates whether or not the user wants to do another calculation.

  // introduction
  cout << "Objective: Add, subtract, multiplicate or divide two numbers.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  // loop where the user either inputs their numbers and operator, or quits the program.xs

  while (true) //main loop
  {
    cout << "Please enter first number: ";
    cin >> number1;
    cin.ignore(1000,10);
    cout << "Please enter second number: ";
    cin >> number2;
    cin.ignore(1000,10);

    while (true) //loop for input validation of "operation"
    {
      cout << "Please enter operator [1= addition  2= subtraction  3= multiplication  4= division]:";
      cin >> operation;
      cin.ignore(1000,10);
      if (operation < 1 || operation > 4)
      {
        cout << "Invalid input, please try again..." << endl;
        continue;
      }
      else if (operation == 1)
      {
        result = number1 + number2;
        cout << number1 << "+" << number2 << "=" << result << endl;
        break;
      }
      else if (operation == 2)
      {
        result = number1 - number2;
        cout << number1 << "-" << number2 << "=" << result << endl;
        break;
      }
      else if (operation == 3)
      {
        result = number1 * number2;
        cout << number1 << "*" << number2 << "=" << result << endl;
        break;
      }
      else if (operation == 4)
      {
        result = number1 / number2;
        cout << number1 << "/" << number2 << "=" << result << endl;
        break;
      }
    } //loop for input validation of "operation"

    while (true) //loop for input validation of "sentinel"
    {
      cout << "Another calculation [Y=yes or N=no]: ";
      cin >> sentinel;
      cin.ignore(1000,10);
      if (sentinel != 'Y' && sentinel != 'N')
      {
        cout << "Invalid character, please try again..." << endl;
        continue;
      }
      else break;
    } //loop for input validation of "sentinel"

    if (sentinel == 'Y') continue;
    if (sentinel == 'N') break;
      
  } // main loop

}//main