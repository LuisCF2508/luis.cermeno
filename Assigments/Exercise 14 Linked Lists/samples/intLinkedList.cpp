//Objective:  input scores between 0 -100 until sentinel value of -1, and output number of scores and average score
//Name: Teacher
//Course: COMSC-110-1021
//Compiler: MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //console IO
using namespace std;

//Programmer defined data types
struct Score
{
  int value;  //each score
  Score* next; // the link
};

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
  int count = 0; // to count the number of nodes in the list
  int sum = 0; // to accumulate the total of all scores in the list
  float average; //calculated average score of all the scores in the list
  Score* p; //points to current node in the list used to traverse the list
  Score* start = 0;  //points to the first node of the linked list or is zero when empty linked list
  Score* aScore; //points to new node: a temporary node for each score input from keyboard
  Score* nextNode; //points to the next node on the list
  string objective = "input scores between 0 -100 until sentinel value of -1, \n and output number of scores and average score.\n"; 

  introduction(objective);   // output my name and objective and program information

  // input each records and save as a node on the linked list
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
 
  // traverse the list and get the average
  for (p = start; p; p = p->next)
  {
    sum += p->value;
    count++;
  }//for

  // output the result
  if (count > 0)
  {
    average = (float)sum / count;
    cout << "The average of " << count << " scores is " << average << endl;
  }
  else
    cout << "No values were entered.\n";

  // release borrowed memory
   while(start)
   {
      nextNode = start->next; 
      delete start;
      start = nextNode;
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
