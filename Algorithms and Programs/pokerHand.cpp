//Objective:  deal a poker hand of 5 cards
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
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
  srand(time(0)); rand(); // "seed" the random number generator
  int n = 5; // deal this many cards
  int value;  //a card value [2-10, 11=Jack, 12=Queen, 13=King, 1=Ace]
  int suit; //a card suit [0=Spade, 1=Heart, 2=Diamond, 3=Club]
  int i;  //loop index

  // introduction
  cout << "Objective: This program will deal a poker hand of 5 cards.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //deal a hand
  for (i = 0; i < n; i=i+1)
  {
    value = 1 + rand() % 13; //a card value
    suit = rand() % 4; //a card suit
    switch (value)
    {
      case 1:
        cout << "Ace";
        break;
      case 11:
        cout << "Jack";
        break;
      case 12:
        cout << "Queen";
        break;
      case 13:
        cout << "King";
        break;
      default:
        cout << value;
    }//switch to determine card value

    switch (suit)
    {
      case 0:
        cout << " of Spades" << endl;
        break;
      case 1:
        cout << " of Hearts" << endl;
        break;
      case 2:
        cout << " of Diamonds" << endl;
        break;
      case 3:
        cout << " of Clubs" << endl;
    } // switch to determine card suit
  } // for loop to deal n cards
}//main
