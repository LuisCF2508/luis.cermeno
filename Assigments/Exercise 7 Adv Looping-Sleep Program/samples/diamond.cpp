#include <iostream> 
using namespace std; 
  
int main() 
{ 
  int n; // output this many rows 
  cout << "How many rows to output? "; 
  cin >> n; 
  cin.ignore(1000, 10); 
  int stars = 1; 
  int skip = n - 1; 
  int i; 
  for (i = 0; i < n; i++) 
  { 
    int j; 
    for (j = 0; j < skip; j++) cout << ' '; 
    for (j = 0; j < stars; j++) cout << '*'; 
    cout << endl; 
    stars += 2; 
    skip--; 
  } // for 
  stars = 2 * n - 3; 
  skip = 1; 
  int extraRows = n - 1; 
  for (i = 0; i < extraRows; i++) // reuses i 
  { 
    int j; 
    for (j = 0; j < skip; j++) cout << ' '; 
    for (j = 0; j < stars; j++) cout << '*'; 
    cout << endl; 
    stars -= 2; 
    skip++; 
  }
} // main 