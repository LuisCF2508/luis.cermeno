//Objective: store student records in an array based list
//Author: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: Notepad

//Libraries
#include <fstream> //file IO
#include <iomanip> //formatting
#include <iostream> //console IO
#include <string> //string functions
using namespace std;

//Programmer defined data types
struct Student
{
  string name; //student name field
  int id;      //student ID field
  float gpa;   //student GPA field
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions 
void introduction(string obj); //program introduction
void sortStudents(Student* student, int nStudents); //sort student records
void outputStudents(Student* student, int nStudents); //output student records

//main program
int main()
{
  //data
  ifstream fin; //represents input file
  const int MAX_STUDENTS = 100; // capacity of array based list student
  int nStudents = 0; // number of students in array based list student
  Student student[MAX_STUDENTS];  //array based list student
  Student aStudent; //each student read from input file
  string objective = "store student records in an array based list"; //program objective

  //output program introduction
  introduction(objective); 

  // input student records
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good())
  {
    getline(fin, aStudent.name);
    fin >> aStudent.id;
    fin.ignore(1000, 10);
    fin >> aStudent.gpa;
    fin.ignore(1000, 10);
    fin.ignore(1000, 10); // skip the ---------- separator
    if (nStudents < MAX_STUDENTS)
    {
      student[nStudents++] = aStudent;
    }//if
  }//while not EOF
  fin.close(); //close input file
 
  sortStudents(student, nStudents); // sort the students by name
  
  outputStudents(student, nStudents);  //output list
 
} // main

//***output program introduction
void introduction(string obj)
{
  //data
  //obj is the objective of the program

  // output my name and objective and program information
  cout << "Objective: This program will ";
  cout << obj << ".\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
} // introduction

//sort student records
void sortStudents(Student* student, int nStudents)
{
   //data
  //student is array based list of students
  //nStudents is the number of students on the list
  int i; //loop index variable (outer loop)
  int j; //loop index variable (inner loop)
  Student temp; //holds a student temporarily during sort swap

  //sort students
  for (i = 0; i < nStudents; i++) //outer loop traversing each student record
  {
    for (j = i + 1; j < nStudents; j++)
    {
      if (student[i].name > student[j].name)
      {
        temp = student[i];
        student[i] = student[j];
        student[j] = temp;
      }//if
    }//for j 
  }//for i
}//sortStudents

//***output the entire table array based list named student of student records 
void outputStudents(Student* s, int n)
{
  //data
  //s is the array based list passed by reference called student in main program
  //n is the array based list size counter passed by value that is a copy of nStudents in main program
  int i; //loop index

  //format output
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  //traverse array based list and output each record
  for (i = 0; i < n; i++)
  {
    cout << "Name = " << left << setw(30) << s[i].name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7)
      << s[i].id << ", gpa = "
      << s[i].gpa << endl;
    cout.fill(' '); 
  }//for i
}//outputStudents