#include <algorithm> 
#include <fstream> 
#include <iostream> 
using namespace std; 
  
int main() 
{
  // open a file for input 
  ifstream fin; 
  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  
  // create an empty list 
  const int MAX_SCORES = 100; // capacity 
  int nScores = 0; // initially empty 
  int score[MAX_SCORES]; 
  
  // read and save the scores 
  while (fin.good()) 
  { 
    // read a score from the file 
    int aScore; 
    fin >> aScore; 
    fin.ignore(1000, 10); 
  
    // save score to list, if not full 
    if (nScores < MAX_SCORES) 
      score[nScores++] = aScore; 
  } // while 
  fin.close(); 
  
  sort(score, score + nScores); //this is a function from the algorithm library
  
  // output scores in lo-to-hi order
  for (int i = 0; i < nScores; i++) 
    cout << score[i] << ' '; 
  cout << endl;
}