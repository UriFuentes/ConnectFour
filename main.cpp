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
  //Ansi color codes 
  const string RED = "\u001b[31m";
  const string YELLOW = "\u001b[33m";

  //Ansi code to display O
  const string ZERO = "O\x1b[0m";

  //Default Variables for player marks
  mark P1 = {RED, ZERO}; // RED "O"
  mark P2 = {YELLOW, ZERO}; // YELLOW "O"

  char option;

  // displays menu
  do
  {

    displayTop();
    int dist = 34; //variable to align, used in setw 
    cout << right << setw(dist) << "" << "1. Play ♟︎\n"
         << setw(dist)<< "" << "2. Practice\n"
         << setw(dist)<< "" << "3. Options ⚒︎\n"
         << setw(dist)<< "" << "4. Exit\n";

    cout << endl << setw(41) << "Selection: ";
    displayBottom(10);

    cin >> option;

    switch(option){ // Cases are in decimal value
      
      // NOT Practice game
      // Functions are located in game.cpp
      case 49: RUN_GAME(false, P1, P2); break;
      // Practice game
      case 50: RUN_GAME(true, P1, P2); break; 
      //Function is located in option.cpp
      case 51: OPTIONS_MENU(P1, P2); break;

      case 52: return 0; break;

    } 
  }
  while(true);
}


