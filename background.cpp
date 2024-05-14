#include "headers/background.h"
#include "headers/mark.h"
#include <iostream>
#include <string>
using namespace std;

/* HOW TO USE:

  displayTop();

  [any/all string output] 

  displayBottom (# of newlines ("\n") used by output);
  
*/

/* Note: There is a way of reading newline escape codes using
   string member functons .start() and .end(), however, that
   wouldve taken much more refactoring. It is possible though.
*/

// Arcade screen SIZE: 66x18

//ANSI codes
const string BLUE = "\x1b[38;5;20m";
const string YELLOW = "\x1b[38;5;220m";
const string RED = "\x1b[38;5;160m";
const string DEFAULT = "\x1b[0m";

// Colors
const string border = BLUE;
const string letters = YELLOW;
const string number =  RED;
const string reset = DEFAULT;

void displayTop(){

  clrscr();

  // Display Top of Arcade machine 

  cout << border << "██████████████████████████████████████████████████████████████████████████████████\n"
    "█▌                                                                              ▐█\n"
    "█▌"<< letters <<"   ██████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗ ██████╗████████╗"<< number <<"    ██╗  ██╗"<< border <<"  ▐█\n"
    "█▌"<< letters <<"  ██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██╔════╝╚══██╔══╝"<< number <<"    ██║  ██║"<< border <<"  ▐█\n"
    "█▌"<< letters <<"  ██║     ██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║        ██║   "<< number <<"    ███████║"<< border <<"  ▐█\n"
    "█▌"<< letters <<"  ██║     ██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║        ██║   "<< number <<"    ╚════██║"<< border <<"  ▐█\n"
    "█▌"<< letters <<"  ╚██████╗╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╗   ██║   "<< number <<"         ██║"<< border <<"  ▐█\n"
    "█▌"<< letters <<"   ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═╝   "<< number <<"         ╚═╝"<< border <<"  ▐█\n"
    "█▌                                                                              ▐█\n"
    "██████████████████████████████████████████████████████████████████████████████████\n"
    "▜████████████████████████████████████████████████████████████████████████████████▛\n"
    " ▜██████████████████████████████████████████████████████████████████████████████▛ \n"
    "  ▜▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▛  \n"
    "   ▜▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▛   \n"
    "    ▜▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▛    \n"
    "     ▜▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▛     \n"
    "      ▜░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▛      \n"
    "       ▜░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▛       \n" << endl << reset;

}
  
void displayBottom(int newLineCount){

/* Using newLineCount, check how many lines are 
   left to complete the 18 lines of the screen */

  saveCursor(); // Saves Cursor position for inputs

  for (int i = 0; i < 18 - newLineCount; i++) {
    cout << "\n";
  }

// Display bottom of arcade machine

cout << endl << border <<
  "       ▟░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▙       \n"
  "      ▟░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▙      \n"
  "     ▟▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▙     \n"
  "    ▟▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▙    \n"
  "   ▟▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▙   \n"
  "  ▟▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▙  \n"
  " ▟██████████████████████████████████████████████████████████████████████████████▙ \n"
  "▟████████████████████████████████████████████████████████████████████████████████▙\n"
  "██████████████████████████████████████████████████████████████████████████████████\n"
  "█▌VERSION: 1.0                                                    Gladymar Colon▐█\n"
  "█▌SERIAL: CCOM3033-001                                             Uriel Fuentes▐█\n"
  "█▌                                                                Jose Rodriguez▐█\n"
  "█▌                                                                              ▐█\n"
  "█▌                                                                              ▐█\n"
  "█▌                                                                              ▐█\n" << reset;

  returnCursor(); 
}