//Objective:  read from data file students.txt and input all the student information and output a table of students
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //file IO
#include <iomanip> //formatting
#include <iostream> //console IO
#include <string>  //string functions
using namespace std;

//Programmer defined data types
struct Student
{
  string name; //each student name
  int id;  //each student 7 digit ID number
  float gpa;  //each student GPA (to be formatted 
  Student* next; // the next-link which points to next node on the linked list
}; // Student

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);

//main program
int main()
{
  //data
  ifstream fin; //represents the input file
  Student* aStudent; // temporary node to read each student from input file
  Student* start = 0;  //start points to the first node of the list, or is zero if empty linked list
  Student* p; //list pointer points to the current node used for traversing the list
  Student* next; //list pointer points to the next node on the linked list
  string objective = "read from data file students.txt and \n input all the student information and output a table of students"; //program objective
 
  introduction(objective);   // output my name and objective and program information

  // read each data record from input file
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good())
  {
    aStudent = new Student; //create tempory node for each student in input file
    getline (fin, aStudent->name);  //input student name
    fin >> aStudent->id; //input student id
    fin.ignore(1000, 10);
    fin >> aStudent->gpa; //input student gpa
    fin.ignore(1000, 10);
    fin.ignore(1000, 10); // skip the separator line
    aStudent->next = start; // set the next field equal to the start pointer (first node on the list)
    start = aStudent;  //set the start pointer to point to the first node on the list (new node)
  }//while
  fin.close();
 
  // traverse the list and output
  for (p = start; p; p = p->next)
  {
    cout << "Name = " << left << setw(30) << p->name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7) << p->id  << ", gpa = " << p->gpa << endl;
    cout.fill(' '); 
  }//for 

// release borrowed memory
   while(start)
   {
      next = start->next; 
      delete start;
      start = next;
   } // while
}//main

//program introduction
void introduction(string obj)
{
  cout << "Objective: This program will ";
  cout << obj << ".\n";  
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//introduction
