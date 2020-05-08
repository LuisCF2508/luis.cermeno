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

#include <cstdlib> //libraries to generate a random number
#include <ctime>

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj);//user introduction
void f_bestScore(); //function to read "mastermindScore.txt" and output best score.
char f_randomChar(); //function to generate random character
int f_correctColors(char c1,char c2,char c3,char c4,char u1,char u2,char u3,char u4);//function to evaluate how many correct colors the user got correct
int f_correctPositions(char c1,char c2,char c3,char c4,char u1,char u2,char u3,char u4);//function to evaluate how many correct positions the user got correct
void f_appendScore(int userScore); //function to append userScore in the text file "mastermindScore.txt"

//main program
int main()
{
  //Data
  string objective = "Objective: Interactive game in which the user will have 10 oportunities to guess the correct sequence of 4 colors.\n";
  char computerChoice1; // (character) the first color chosen by the computer. 
  char computerChoice2; // (character) the second color chosen by the computer.
  char computerChoice3; // (character) the third color chosen by the computer.
  char computerChoice4; // (character) the fourth color chosen by the computer.
  string userChoice; // (text) the text the user will input with their choices of colors
  char userChoice1; //(character) the the first color chosen by the user. 
  char userChoice2; //(character) the the second color chosen by the user. 
  char userChoice3; //(character) the the third color chosen by the user. 
  char userChoice4; // (character)the the fourth color chosen by the user. 
  int n_correctColors; //(integer) the number of correct colors userChoice matches with computerChoice.
  int n_correctPositions;  //(integer) the total number of correct positions userChoice matches with 
  char playAgain; //(character) can be either Y or N, determines whether the user wants to play again or exit the program
  int i; //(integer) counts the number of attemps the user uses.

  //user introduction
  introduction(objective);

  //read "mastermindScore.txt" and output best score
  f_bestScore();
  
  while (true) //main loop for each play
  {
    //create 4 random characters to store computer choice
    srand(time(0)); //seed the ramdom number generator, it has to be here NOT inside the function...
    computerChoice1 = f_randomChar();
    computerChoice2 = f_randomChar();
    computerChoice3 = f_randomChar();
    computerChoice4 = f_randomChar();

    for(i = 1; i <= 10; i++) //10 times loop for each guess
    {
      cout <<endl << "Guess #" << i << ":" << endl;
      //user input of userChoice and stract characters from userChoice
      while (true)
      {
        cout << "Input your choice [e.g. YRGB]: ";
        getline(cin,userChoice);
        userChoice1 = userChoice[0];
        userChoice2 = userChoice[1];
        userChoice3 = userChoice[2];
        userChoice4 = userChoice[3];
        if ((userChoice1 != 'R' && userChoice1 != 'G' && userChoice1 != 'B' && userChoice1 != 'Y') || (userChoice2 != 'R' && userChoice2 != 'G' && userChoice2 != 'B' && userChoice2 != 'Y') || (userChoice3 != 'R' && userChoice3 != 'G' && userChoice3 != 'B' && userChoice3 != 'Y') || (userChoice4 != 'R' && userChoice4 != 'G' && userChoice4 != 'B' && userChoice4 != 'Y'))
        {
          cout << "Invalid input, please try again..." << endl;
          continue;
        }
        break;
      }
   
      //calculate the number of correct colors.
      n_correctColors = f_correctColors(computerChoice1,computerChoice2,computerChoice3, computerChoice4,userChoice1,userChoice2,userChoice3,userChoice4);
  
      //calculate the number of correct positions.
      n_correctPositions = f_correctPositions(computerChoice1,computerChoice2,computerChoice3, computerChoice4,userChoice1,userChoice2,userChoice3,userChoice4);

      //output feedback
      cout << "You got " << n_correctColors << " correct colors and " << n_correctPositions << " correct positions." << endl << endl;
      if (n_correctPositions == 4) 
       {
        cout << "Congratulations! You win!" << endl;
        break;
       }
    } //10 times loop for each guess

    //show correct answer and chance to play Again
    cout << "The correct combination is: " << computerChoice1 << computerChoice2 << computerChoice3 << computerChoice4 << endl;

    //show and save user's score
    cout << "Your score is: " << i << " out of 10 attemps." << endl;
    f_appendScore(i);

    cout << "What to play again? [Y:Yes, N:No]: ";
    cin >> playAgain;
    cin.ignore(1000,10);
    if (toupper(playAgain) == 'Y') continue;
    else if (toupper(playAgain) == 'N') break;

  }//main loop for each play
  cout << endl << "Thank you for playing!" << endl;
}//main


//introduction function
void introduction(string obj)//user introduction
{
  //data
  //obj is the program objective

  //introduction
  cout << endl << "*************WELCOME TO MASTERMIND GAME*************" << endl;
  cout << obj; 
  cout << "Programmer: Luis Cermeno-Farro\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Xcode\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  cout << "HOW TO PLAY:" << endl;
  cout << "The computer will randomly choose a combination of 4 colors." << endl; 
  cout << "R: Red, G: Green, B: Blue, Y: Yellow" << endl; 
  cout << "You will have 10 guesses to nail the correct combination." << endl;
  cout << "Good luck and have fun :)" << endl;

}//end of introduction function


//function to read "mastermindScore.txt" and output best score.
void f_bestScore()
{
  //data
  ifstream fin; //creates object to input from file
  fin.open("mastermindScore.txt");
  int a; // (integer) temporary storage variable
  int b; // (integer) temporary storage variable
  int c; // (integer) temporary storage variable
  int min = 12; // (integer) storage variable for min score

  //read file
  if (!(fin.good())) throw "I/O error";
  while (fin.good())
  {
    fin >> a;
    fin.ignore(1000,10); //ignores enter key and go to next line
    fin >> b;
    fin.ignore(1000,10); //ignores enter key and go to next line 
    if (a < b) c = a;
    else c = b; 
    if (c < min) min = c;
  }
  if (min == 0) cout << "No scores registered yet. You will be the first one!" <<endl;
  else cout << "The best score to date is " << min << " out of 10 attemps. Let'see if you beat that score!" << endl;
  fin.close();
  fin.clear();
}// end function to read "mastermindScore.txt" and output best score.


//function to append userScore in the text file "mastermindScore.txt"
void f_appendScore(int userScore)
{
  ofstream fout;//creates object to input into file
  fout.open("mastermindScore.txt", ios::app);
  fout << userScore << endl;
  fout.close();
  fout.clear();
}//end of function to append userScore in the text file "mastermindScore.txt"


//function to generate random character
char f_randomChar() 
{
  char randomChar;
  int randomNumber = rand() % 4; // (integer) a ramdom number from 0 to 4 generated by the computer 
  switch (randomNumber)
  {
    case 0:
      randomChar = 'R';
      break;
    case 1:
      randomChar = 'G';
      break;
    case 2:
      randomChar = 'B';
      break;
    case 3:
      randomChar = 'Y';
      break;
  } 
  return randomChar;
}//end of function to generate random character


//function to evaluate how many correct colors the user got correct
int f_correctColors(char c1,char c2,char c3,char c4,char u1,char u2,char u3,char u4)
{
  //data
  int n_computerRed = 0;// the number of red computerChoice has
  int n_computerGreen = 0;// the number of green computerChoice has
  int n_computerBlue = 0;// the number of blue computerChoice has
  int n_computerYellow = 0;// the number of yellow computerChoice has
  int n_userRed = 0; // the number of red userChoice has
  int n_userGreen = 0;// the number of green userChoice has
  int n_userBlue = 0;// the number of blue userChoice has
  int n_userYellow = 0;// the number of yellow userChoice has
  int n_correctColors = 0;
  //extracting the number of each color user's and computer's combinations have
  switch (c1)
  {
    case 'R':
      n_computerRed++;
      break;
    case 'G':
      n_computerGreen++;
      break;
    case 'B':
      n_computerBlue++;
      break;
    case 'Y':
      n_computerYellow++;
      break; 
  }
  switch (c2)
  {
    case 'R':
      n_computerRed++;
      break;
    case 'G':
      n_computerGreen++;
      break;
    case 'B':
      n_computerBlue++;
      break;
    case 'Y':
      n_computerYellow++;
      break; 
  }
  switch (c3)
  {
    case 'R':
      n_computerRed++;
      break;
    case 'G':
      n_computerGreen++;
      break;
    case 'B':
      n_computerBlue++;
      break;
    case 'Y':
      n_computerYellow++;
      break; 
  }
  switch (c4)
  {
    case 'R':
      n_computerRed++;
      break;
    case 'G':
      n_computerGreen++;
      break;
    case 'B':
      n_computerBlue++;
      break;
    case 'Y':
      n_computerYellow++;
      break; 
  }
  switch (u1)
  {
    case 'R':
      n_userRed++;
      break;
    case 'G':
      n_userGreen++;
      break;
    case 'B':
      n_userBlue++;
      break;
    case 'Y':
      n_userYellow++;
      break; 
  }
  switch (u2)
  {
    case 'R':
      n_userRed++;
      break;
    case 'G':
      n_userGreen++;
      break;
    case 'B':
      n_userBlue++;
      break;
    case 'Y':
      n_userYellow++;
      break; 
  }
  switch (u3)
  {
    case 'R':
      n_userRed++;
      break;
    case 'G':
      n_userGreen++;
      break;
    case 'B':
      n_userBlue++;
      break;
    case 'Y':
      n_userYellow++;
      break; 
  }
  switch (u4)
  {
    case 'R':
      n_userRed++;
      break;
    case 'G':
      n_userGreen++;
      break;
    case 'B':
      n_userBlue++;
      break;
    case 'Y':
      n_userYellow++;
      break; 
  }
  //comparing number of colors betwenn computerchoice and userchoice
  if (n_userRed < n_computerRed) n_correctColors = n_correctColors + n_userRed;
  else n_correctColors = n_correctColors + n_computerRed;
  if (n_userGreen < n_computerGreen) n_correctColors = n_correctColors + n_userGreen;
  else n_correctColors = n_correctColors + n_computerGreen;
  if (n_userBlue < n_computerBlue) n_correctColors = n_correctColors + n_userBlue;
  else n_correctColors = n_correctColors + n_computerBlue;
  if (n_userYellow < n_computerYellow) n_correctColors = n_correctColors + n_userYellow;
  else n_correctColors = n_correctColors + n_computerYellow;
  return n_correctColors;
}//end of function to evaluate how many correct colors the user got correct


//function to evaluate how many correct positions the user got correct
int f_correctPositions(char c1,char c2,char c3,char c4,char u1,char u2,char u3,char u4)
{
  int n_positions = 0;
  if (u1 == c1) n_positions++;
  if (u2 == c2) n_positions++;
  if (u3 == c3) n_positions++;
  if (u4 == c4) n_positions++;
  return n_positions;
}//end of function to evaluate how many correct positions the user got correct
