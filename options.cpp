#include <iostream>
#include "headers/options.h"
#include "headers/mark.h"
using namespace std;

int OPTIONS_MENU(mark &P1, mark &P2){

  do{
    clrscr();

    if (P1.mark == P2.mark)
      warning("Marks are identical!\n\n");

    char option;
    cout << "\x1b[1mCustomization Options\x1b[22m\n\n";

    cout << "\t1. Colors\n"
         << "\t2. Character\n"
         << "\t3. Return to MAIN MENU\n";

    cout << "\nSelection: ";
    cin >> option;

    switch(option){
      case 49: clrscr(); COLORS_MENU(P1, P2); break;

      case 50: clrscr(); CHARS_MENU(P1, P2); break;

      case 51: 
        clrscr(); 

        if (P1.mark == P2.mark){
          error("Marks cannot be identical. Please make a change.\n\n");
          cout << "(Press ENTER to return to OPTIONS menu)";
          cin.ignore(); cin.get();
        }
        else
          return  0; 

        break;
    }
  }
  while(1);
}



void COLORS_MENU(mark &P1, mark &P2){

  // Display List of available colors in with ANSI codes

  cout << "Available colors:\n"
       << "\t1.\u001b[31m Red\u001b[0m\n"
       << "\t2.\u001b[32m Green\u001b[0m\n"
       << "\t3.\u001b[33m Yellow\u001b[0m\n"
       << "\t4.\u001b[34m Blue\u001b[0m\n"
       << "\t5.\u001b[35m Magenta\u001b[0m\n"
       << "\t6.\u001b[36m Cyan\u001b[0m\n"
       << "\t7. White (Default)\n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

  char option;
  /////// PLAYER 1 SELECTION ///////
  do
  { 
    cout << "Player 1 Selection: "; 
    cin >> option;

    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Plug in input into ANSI Code, adding such to P1_color
  P1.color = "\u001b[3" + to_string(option - 48) + "m";
  P1.mark = P1.color + P1.character;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 1 Selection: [" << P1.mark << "]\n";

  /////// PLAYER 2 SELECTION ///////
  do
  { 
    cout << "Player 2 Selection: "; 
    cin >> option;

    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Plug in input into ANSI Code, adding such to P2_color
  P2.color = "\u001b[3" + to_string(option - 48) + "m";
  P2.mark = P2.color + P2.character;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 2 Selection: [" << P2.mark << "]";

  // Stop Gap
  cout << "\n\n(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get(); 
}



void CHARS_MENU(mark &P1, mark &P2){

  cout << "Available Icons:\n\n";

  cout << "\t1. ★\n"
       << "\t2. ❆\n"
       << "\t3. ✦\n"
       << "\t4. ♡\n"
       << "\t5. ♫\n"
       << "\t6. ☽\n"
       << "\t7. ✿\n"
       << "\t8. A-Z Characters [Not Coded]\n"
       << "\t9. Paste your own [Not Coded]\n"
       << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

  char option;
  /////// PLAYER 1 SELECTION ///////
  do
  {
    cout << "Player 1 Selection: "; 
    cin >> option;

    if(option > 57 || option < 49)
      clrln();
  }
  while(option > 57 || option < 49);

  // Switch for Predefined icons
  switch(option){
    case 49: P1.character = "★\u001b[0m"; break;
    case 50: P1.character = "❆\u001b[0m"; break;
    case 51: P1.character = "✦\u001b[0m"; break;
    case 52: P1.character = "♡\u001b[0m"; break;
    case 53: P1.character = "♫\u001b[0m"; break;
    case 54: P1.character = "☽\u001b[0m"; break;
    case 55: P1.character = "✿\u001b[0m"; break; 
  }

  P1.mark = P1.color + P1.character;

  // Deletes line and writes mark
  clrln(); 
  cout << "Player 1 Selection: [" << P1.mark << "]\n";

  /////// PLAYER 2 SELECTION ///////
  do
  {
    cout << "Player 2 Selection: "; 
    cin >> option;

    if(option > 57 || option < 49)
      clrln();
  }
  while(option > 57 || option < 49);

  // Switch for Predefined icons
  switch(option){
    case 49: P2.character = "★\u001b[0m"; break;
    case 50: P2.character = "❆\u001b[0m"; break;
    case 51: P2.character = "✦\u001b[0m"; break;
    case 52: P2.character = "♡\u001b[0m"; break;
    case 53: P2.character = "♫\u001b[0m"; break;
    case 54: P2.character = "☽\u001b[0m"; break;
    case 55: P2.character = "✿\u001b[0m"; break;
  }

  P2.mark = P2.color + P2.character;

  // Deletes line and writes mark
  clrln(); 
  cout << "Player 2 Selection: [" << P2.mark << "]";

  // Stop Gap
  cout << "\n\n(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get();
}
