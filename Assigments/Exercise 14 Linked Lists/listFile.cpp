#include <fstream> 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
  ifstream fin; 
  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  
  // create an empty list 
  const int MAX_SCORES = 100; // list capacity 
  int nScores = 0; // initially empty 
  int score[MAX_SCORES]; 
  
  // read and save the scores 
  while (fin.good()) 
  { 
    // read a score from the file 
    int aScore; // temporary storage for new score
    fin >> aScore; 
    fin.ignore(1000, 10); 
  
    // add new score to list, if list is not full 
    if (nScores < MAX_SCORES) 
      score[nScores++] = aScore; 
  } // while 
  fin.close(); 
  
  // find the average 
  int i; // loop counter 
  int scoreTotal = 0; 
  for (i = 0; i < nScores; i++) 
    scoreTotal += score[i]; 
  double average = (double)scoreTotal / nScores; 
  cout << "The average of " << nScores 
    << " numbers is " << average << endl; 
  
  // count number of scores > average 
  int nGreater = 0; 
  for (i = 0; i < nScores; i++) 
    if (score[i] > average) nGreater++; 
  cout << nGreater  << " scores are greater than the average." << endl; 
} // main 