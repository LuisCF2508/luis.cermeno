//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3 (clang-1103.0.32.59)
//Editor: TextEdit

//libraries
#include <fstream> 
#include <iostream> 
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
void getStatistics(int* score, int nScores); //get Statistics function
void sort(int* score, int nScores);//function for sorting list from lowest to highest

//main program
int main()
{
  //Data and creation of empty list to store scores
  string objective = "Objective: Read scores [0-100] from input file and calculate the highest, lowest, average scores, number of scores greater than the average, and number of perfect scores.\n";
  const int MAX_SCORES = 100; // (integer) list capacity 
  int nScores = 0; // (integer) counter to track how many scores are stored in the list so far  
  int score[MAX_SCORES]; // (array of integers) list of scores
  int aScore; //(integer) a valid score read from the file
  ifstream fin; //object for file input

  //User introduction
  introduction(objective);
 
  //Read file, save valid scores to list, and output them unsorted
  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  cout << "Scores found: ";
  while (fin.good()) 
  { 
    fin >> aScore; 
    fin.ignore(1000, 10); 
    if (nScores < MAX_SCORES && aScore > 0 && aScore <= 100 && aScore != ' ') 
    {
      score[nScores++] = aScore;// save score to list, if not full and if not an invalid input
      cout << aScore << " ";
    } 
  } // while 
  fin.close();
  // Calculate statistics from the array of scores and output them
  if (nScores > 0) getStatistics(score, nScores); //calling getStatistics only if file is not empty
  else cout << "Sorry, no valid scores found in file." << endl; // otherwise input error message
}//main


//introduction function
void introduction(string obj)//user introduction
{
  //introduction
  cout << endl;
  cout << obj; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Apple clang version 11.0.3 (clang-1103.0.32.59)\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//introduction function

//getStatistics function
void getStatistics(int* score, int nScores)
{
  //Data
  int i; // (integer) counter to traverse file line by line
  int sum = 0; //(integer) sum of all scores stored in list
  double avg; // (decimal) the average of all scores stored in list
  int nGreater = 0; //(integer) the number of scores greater than the average
  int nPerfect = 0; //(integer) the number of perfect scores (equal to 100)

  //Sum all the scores and calculate average
  for (i = 0; i < nScores; i++) sum = sum + score[i];
  avg = double(sum) /nScores;

  //Find number of scores greater that the avg, number of avg scores, and perfect scores
  for (i = 0; i < nScores;i++)
  {
      if (score[i] > avg) nGreater++;
      if (score[i] == 100) nPerfect++;
  }
  //Sort the list from lowest to highest score
  sort(score, nScores); //this is a function from the algorithm library
  
  //Output sorted list, highest, lowest, number of average scores, number of scores >averag and number of perfect scores
  cout << endl << "Scores sorted from lowest to highest: ";
  for (int i = 0; i < nScores; i++) cout << score[i] << ' ';
  cout << endl;
  cout << "The highest score is: " << score[nScores-1] << endl;
  cout << "The lowest score is: " << score[0] << endl;
  cout << "The average score is: " << avg << endl;
  cout << "The number of scores greater than the average is : " << nGreater << endl;
  cout << "The number of perfect scores is : " << nPerfect << endl;
}//get Statistics function


//function for sorting list from lowest to highest
void sort(int* score, int nScores)
{
  int i;// (integer) a counter to compare each character i with the rest
  int j;// (integer) a counter to select a character j to compare with character i
  int temp; //(integer) a tempory variable used when swaping elements from the list
	//sorting
	for(i=0;i<nScores;i++)
	{		
		for(j=i+1;j<nScores;j++)
		{
			if(score[i]>score[j])
			{
				temp  =score[i];
				score[i]=score[j];
				score[j]=temp;
			} // if for swap code block
		}//j for
	}// i for
}//function for sorting list from lowest to highest
