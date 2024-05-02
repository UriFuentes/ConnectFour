#include <iostream>
#include <string>
#include <vector>
#include "mark.h"
#include "game.h"
#include "options.h"
#include "4InARowScan.h"
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
      " ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═╝            ╚═╝" << endl << endl;

    cout << "\t\t\t\t\t1. Play ♟︎\n"
         << "\t\t\t\t\t2. Practice\n"
         << "\t\t\t\t\t3. Options ⚒︎\n"
         << "\t\t\t\t\t4. Exit\n";

    cout << "\n\t\t\tSelection: ";
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

