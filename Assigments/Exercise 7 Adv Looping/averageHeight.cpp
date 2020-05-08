//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
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
  double height = 0; //each student's height (decimal) valid values [0-250]
  int count = 0; //total number of people in the classroom (integer)
  double sum = 0; //total of all the people's height in the classroom (decimal)
  double averageHeight; //average height of everyone in the room (decimal) formatted to 1 digit past the decimal point


  //NONE

  // introduction
  cout << "Objective: Calculate the average height of everyone in the classroom.\n"; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Input each person's height, sum height, and count each person.
  while (true) //main while loop for the user to enter their height values
  {
    cout << "Enter one person's height in cm [0-250 or -1 if there are no more people]: ";
    cin >> height;
    cin.ignore(1000,10);
    if (height == -1) break; //check sentinel value to exit the loop
    else if (height <= 0 || height >= 250) //check for valid input
    {
      cout << "Invalid input, please try again" << endl; 
    }
    else // if everything is alright then start adding the values to the variable sum and one more person to the total of count
    {
    sum = sum + height;
    count++;
    }
  } // main while loop ends
  
  if (count > 0) averageHeight = sum / count; //count cannot be zero, otherwise averageHeight wouldn't be defined
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);
  cout << "The average height of everyone in the room is " << averageHeight;


}//main