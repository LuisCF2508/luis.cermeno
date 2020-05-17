//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3 (clang-1103.0.32.59)
//Editor: TextEdit

//libraries
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include <ctime>


//Programmer defined data types
ifstream fin;
struct list
{
  string name; // (text) is the name of a song 
}; // list

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
void outputSong(deque<list>& lastSongs, string* song, int nSongs);//outputSong
bool checkRepeated(deque<list>& lastSongs, string song);//check for repeated value function


//main program
int main()
{
  //Data
  string objective = "Objective: Read song names from a text file named songs.txt, randomly select one song and output its song to the user.\n";
  
  const int MAX_SONGS = 200; // (integer) is the maximun song names that th list song can process
  int nSongs = 0;// (integer )is how many song names the list has so far
  string song[MAX_SONGS];// (list)  is the list of song names

  string lineFromFile; // (text) is a line from the text file
  char playAgain; //(integer) 'Y' for yes or 'N' for no.
  
  deque<list> lastSongs; // collection of guesses
  list userGuess; //(object) a temporary object to store user input lastSongs

  srand(time(0)); //"seeds the ramdom number generator"

 

  //user introduction
  introduction(objective);
  //store the song names 
  fin.open("songs.txt");
  if (!(fin.good())) throw "I/O error";
  while (fin.good() && nSongs < 200)
  {
    getline(fin, lineFromFile);
    if (lineFromFile.length() > 0) //to skip blank spaces
    {
      song[nSongs] = lineFromFile; 
      nSongs++;
    }
  }
  fin.close();

    //prompt the user if they want to play a song, select one randomly and output its name
    while (true) // loop for input validation of playAgain
    {
      cout << "play a song [Y/N] ?:";
      cin >> playAgain;
      cin.ignore(1000,10);
      if (toupper(playAgain) == 'N') 
      {
        break;
      }
      else if (toupper(playAgain) == 'Y') 
      {
        outputSong(lastSongs, song, nSongs);
        continue;
      }
      else cout << "Invalid input, please try again" << endl;
    } // loop for input validation of playAgain
  
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

//function checkRepeated: check for repeated value function
bool checkRepeated(deque<list>& lastSongs, string song)
{
  //Data
  int i;
  bool repeated = false;

  //Traverse collection to check for repeated values
  cout << "program has entered check repeated funtion with size of lastSongs : " << lastSongs.size() << endl;
  for (i = 0; i < lastSongs.size(); i++)
  {
    if (song == lastSongs[i].name) repeated = true;
  }
  if (!repeated) cout << "repeated is not repeated, repeate is false" << endl; else cout << "the song has played in the last 5, repeated is true " << endl;
  return repeated;
}//function checkRepeated

//function outputSong
void outputSong(deque<list>& lastSongs, string* song, int nSongs)
{
  int random; // (integer) a random number from 0-199
  list aSong;

  while (true)
  {
    cout << "current size of collections : " << lastSongs.size() << endl;
    random = rand() % nSongs;
    cout << "the random number selected is " << random << " and the song selected is " << song[random] << endl;
    if (checkRepeated(lastSongs, song[random])) continue;
    else 
    {
      cout << song[random] << endl;
      aSong.name = song[random];
      lastSongs.push_back(aSong);
      if (lastSongs.size() > 5) lastSongs.pop_front();
      break;
    }
  }
}
//function outputSong