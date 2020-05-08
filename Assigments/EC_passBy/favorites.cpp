//Objective:  template for C++ programs and to test code
//Name: Luis Cermeno-Farro 1837034
//Course: COMSC-110-8076
//Compiler: Xcode
//Editor: TextEdit

//libraries
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Programmer defined data types
ifstream fin; //object for file input

struct Favorites
{
  string movie; // (text) person's favorite movie
  string song; // (text) person's favorite song
  string food; // (text) person's favorite food
  string sport; // (text) person's favorite sport
  string tvShow; // (text) person's favorite tvShow
  string book; // (text) person's favorite book
  string place; // (text) person's favorite place
}; //Favorite


//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
void outputRecord(Favorites& x, int nPerson, string* name);//output record function
void outputRawData(Favorites* a, string* whoAreYou, int nRecords); //output raw data function

//main program
int main()
{
  //Data
  string objective = "Objective: Output a person's favorite things and ask the user what person they think it is.\n";
  string readLine; //(text) variable to store temporarily each line of the text file favoritesData.txt
  bool error; //(bolean) variable that becomes true if the input file is not properly formatted
  int i; //(integer) counter for traversing arrays and read file

  //User introduction
  introduction(objective);

  //Creation of the array of objects and whoAreYou
  const int N = 12; // list capacity: maximun possible records to store)
  int nRecords = 0; // list size: counts how many record has been stored
  Favorites a[N]; // array of objects for each field of Favorites
  string whoAreYou[N]; // array of strings to store each name input by the user

  //Read and output text of the file, prompt the user for a name and store data in the arrays.
  fin.open("favoritesData.txt");
  if (!fin.good()) throw "I/O error"; //check for errors
  while ( (fin.good()) && (error == false) && (nRecords < 12) )
  {
    for (i = 0; i < 8 ; i++)
    {
      getline(fin,readLine);
      if ( (readLine.length() == 0) && (i != 7) ) //check for undesirable spaces between records in the text file...
      {
      cout << "ERROR: favoritesData.txt is not properly formated. Program is not able to retrieve data properly." << endl;
      error = true;
      break;
      }
      switch (i)
      {
        case 0: 
          a[nRecords].movie = readLine;
          cout << "favorite movie: " << a[nRecords].movie << endl;
          break;
        case 1: 
          a[nRecords].song = readLine;
          cout << "favorite song: " << a[nRecords].song << endl;
          break;
        case 2: 
          a[nRecords].food = readLine;
          cout << "favorite food: " << a[nRecords].food << endl;
          break;
        case 3: 
          a[nRecords].sport = readLine;
          cout << "favorite sport: " << a[nRecords].sport << endl;
          break;
        case 4: 
          a[nRecords].tvShow = readLine;
          cout << "favorite tvShow: " << a[nRecords].tvShow << endl;
          break;
        case 5: 
          a[nRecords].book = readLine;
          cout << "favorite book: " << a[nRecords].book << endl;
          break;
        case 6: 
          a[nRecords].place = readLine;
          cout << "favorite place: " << a[nRecords].place << endl;
      } //switch
    }//for
    if (error == true) break;
    cout << "Who is this?: ";
    getline(cin,whoAreYou[nRecords]);
    cout << endl;
    nRecords++; 
  }//while

  if (error == false)
  {
    //Output each record of the table
    cout << "-------------------------------------------" << endl;
    for (i = 0 ; i < nRecords; i++) outputRecord(a[i],i,whoAreYou);

    //Output raw data
    cout << "-------------------------------------------" << endl;
    outputRawData(a,whoAreYou,nRecords);
  }
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
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

}//introduction function

//output record function
void outputRecord(Favorites& x, int nPerson, string* name)
{
  cout << "Person #" << nPerson + 1 << ":you think is: " << name[nPerson] << endl;
  cout << "favorite movie: " << x.movie << endl;
  cout << "favorite song: " << x.song << endl;
  cout << "favorite food: " << x.food << endl;
  cout << "favorite sport: " << x.sport << endl;
  cout << "favorite tvShow: " << x.tvShow << endl;
  cout << "favorite book: " << x.book << endl;
  cout << "favorite place: " << x.place << endl;
  cout << endl;
}//output record function

//output raw data function
void outputRawData(Favorites* a, string* whoAreYou, int nRecords)
{
  int i;//(integer) counter for traversing the arrays
  for (i = 0 ; i < nRecords; i++) cout << "whoAreYou[" << i << "]: " << whoAreYou[i] << endl;
  cout << "fields = movie, song, food, sport, TV show, book, place." << endl;
  for (i = 0 ; i < nRecords; i++)
  {
  cout << "a[" << i << "]: " << a[i].movie << endl;
  cout << "a[" << i << "]: " << a[i].song << endl;
  cout << "a[" << i << "]: " << a[i].food << endl;
  cout << "a[" << i << "]: " << a[i].sport << endl;
  cout << "a[" << i << "]: " << a[i].tvShow << endl;
  cout << "a[" << i << "]: " << a[i].book << endl;
  cout << "a[" << i << "]: " << a[i].place << endl;
  }
}//output raw data function






