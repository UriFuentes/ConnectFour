#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "headers/mark.h"
#include "headers/game.h"
#include "headers/options.h"
#include "headers/4InARowScan.h"
using namespace std;

int main(){
  
  //Default Variables for player marks
  mark P1 = {"\u001b[31m", "O\x1b[0m"}; // RED "O"
  mark P2 = {"\u001b[33m", "O\x1b[0m"}; // YELLOW "O"

  char option;
  do
  {
    clrscr();

    // Output Game Title in BOLD
    cout << " ██████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗ ██████╗████████╗    ██╗  ██╗" << endl <<
      "██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██╔════╝╚══██╔══╝    ██║  ██║" << endl <<
      "██║     ██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║        ██║       ███████║" << endl <<
      "██║     ██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║        ██║       ╚════██║" << endl <<
      "╚██████╗╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╗   ██║            ██║" << endl <<
      " ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═╝            ╚═╝" << endl ;

    cout << right << setw(35) << "1. Play ♟︎\n"
         << setw(50) << "2. Practice [NOT IMPLEMENTED]\n"
         << setw(38) << "3. Options ⚒︎\n"
         << setw(28) << "4. Exit\n";

    cout << setw(23) << endl << "Selection: ";
    cin >> option;

    switch(option){ // Cases are in decimal value

      // NOT Practice game
      case 49: clrscr(); RUN_GAME(false, P1, P2); break;
      // Practice game
      case 50: clrscr(); RUN_GAME(true, P1, P2); break; 

      case 51: clrscr(); OPTIONS_MENU(P1, P2); break;

      case 52: return 0; break;
    } 
  }
  while(1);
}

