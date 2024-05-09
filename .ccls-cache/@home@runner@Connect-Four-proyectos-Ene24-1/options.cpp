#include <iostream>
#include <fstream>
#include <iomanip>
#include "headers/options.h"
#include "headers/mark.h"
using namespace std;

int OPTIONS_MENU(mark &P1, mark &P2){

  // Used for Resetting player scores
  string answer;
  const bool answer_Yes = answer == "Y" || answer == "y";
  const bool answer_No  = answer == "N" || answer == "n";

  do{
    
    displayTop();
    if (P1.mark == P2.mark)
      (warning("Marks are identical!\n\n"));

    char option;
    cout << right << setw(55) <<"\x1b[1mOptions\x1b[22m\n\n";

    int dist = 33;

    cout << right <<setw(dist) << "\t1. Change Colors\n"
         <<setw(dist) <<  "\t2. Change Characters\n"
          <<setw(dist) << "\t3. Reset player Scores\n"
         <<setw(dist) << "\t4. Return to MAIN MENU\n";

    cout << setw(47) << endl << "Selection: ";
    displayBottom(10); //lo cambie a 10 estaba en 8
    
    cin >> option;

    switch(option){
      case 49: clrscr(); COLORS_MENU(P1, P2); break;

      case 50: clrscr(); CHARS_MENU(P1, P2); break;

      case 51:
        
        clrscr();
        
        do{
          displayTop();
          cout << right << setw(52) <<"Reset Player Scores\n";
          cout << setw(67) << endl;
          warning("Are you sure you want to delete ALL scores? (Y/n): ");
          displayBottom(1);
          
          cin >> answer;
  
          if (answer == "Y" || answer == "y"){
            // Open files, delete in process, close
            ofstream delete1("records/P1points.txt"); 
            delete1.close();
            
            ofstream delete2("records/P2points.txt"); 
            delete2.close();
          }
  
        }
        while (answer_Yes && answer_No); // input validation

      break;

      case 52: 

        if (P1.mark == P2.mark){
          
          displayTop();
          error("Marks cannot be identical. Please make a change.\n\n");
          cout << "(Press ENTER to return to OPTIONS menu)";
          displayBottom(3);
          
          cin.ignore(); cin.get();
        }
        else
          return 0; 

      break;
    }
  }
  while(1);
}



void COLORS_MENU(mark &P1, mark &P2){

  // List of available colors in with ANSI codes
  //cambiar colores a variables const
  string colorMenu = 
     "Available colors:\n"
     "\t1.\u001b[31m Red\u001b[0m\n"
     "\t2.\u001b[32m Green\u001b[0m\n"
     "\t3.\u001b[33m Yellow\u001b[0m\n"
     "\t4.\u001b[34m Blue\u001b[0m\n"
     "\t5.\u001b[35m Magenta\u001b[0m\n"
     "\t6.\u001b[36m Cyan\u001b[0m\n"
     "\t7. White (Default)\n"
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

  char option;
  /////// PLAYER 1 SELECTION ///////
  do
  { 
    displayTop();
    cout << colorMenu;
    cout << "Player 1 Selection: "; 
    displayBottom(10);
    
    cin >> option;
    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Plug in input into ANSI Code, adding such to P1_color
  P1.color = "\u001b[3" + to_string(option - 48) + "m";
  P1.mark = P1.color + P1.character;

  /////// PLAYER 2 SELECTION ///////
  do
  { 
    displayTop();
    cout << colorMenu;
    cout << "Player 1 Selection: [" << P1.mark << "]\n";
    cout << "Player 2 Selection: "; 
    displayBottom(10);
    
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
// FALTA setw
  string iconMenu = 
     "Available Icons:\n\n"
     "\t1. ★\n"
     "\t2. ❆\n"
     "\t3. ✦\n"
     "\t4. ♡\n"
     "\t5. ♫\n"
     "\t6. ☽\n"
     "\t7. ✿\n"
     "\t8. A-Z Characters [Not Coded]\n"
     "\t9. Paste your own [Not Coded]\n"
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

  char option;
  /////// PLAYER 1 SELECTION ///////
  do
  {
    displayTop();
    cout << iconMenu;
    cout << "Player 1 Selection: "; 
    displayBottom(12);
    
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

  /////// PLAYER 2 SELECTION ///////
  do
  {
    displayTop();
    cout << iconMenu;
    cout << "Player 1 Selection: [" << P1.mark << "]\n";
    cout << "Player 2 Selection: ";
    displayBottom(12);
    
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
