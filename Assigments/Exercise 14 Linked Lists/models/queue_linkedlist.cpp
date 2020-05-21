//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <fstream> 
#include <iostream> 
using namespace std; 

//Programmer defined data types
struct Node
{
    int value;
    Node* next; // the link
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE


//Programmer defined functions
void introduction(string obj);//user introduction

//main program
int main() 
{ 
  ifstream fin; 
  fin.open("numbers.txt"); 
  if (!fin.good()) throw "I/O error"; 
  
  // data 
  string objective = "Objective: Analize how stack modeled linked list store their values.\n";
  Node* start = new Node; //empty linked list
  Node* final = start;

  //introduction
  introduction(objective);

  //input scores from file numbers.txt and sum and count each score 
  while (fin.good()) 
  {
    //write data in node
    fin >> final->value;
    fin.ignore(1000, 10);
    //preparation for next node
    final->next = new Node; //creates a new node and make next to point there
    final = final->next; //updates the pointer final to next node
    final->next = 0; //updates next to cero in case is the last one
  } // while 
  fin.close(); 

    //output values
    cout << "The queue (first come first serve) linked list is stored in order: ";
    Node* p;
    for (p = start; p; p = p->next) cout <<  p->value << " ";
} // main 

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
  cout << "The file name used is scores.txt" << endl << "Please make sure you have this file ready" << endl << endl;

}//introduction function