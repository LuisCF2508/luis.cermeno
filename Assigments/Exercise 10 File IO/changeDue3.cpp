//Objective:  calculate change due in a transaction using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.
//Name: Luis Cermeno-Farro
//Course: COMSC-110-8215
//Compiler: Xcode
//Editor: MS NotePad-TextEdit

//libraries
#include <fstream>
#include <iostream>
#include <string>
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
 //Data and file input
  int amountOwed; //amount owed
  int cashPaid;//amount paid 
  int totalChangeDue; //total change due
  int changeDue; //change due for each value of bills
  int thousand100; //number of $100000 bills
  int thousand10; //number of $10000 bills
  int thousand5; //number of $5000 bills
  int thousand;  //number of $1000 bills
  int hundred5; //number of $500 bills
  int hundred;  //number of $100 bills
  int fifty;  //number of $50 bills
  int twenty; //number of $20 bills
  int ten;  //number of $10 bills
  int five;  //number of $5 bills
  int two; //number of $2 bills
  int one;  //number of $1 bills
  string enter; // just a variable to confirm wheter the user wants to continue

  //File input

  
  ifstream fin;
  fin.open("change.txt");
  cout << endl << "This program has extracted data from cash.txt, press ENTER to check if the file is correct: ";
  getline(cin,enter);
  if (!fin.good()) throw "I/O error";
  fin >> amountOwed;
  fin.ignore(1000,10);
  fin >> cashPaid;
  fin.ignore(1000,10);
  fin.close();

  //Output user introduction
  cout << endl;
  cout << "Objective: calculate change due in a transaction using these U.S. bills - no cents: \n $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.\n"; 
  cout << "Programmer: Teacher/Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: Notepad/TextEdit\n"; 
  cout << "Compiler(s) used: VC++ 2010 Express/Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

   //Calculate change due
  totalChangeDue = cashPaid - amountOwed;
  changeDue = totalChangeDue;
  thousand100 = changeDue / 100000;  //number of $100,000 bills
  changeDue = changeDue % 100000;  //remainder from $100,000 
  //NOTE: for the % operation: if numerator is less than denominator then the answer will be zero because changeDue has been declared as an integer, cannot accept decimals.
  thousand10 = changeDue / 10000;  //number of $10,000 bills
  changeDue = changeDue % 10000; //remainder from $10,000
  thousand5 = changeDue / 5000;  //number of $5,000 bills
  changeDue = changeDue % 5000;  //remainder from $5,000 bills
  thousand = changeDue / 1000;  //number of $1,000 bills
  changeDue = changeDue % 1000;  //remainder from $1,000 bills
  hundred5 = changeDue / 500;  //number of $500 bills
  changeDue = changeDue % 500;  //remainder from $500 bills
  hundred = changeDue /100;  //number of $100 bills
  changeDue = changeDue % 100;  //remainder from $100 bills
  fifty = changeDue / 50;  //number of $50 bills
  changeDue = changeDue % 50;  //remainder from $50 bills
  twenty = changeDue / 20;  //number of $20 bills
  changeDue = changeDue % 20;  //remainder from $20 bills
  ten = changeDue / 10;  //number of $10 bills
  changeDue = changeDue % 10;  //remainder from $10 bills
  five = changeDue / 5; //number of $5 bills
  changeDue = changeDue % 5; //remainder from $5 bills
  two = changeDue / 2; //number of $2 bills
  changeDue = changeDue % 2; //remainder from $2 bills
  one = changeDue; //number of $1 bills

  //Output calculated change due for each kind of monetary demonination
  cout << "Amount owed: " << amountOwed << endl;
  cout << "Amount cash paid: " << cashPaid << endl;
  cout << endl;
  cout << "Change due: " << totalChangeDue <<endl;
  cout << "Change paid out in: " << endl;
  cout << "-this many $100,000 bills: " << thousand100 << endl;
  cout << "-this many $10,000 bills: " << thousand10 << endl;
  cout << "-this many $5,000 bills: " << thousand5 << endl;
  cout << "-this many $1,000 bills: " << thousand << endl;
  cout << "-this many $500 bills: " << hundred5 << endl;
  cout << "-this many $100 bills: " << hundred << endl;
  cout << "-this many $50 bills: " << fifty << endl;
  cout << "-this many $20 bills: " << twenty << endl;
  cout << "-this many $10 bills: " << ten << endl;
  cout << "-this many $5 bills: " << five << endl;
  cout << "-this many $2 bills: " << two << endl;
  cout << "-this many $1 bills: " << one << endl; 
  cout << endl;
}