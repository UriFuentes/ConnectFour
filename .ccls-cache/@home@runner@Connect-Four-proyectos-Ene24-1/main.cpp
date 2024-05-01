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

  short option;
  do
  {
    clrscr();

    // Output Game Title in BOLD
    cout << "\x1b[1m░▒▓█ C O N N E C T  4 █▓▒░\x1b[22m\n\n";

    cout << "\t1. Play ♟︎\n"
         << "\t2. Practice\n"
         << "\t3. Options ⚒︎\n"
         << "\t4. Exit\n";

    cout << "\nSelection: ";
    cin >> option;

    // input validation
    if (option < 1 || option > 4)
      cout << "ERROR, please enter number 1-4\n";

    switch(option){

      // NOT Practice game
      case 1: clrscr(); RUN_GAME(false, P1, P2); break;
      // Practice game
      case 2: clrscr(); RUN_GAME(true, P1, P2); break; 

      case 3: clrscr(); OPTIONS_MENU(P1, P2); break;

      case 4: return 0; break;
    } 
  }
  while(1);


}

