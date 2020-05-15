//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3 (clang-1103.0.32.59)
//Editor: TextEdit

//libraries
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Programmer defined data types
struct Student
{
  string name;
  int id;
  float gpa;
  Student* next; // the next-link
}; // Student

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction

//main program
int main()
{
  //Data
  string objective = "Objective: Read name, student id, and GPA from a text file and output a formatted table of students with the data.\n";
  ifstream fin;
  int nStudents = 0;
  //user introduction
  introduction(objective);

  // open a file for input
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
 
  // create an empty linked list
  Student* start = 0;
 
  // read and save the records
  while (fin.good())
  {
    // Step 1, create a node
    Student* aStudent = new Student;

    // Step 2, read its data fields
    getline (fin, aStudent->name);

    fin >> aStudent->id;
    fin.ignore(1000, 10);
 
    fin >> aStudent->gpa;
    fin.ignore(1000, 10);
 
    fin.ignore(1000, 10); // skip the separator line

    // Step 3, add new node to the list
    aStudent->next = start;
    start = aStudent;
    nStudents++;
  }
  fin.close();

  //output number of students
  cout << nStudents << " students found in the text file." << endl;
  // traverse the list and output
  Student* p;
  for (p = start; p; p = p->next)
  {
    cout << "Name = " << left << setw(30) << p->name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7) << p->id
      << ", gpa = " << p->gpa << endl;
    cout.fill(' '); 
  }

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
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function