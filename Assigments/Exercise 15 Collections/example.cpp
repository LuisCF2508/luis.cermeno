//Fibonacci Series using Recursion 
#include<iostream> 
using namespace std; 

int fib(int index) 
{ 
	if (index <= 1) return index; // base case for the two first numbers of the fibonacci series 0 and 1
	else 
	{
	  return fib(index-1) + fib(index-2); 
	}
} 

int main () 
{ 	
	int index;
	int i;

	while (true)
  	{
		cout << "Enter an index [0 or greater]: ";
		cin >> index;
		cin.ignore(1000, 10);
		if (index >= 0) break;
		else cout << "Invalid input, please try.." << endl;
  	}//while true for input validation 
	for (i = 0; i <= index; i++) 
	{
	  cout << fib(i) << " ";
	}
	cout << endl << "The fibonacci number at index " << index << " is " << fib(index) << endl; 
} 

// This code is contributed 
// by Akanksha Rai 
