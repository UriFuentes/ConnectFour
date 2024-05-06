#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "headers/mark.h"
#include "headers/game.h"
#include "headers/options.h"
#include "headers/background.h"
#include "headers/4InARowScan.h"
using namespace std;

int main(){
  
  //Default Variables for player marks
  mark P1 = {"\u001b[31m", "O\x1b[0m"}; // RED "O"
  mark P2 = {"\u001b[33m", "O\x1b[0m"}; // YELLOW "O"

  char option;
  
  do
  {

    displayTop();
    cout << right << setw(42) << "1. Play ♟︎\n"
         << setw(57) << "2. Practice [NOT IMPLEMENTED]\n"
         << setw(45) << "3. Options ⚒︎\n"
         << setw(35) << "4. Exit\n";

    cout << setw(38) << "Selection: ";
    displayBottom(10); // lo cambie a 10 a ver como se veia. estaba en 5
    

    cin >> option;

    switch(option){ // Cases are in decimal value

      // NOT Practice game
      case 49: RUN_GAME(false, P1, P2); break;
      // Practice game
      case 50: RUN_GAME(true, P1, P2); break; 

      case 51: OPTIONS_MENU(P1, P2); break;

      case 52: return 0; break;
    } 
  }
  while(1);
}


