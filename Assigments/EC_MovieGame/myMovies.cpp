//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Apple clang version 11.0.3 (clang-1103.0.32.59)
//Editor: TextEdit

//libraries
#include <fstream>
#include <iomanip>
#include <iostream>
#include <deque>
#include <string>
using namespace std;

#include <cstdlib>
#include <ctime>

//Programmer defined data types
ifstream fin;//creates object to input into file
ofstream fout;//creates object to output into file

struct Movie
{
    string name; // (text) is the name of the movie
    string year; // (text) is the year of the movie
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
void inputMovies(deque<Movie>& movie, Movie& aMovie); //read movie.txt input file and create a list of movies and year created
bool askMovie(deque<Movie>& movie); //randomly pick a movie from the list and output a movie title to the user and ask user what year that movie was made.
char yOrN(string type); //ask the user to play again or ask the user if they want to add another movie to the list
void sortList(deque<Movie>& movie); //sort list of movies with year
void outputList(deque<Movie>& movie); //output the list, lining up all the years after each movie title on each line.

//main program
int main()
{
  //Data
  string objective = "Objective: Read data about movies from a text file and prompt user to guess what year they were filmed and whether they want to add movies to the list.\n";
  char playAgain = 'Y'; // (char) is Y when user wants to guess another year of a movie, and N when user does not
  char anotherMovie; // (char) is Y when user wants to add another movie to the list, and N when user does not
  int score = 0; //(int) is the number of correct guesses made by the user
  deque<Movie> movie; // (collection of objects of data type Movie) list to store the movie data
  Movie aMovie; // (object of data type Movie) temporary variable to store a movie from the file before storing it in the list "movie"
  srand(time(0)); //"seeds the ramdom number generator"

  //User introduction
  introduction(objective);

  //Store the movie data into the list "movie" from the text file movieData
  inputMovies(movie, aMovie);

  //Prompt the user to guess the year of a random movie
  if (movie.size() > 0) //in case of empty file
  {
    while (playAgain == 'Y')
    {
      if (askMovie(movie)) score++;

      //Prompt the user if they would like to play again.
      playAgain = yOrN("playAgain");

      //Prompt the user if they would like to add another movie, if yes append the movie to list "movie" and to file "movieData.txt"
      anotherMovie = yOrN("anotherMovie");
      cout << endl;
      if (anotherMovie == 'Y')
      {
        cout << "Alright, please enter the following data of the movie:" << endl;
        cout << "Name of the movie: ";
        getline(cin,aMovie.name);
        cout << "Year: ";
        getline(cin,aMovie.year);
        cout << endl;
        //Append movie to list
        movie.push_back(aMovie);
        //Append movie to file movieData.txt
        fout.open("movieData.txt", ios::app);
        fout << endl << endl;
        fout << aMovie.name << endl;
        fout << aMovie.year;
        fout.close();
        fout.clear();
      }
    }//while

    //Output number of correct guesses
    cout << "You have correctly guessed the year of " << score << " movies." << endl;

    //Sort list of movies from oldest to newest
    sortList(movie);

    //Output sorted list of movies to console and to file movieData.txt
    outputList(movie);
  }
  else cout << "Sorry, it seems that there are no songs in the file movieData.txt" << endl;
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

//function inputMovies: Read movie.txt input file and create a list of movies and year created
void inputMovies(deque<Movie>& movie, Movie& aMovie)
{
  //Read file and store names and years of the movies
  fin.open("movieData.txt");
  if (!(fin.good())) throw "I/O error";
  while (fin.good())
  {
    getline(fin, aMovie.name);
    getline(fin, aMovie.year);
    if (aMovie.name.length() > 0 && aMovie.year.length() > 0) movie.push_back(aMovie);
    fin.ignore(1000, 10); // skip the separator blank line
  }
  fin.close();
}//function inputMovies

//function askMovie: Randomly pick a movie from the list and output a movie title to the user and ask user what year that movie was made.
bool askMovie(deque<Movie>& movie)
{
  //Data
  bool result = false; // (boolean) is true if the user has guessed right, value returned by the function
  int random; // (integer) a random number to pick up an element of the collection movie.
  string guess; // (text) is the year guessed by the user.

  //Ask random movie
  random = rand() % movie.size();
  cout << "Guess in what year " << movie[random].name << " was filmed: ";
  getline(cin,guess);

  //Evaluate whether user guessed right
  if (guess == movie[random].year) 
  {
    cout << "Correct! you guessed it right!" << endl << endl;
    result = true;
  }
  else cout << "Not quite right! " << movie[random].name << " was filmed in " << movie[random].year << "." << endl << endl;
  return result;
}//function askMovie

//function yOrN: Ask the user to play again or ask the user if they want to add another movie to the list
char yOrN(string type)
{
  //Data
  char result = 'N'; // (char) either Y: yes or N: no input by the user

  //Output prompt depending of the type
  while (true)
  {
      if (type == "playAgain") cout << "Would you like to play again [Y/N]?: ";
      else if (type == "anotherMovie") cout << "Would you like to add another movie to the list [Y/N]?: ";
      cin >> result;
      cin.ignore(1000,10);
      if (toupper(result) == 'Y' || toupper(result) == 'N') break;
      else cout << "Invalid input, please try again" << endl;
  }
  return toupper(result);
}//function yOrN

//function sortList: Sort list of movies with year
void sortList(deque<Movie>& movie)
{
  //Data
  int i;// (integer) a counter to compare each movie i with the rest, outer loop
  int j;// (integer) a counter to select a movie j to compare with the movie i, inner loop
  Movie temp; //(object of data type Movie) a tempory variable used when swaping movies in the collection

	//Sorting
	for(i = 0; i < movie.size() ; i++)
	{		
		for(j = i + 1 ; j < movie.size(); j++)
		{
			if(movie[i].year > movie[j].year)
			{
				temp  = movie[i];
				movie[i] = movie[j];
				movie[j] = temp;
			} // if for swap code block
		}//j for
	}// i for
}//function sortList

//function outputList: Output the list, lining up all the years after each movie title on each line.
void outputList(deque<Movie>& movie)
{
  //Data 
  int i; // (integer) counter to traverse each movie record in the list movie

  //Output formatted table
  cout << endl;
  for (i = 0 ; i < movie.size() ; i ++) 
  {
    cout << left << setw(30) << movie[i].name;
    cout << " Year : " << right << setw(4) << movie[i].year << endl;
  }
  cout << endl;
}//function outputList