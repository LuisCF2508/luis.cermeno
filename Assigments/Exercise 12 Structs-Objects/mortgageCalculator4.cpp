//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include <cmath>

//Programmer defined data types
struct Mortgage
{
  float p; // (decimal) amount borrowed (we dont need that much of precision here)
  double rate; //(double) annual interest rate
  int n; // (integer) number of monthly payments
  double payment; // (decimal) the monthly payment

}; //Mortgage

ifstream fin; //defining object for file input
ofstream fout; //defining object for file output

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
void password(); // request and check correct password
string getFileName(); // request name of input file and check for valid input

//main program
int main()
{
  //Data
  string objective = "Objective: Determine the monthly payment on borrowed amount of money to be paid back in a 30 years fixed loan.\n";
  string userFile; //(text) the name of the input file
  Mortgage user; //object to store user input values

  //User introduction
  introduction(objective);

  //Security
  password();
  
  //User File Input
  userFile = getFileName();
  fin.open(userFile.c_str()); //opening the file
  if (!fin.good()) throw "I/O error"; //check for errors
  for (int i = 0; i < 2; i++)
  {
    switch (i)
    {
      case 0 :
        fin >> user.p;
        fin.ignore(1000,10);
        break;
      case 1 :
        fin >> user.rate;
        fin.ignore(1000,10);
        break;
    }
  }
  fin.close();
  
  //Calculation of payment
  user.n = 30; //considering 30 month fixed loan (programmer input)
  user.payment = (user.p * pow(1 +(user.rate/1200), user.n * 12) * (user.rate/1200)) / (pow((1 + (user.rate/1200)), user.n * 12) - 1);
  
  //Echo input values and output value of payment
  cout << endl << "Amount borrowed (user input) = $" << user.p << endl; 
  cout << "Annual interest rate (user input) = " << user.rate << "%" << endl;
  cout << "Payback period (programmer input) = " << user.n << " Years" << endl;
  cout.setf(ios::fixed|ios::showpoint); // turning on formating for the upcoming output
  cout << setprecision(2); // formating the outpout so that amountSaved is displayed with two digits after decimal point.
  cout << "Monthly payment (output) = $" << user.payment << endl;

  //Output to text file "mortgage.txt"
  fout.open("mortgage.txt");
  fout << "Amount borrowed (user input) = $" << user.p << endl; 
  fout << "Annual interest rate (user input) = " << user.rate << "%" << endl;
  fout << "Payback period (programmer input) = " << user.n << " Years" << endl;
  fout.setf(ios::fixed|ios::showpoint); // turning on formating for the upcoming output
  fout << setprecision(2); // formating the outpout so that amountSaved is displayed with two digits after decimal point.
  fout << "Monthly payment (output) = $" << user.payment << endl;
  cout << endl << "Results have been saved to text file named mortgage.txt" << endl;
  fout.close();
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
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl; 

}//introduction function


void password() // request and check correct password
{
  string pass; //(text) attemp of password by the user
  while (true)
  {
    cout << endl << "Please enter the password for the program :";
    getline(cin,pass);
    if (pass == "1837034") break;
    else cout << "Sorry, incorrect password, try again...";
  }
}// request and check correct password

string getFileName() // request name of input file and check for valid input
{
  string read;
  do 
  {
    cout << endl << "Please enter an input filename [i.e.: x.txt]: ";
    getline(cin, read);
  }while(!(read.length() >=5)); //do-while
  return read;
}// request name of input file and check for valid input









