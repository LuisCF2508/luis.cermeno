//Objective:  simulate a digital clock
//Name: Teacher
//Course: COMSC-110-8215
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
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
  int decimal = 0; // (integer) decimal digit in digital odometer.
  int first_dig = 0; // (integer) first digit in digital odometer.
  int second_dig = 0; // (integer) second digit in digital odometer.
  int third_dig = 0; // (integer) third digit in digital odometer.
  int fourth_dig = 0; // (integer) fourth digit in digital odometer.
  int fifth_dig = 0; // (integer) fifth digit in digital odometer.
  int sixth_dig = 0; // (integer) sixth digit in digital odometer.

  // output my name and objective and program information
  cout << "Objective: This program will simulate a digital odometer.\n"; 
  cout << "Programmer: Luis Cermeno\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << endl << endl << "CTRL-C to exit...\n"; 

  //output digital odometer.

  for (sixth_dig = 0; sixth_dig < 9; sixth_dig++) 
  {
    for (fifth_dig = 0; fifth_dig < 9; fifth_dig++) 
    {
      for (fourth_dig = 0; fourth_dig < 9; fourth_dig++) 
      {
        for (third_dig = 0; third_dig < 9; third_dig++) 
        { 
          for (second_dig = 0; second_dig < 9; second_dig++) 
          { 
            for (first_dig = 0; first_dig < 9; first_dig++) 
            { 
              for (decimal = 0; decimal < 9; decimal++) 
              { 
                cout << "Mileage: ";
                cout << sixth_dig; 
                cout << fifth_dig;
                cout << fourth_dig; 
                cout << third_dig;
                cout << second_dig; 
                cout << first_dig;
                cout << "." << decimal; 
                cout.flush();  //clears the output buffer

                //pause for one tenth of a second 
                #ifdef _WIN32 
                Sleep(100); // hundred milliseconds
                #else 
                sleep(0.1); // 1 tenth of a second 
                #endif 

                //return to begining of current line  
                cout << '\r'; // CR 
              } //for decimal
            } // for first digit
          } //for second digit
        }//for third digit
      }//for fouth digit
    }//for fifth digit
  }//for sixth digit

}//main