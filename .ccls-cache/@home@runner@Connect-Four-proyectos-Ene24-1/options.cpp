#include <iostream>
#include <string>
#include <vector>
#include "options.h"
#include "global.h"
using namespace std;


int OPTIONS_MENU(){

  //Used to save color to add in CHAR_MENU
  string P1_color, P2_color;

  do{
    clrscr();

    int option;
    cout << "\x1b[1mCustomization Options\x1b[22m\n\n";

    cout << "\t1. Colors\n"
         << "\t2. Character\n"
         << "\t3. Return to MAIN MENU\n";

    cout << "\nSelection: ";
    cin >> option;

    // input validation
    if (option < 1 || option > 3)
      cout << "ERROR, please enter number 1-3\n";

    switch(option){
      case 1: clrscr(); COLORS_MENU(); break;

      case 2: clrscr(); CHARS_MENU(); break;

      case 3: clrscr(); return 0; break;
    }
  }
  while(1);

}




void COLORS_MENU(){

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

  int option;

  /////// PLAYER 1 SELECTION ///////
  do
  { 
    cout << "Player 1 Selection: "; 
    cin >> option;

    if(option > 7 || option < 1)
      clrln();
  }
  while(option > 7 || option < 1);

  // Plug in input into ANSI Code, adding such to P1_color
  P1.color = "\u001b[3" + to_string(option) + "m";
  P1_mark = P1.color + P1.character;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 1 Selection: [" << P1_mark << "]\n";

  /////// PLAYER 2 SELECTION ///////
  do
  { 
    cout << "Player 2 Selection: "; 
    cin >> option;

    if(option > 7 || option < 1)
      clrln();
  }
  while(option > 7 || option < 1);

  // Plug in input into ANSI Code, adding such to P2_color
  P2.color = "\u001b[3" + to_string(option) + "m";
  P2_mark = P2.color + P2.character;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 2 Selection: [" << P2_mark << "]";

  // Stop Gap
  cout << "\n\n(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get(); 
}



void CHARS_MENU(){

  cout << "Available Icons:\n\n";

  cout << "\t1. ★\n"
     << "\t2. ❆\n"
     << "\t3. ✦\n"
     << "\t4. ♡\n"
     << "\t5. ♫\n"
     << "\t6. ☽\n"
     << "\t7. ☢\n"
     << "\t8. ✿\n"
     << "\t9. A-Z Characters [Not Coded]\n"
     << "\t10. Paste your own [Not Coded]\n"
     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

  int option;
  /////// PLAYER 1 SELECTION ///////
  do
  {
    cout << "Player 1 Selection: "; 
    cin >> option;

    if(option > 10 || option < 1)
      clrln();
  }
  while(option > 10 || option < 1);

  // Switch for Predefined icons
  switch(option){
    case 1: P1.character = "★\u001b[0m"; break;
    case 2: P1.character = "❆\u001b[0m"; break;
    case 3: P1.character = "✦\u001b[0m"; break;
    case 4: P1.character = "♡\u001b[0m"; break;
    case 5: P1.character = "♫\u001b[0m"; break;
    case 6: P1.character = "☽\u001b[0m"; break;
    case 7: P1.character = "☢\u001b[0m"; break;
    case 8: P1.character = "✿\u001b[0m"; break;
  }

  P1_mark = P1.color + P1.character;

  // Deletes line and writes mark
  clrln(); 
  cout << "Player 1 Selection: [" << P1_mark << "]\n";

  /////// PLAYER 2 SELECTION ///////
  do
  {

    cout << "Player 2 Selection: "; 
    cin >> option;

    if(option > 10 || option < 1)
      clrln();
  }
  while(option > 10 || option < 1);

  // Switch for Predefined icons
  switch(option){
    case 1: P2.character = "★\u001b[0m"; break;
    case 2: P2.character = "❆\u001b[0m"; break;
    case 3: P2.character = "✦\u001b[0m"; break;
    case 4: P2.character = "♡\u001b[0m"; break;
    case 5: P2.character = "♫\u001b[0m"; break;
    case 6: P2.character = "☽\u001b[0m"; break;
    case 7: P2.character = "☢\u001b[0m"; break;
    case 8: P2.character = "✿\u001b[0m"; break;
  }

  P2_mark = P2.color + P2.character;

  // Deletes line and writes mark
  clrln(); 
  cout << "Player 2 Selection: [" << P2_mark << "]";

  // Stop Gap
  cout << "\n\n(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get();
}


