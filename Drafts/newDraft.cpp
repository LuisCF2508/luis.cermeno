//Objective:  Draft
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
  double amountRice = 1;
  double amountWater = 2;
  double numberDish = 1;
  string initialGreeting = "Welcome to MyRiceCalculator!";
  string objective = "This program outputs the amount of water or rice needed to cook a traditional rice dish.";
  string closing = "Thank you for using this app, hope you enjoyed it!.";

  cout << endl;
  cout << initialGreeting << endl;
  cout << objective << endl;
  cout << endl;
  cout << "The amount of rice needed to make " << numberDish << " dish of regular white rice is:" << endl;
  cout << "- " << amountRice << " cup of rice." << endl;
  cout << "- " << amountWater << " cup of water." << endl;
  cout << endl;
  cout << closing;
  cout << endl;
 

}//main