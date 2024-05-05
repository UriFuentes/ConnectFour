#include "headers/background.h"
#include "headers/mark.h"
#include <iostream>
#include <string>
using namespace std;

void displayArcade(string content){

  cout << "\x1b[H"; // Returns Cursor to beginning of terminal screen

  // Colors
  string border = "\x1b[38;5;20m"; // Set to blue
  string letters = "\x1b[38;5;220m"; // Set to orange
  string number = "\x1b[38;5;160m";
  string reset = "\x1b[0m";
  
  // Screen SIZE: 66x18

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
  

  // Display Main menu (5 lines)
    cout << endl << content;
    saveCursor();

  // Display remaining space below original menu (13 lines)
    for (int i = 0; i < 13; ++i) {
      cout << "\n";
    }

  // Display bottom of arcade machine

  cout << border <<
    "       ▟░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▙       \n"
    "      ▟░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▙      \n"
    "     ▟▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▙     \n"
    "    ▟▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▙    \n"
    "   ▟▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▙   \n"
    "  ▟▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▙  \n"
    " ▟██████████████████████████████████████████████████████████████████████████████▙ \n"
    "▟████████████████████████████████████████████████████████████████████████████████▙\n"
    "██████████████████████████████████████████████████████████████████████████████████\n"
    "█▌                                                                Gladymar Colon▐█\n"
    "█▌                                                                 Uriel Fuentes▐█\n"
    "█▌                                                                Jose Rodriguez▐█\n"
    "█▌                                                                              ▐█\n"
    "█▌                                                                              ▐█\n"
    "█▌                                                                              ▐█\n" << reset;

  returnCursor();
  
}