//Objective:  Objective: calculate the accumulated money from depositing $ monthly, earning % interest, over years.
//Name: Teacher
//Course: COMSC-110-8269
//Compiler: MS Visual Studio 2013
//Editor: JNotePad

//libraries
#include <iostream> //formatting library
#include <iomanip>
using namespace std;
#include <cmath> //math library

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
  //data
  double interestRate =7.5; // = annual interest rate (decimal)
  double s; // = the sum at the end of the number years (decimal)
  double D = 100.0; // = monthly deposit (decimal)
  double p; // = monthly interest (decimal)
  int T; // = number of months (integer)
  int years = 10; // = number of years (integer)

  // output my name and objective and program information
  cout << "Objective: calculate the accumulated money from depositing $ monthly, earning % interest, over years.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM Min-GW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //calculations
  //calculate monthly interest
  p = (interestRate/100.0)/12.0;
  //calculate number of months
  T= years * 12;
  //calculate sum at the end of the number years
  s = D * ((pow((1.0+p),T)-1)/p);

  //output results  with two decimal places
  cout.setf(ios::fixed|ios::showpoint); //turn on formatting for decimals
  cout << setprecision(2); //set to two digit after decimal point as maximun
  cout << "In " << years << " years, $" << D << " deposited per month will grow to $" << s << " earning " << interestRate << "% interest" << endl;

  //output results  as original
  cout.unsetf(ios::fixed|ios::showpoint); // turn off formatting for decimals
  cout << setprecision(6); //reset digits after decimal point to its default
  cout << "In " << years << " years, $" << D << " deposited per month will grow to $" << s << " earning " << interestRate << "% interest" << endl;

  //output results  truncated to nearest integer
  cout.setf(ios::fixed); // turn on formatting without decimals (whole part only)
  cout << setprecision(0); //no digits after decimal point.
  cout << "In " << years << " years, $" << D << " deposited per month will grow to $" << s << " earning " << interestRate << "% interest" << endl;

  //output results  with 4 digits in TOTAL as maximun
  cout.unsetf(ios::fixed); // no need to turn on formatting
  cout << setprecision(4); //4 digits in total
  cout << "In " << years << " years, $" << D << " deposited per month will grow to $" << s << " earning " << interestRate << "% interest" << endl;
}//main