#include <iostream>
#include <deque>
using namespace std;

struct Score
{
  int value;  //each score
  Score* next; // the link
};

struct Student
{
  string name; //each student name
  int id;  //each student ID (output as 7 digits)
  float gpa; //each student gpa (output as 2 digits past decimal point)
}; // Student


int main()
{
  //aray based lists
const int MAX_SCORES = 100; // array based list capacity 
int nScores = 0; // number of values on the array based list
int score[MAX_SCORES]; //array based list of values

  //linked list
        Score* start = 0;  //points to the first node of the linked list or is zero when empty linked list
        Score* aScore; //points to new node: a temporary node for each score input from keyboard

        while (true)
        {
          aScore = new Score; //create temporary node

          cout << "Enter a score [0 to 100 or -1 to quit]: ";
          cin >> aScore->value;
          cin.ignore(1000, 10);
          if (aScore->value == -1) break;     // before linking it in, check for sentinel value
          if (aScore->value >= 0 && aScore->value <= 100)
          {
            // add node to list as first node in the list
            aScore->next = start; 
            start = aScore;
          }//if
        } //while true

        Score* p;
        for (p = start; p; p = p->next)
        {
          p->value = 1 ; //change data or retrieve
        }

    //collections
        deque<Student> student;  // create an empty list
        Student aStudent;  //each student's information temporary to be pushed into the collection
        //.....do stuff with aStudent..../
        student.push_back(aStudent); //push student to the back
        student.pop_front(); // in case of removing one element from the front



  
}