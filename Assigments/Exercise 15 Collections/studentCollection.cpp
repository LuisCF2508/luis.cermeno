//Objective:  Input students from file students.txt and output each students information
//Name: Teacher
//Course: COMSC-110-5003
//Compiler: MinGW
//Editor: MS NotePad

//libraries
#include <deque>  //collection
#include <fstream>  //file IO
#include <iomanip> //formating
#include <iostream>  //console IO
#include <string>  //string functions
using namespace std;

//Programmer defined data types
struct Student
{
  string name; //each student name
  int id;  //each student ID (output as 7 digits)
  float gpa; //each student gpa (output as 2 digits past decimal point)
}; // Student

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string ins); //program introduction 
void outputStudents(deque<Student>& student); //output formatted student records

//main program
int main()
{
  //data
  ifstream fin; //represents input file
  deque<Student> student;  // create an empty list
  Student aStudent;  //each student's information read from input file
  string objective="input students from file students.txt and output each students information"; //program objective
  string instructions = ""; //user instructions
 
  //user introduction
  introduction(objective, instructions);   

  //input from file
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good())
  {
    getline(fin, aStudent.name); 
    fin >> aStudent.id; 
    fin.ignore(1000, 10);
    fin >> aStudent.gpa; 
    fin.ignore(1000, 10);
    fin.ignore(1000, 10); // skip the separator line
    student.push_back(aStudent);
  } // while
  fin.close();
 
  //output all the students
  outputStudents(student);
} // main

//***program introduction
void introduction(string obj, string ins)
{
  //data
  //obj is the program objective
  //ins is the user instructions

  //user introduction
  cout << "Objective: This program will "; 
  cout << obj << ".\n";
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << endl << ins << endl << endl; 
}//introduction

//***output students
void outputStudents(deque<Student>& student)
{
  //data
  int i; //loop index
  //student is a collection of student records of datatype Student containing fields for name, id, gpa

  //output each student in the collection
  for (i = 0; i < student.size(); i++)
  {
    cout << "Name = " << left << setw(30) << student[i].name;
    cout.fill('0');  
    cout << " ID = " << right << setw(7) << student[i].id;
    cout.setf(ios::fixed|ios::showpoint);
    cout << ", gpa = " << setprecision(2) << student[i].gpa << endl;
    cout.fill(' '); 
  } // for
} // outputStudents