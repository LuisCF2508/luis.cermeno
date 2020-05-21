//Objective:  simulate a digital clock
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip> //formatting
#include <iostream>  //console input and output
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
#ifdef _WIN32 
#include <windows.h> 
#else 
#include <unistd.h> 
#endif 

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data
  int hr = 0; //hours (2 digits width) in digital clock
  int min = 0; //minutes (2 digits width) in digital clock
  int sec = 0;// seconds (2 digits width) in digital clock

  // output my name and objective and program information
  cout << "Objective: This program will simulate a digital clock.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << endl << endl << "CTRL-C to exit...\n"; 

  //output digital clock
  cout.fill('0'); //format the initial digital clock to 00:00:00
  for (hr = 0; hr < 24; hr++) 
  { 
    for (min = 0; min < 60; min++) 
    { 
      for (sec = 0; sec < 60; sec++) 
      { 
        //output hours, minutes, seconds of digital clock
        cout << setw(2) << hr << ':'; 
        cout << setw(2) << min << ':'; 
        cout << setw(2) << sec << ' '; 
        cout.flush();  //clears the output buffer

        //pause for one second  
        #ifdef _WIN32 
        Sleep(1000); // one thousand milliseconds
        #else 
        sleep(1); // one second 
        #endif 

        //return to begining of current line  
        cout << '\r'; // CR 
      } //for seconds
    } // for minutes
  } //for hours
}//main