#include <iostream>
#include <fstream>
#include <iomanip>
#include "headers/options.h"
#include "headers/mark.h"
using namespace std;

//Ansi codes
const string RED = "\u001b[31m";
const string GREEN = "\u001b[32m";
const string YELLOW = "\u001b[33m";
const string BLUE = "\u001b[34m";
const string MAGENTA = "\u001b[35m";
const string CYAN = "\u001b[36m";
const string DEFAULT = "\u001b[0m";
const string BOLD = "\x1b[1m";
const string COLOR_PLUGIN = "\u001b[3";
const string ANSI_END = "m";


int OPTIONS_MENU(mark &P1, mark &P2){

  // Used for Resetting player scores
  string answer;
  const bool answer_Yes = answer == "Y" || answer == "y";
  const bool answer_No  = answer == "N" || answer == "n";

  do{
    
    displayTop();
    if (P1.mark == P2.mark){
      (warning("Marks are identical!\n\n"));
    }

    char option;
    cout << right << setw(43) << BOLD << "Options" <<  DEFAULT << "\n\n";

    int dist = 55;

    cout << right <<setw(dist -6) << "\t1. Change Colors\n"
         <<setw(dist- 4) <<  "\t2. Change Characters\n"
         <<setw(dist) <<  "\t3. Reset player Scores\n"
         <<setw(dist) <<  "\t4. Return to MAIN MENU\n";

    cout << setw(47) << endl << "Selection: ";
    displayBottom(12); 
    
    cin >> option;

    switch(option){
      case 49: clrscr(); COLORS_MENU(P1, P2); break;

      case 50: clrscr(); CHARS_MENU(P1, P2); break;

      case 51: 
        
        clrscr();
        
        do{
          displayTop();
          cout << right << setw(52) <<"Reset Player Scores\n\n";
          cout << setw(77) << RED + "Are you sure you want to delete ALL scores?" + DEFAULT + " (Y/n): ";
          displayBottom(5);
          
          cin >> answer;
  
          if (answer == "Y" || answer == "y"){
            // Open files, write 0, close
            ofstream deleteP1("records/P1points.txt");
            deleteP1 << 0;
            deleteP1.close();
            
            ofstream deleteP2("records/P2points.txt");
            deleteP2 << 0;
            deleteP2.close();
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
  
  char option;
  /////// PLAYER 1 SELECTION ///////
  do
  { 
    displayTop();
    cout << right << setw(31) << "" <<  "Available colors:\n\n" ;
    cout << setw(50) << "\t1. " + RED + "Red" + DEFAULT + "\n"
         << setw(54) << "\t2. " + GREEN + "Green" + DEFAULT + "\n"
         << setw(54) << "\t3. " + YELLOW + "Yellow" + DEFAULT + "\n"
         << setw(50) << "\t4. " + BLUE + "Blue" + DEFAULT + "\n"
         << setw(54) << "\t5. " + MAGENTA + "Magenta" + DEFAULT + "\n"
         << setw(50) << "\t6. " + CYAN + "Cyan" + DEFAULT + "\n"
         << setw(55) << "\t7. White (Default)\n\n"
         << setw(63) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    
    cout << setw(51) << "Player 1 Selection: "; 
    displayBottom(10);
    
    cin >> option;
    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Plug in input into ANSI Code, adding such to P1_color
  P1.color = COLOR_PLUGIN + to_string(option - 48) + ANSI_END;
  P1.mark = P1.color + P1.character;

  /////// PLAYER 2 SELECTION ///////
  do
  { 
    displayTop();
    cout << setw(31) << "" <<  "Available colors:\n\n" ;
    cout << setw(50) << "\t1. " + RED + "Red" + DEFAULT + "\n"
         << setw(54) << "\t2. " + GREEN + "Green" + DEFAULT + "\n"
         << setw(54) << "\t3. " + YELLOW + "Yellow" + DEFAULT + "\n"
         << setw(50) << "\t4. " + BLUE + "Blue" + DEFAULT + "\n"
         << setw(54) << "\t5. " + MAGENTA + "Magenta" + DEFAULT + "\n"
         << setw(50) << "\t6. " + CYAN + "Cyan" + DEFAULT + "\n"
         << setw(55) << "\t7. White (Default)\n\n"
         << setw(63) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    cout << setw(51) << "Player 2 Selection: "; 
    displayBottom(10);
    
    cin >> option;
    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Plug in input into ANSI Code, adding such to P2_color
  P2.color = COLOR_PLUGIN + to_string(option - 48) + ANSI_END;
  P2.mark = P2.color + P2.character;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << setw(51) << "Player 1 Selection: [" << P1.mark << "]\n";
  cout << setw(51) << "Player 2 Selection: [" << P2.mark << "]";

  // Stop Gap
  cout << setw(62) << endl << endl<< "(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get(); 
}



void CHARS_MENU(mark &P1, mark &P2){
   
  char option;
  /////// PLAYER 1 SELECTION ///////
  do
  {
    displayTop();
    cout << right << setw(50) <<"Available Icons:\n\n";
     cout << setw(41) << "\t1. ★\n";
     cout << setw(41) << "\t2. ❆\n";
     cout << setw(41) << "\t3. ✦\n";
     cout << setw(41) <<  "\t4. ♡\n";
     cout << setw(41) << "\t5. ♫\n";
     cout << setw(41) << "\t6. ☽\n";
     cout << setw(42) << "\t7. ✿\n\n";
     cout << setw(63) <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << setw(51) << "Player 1 Selection: "; 
    displayBottom(12);
    
    cin >> option;
    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Switch for Predefined icons
  switch(option){
    case 49: P1.character = "★" + DEFAULT; break;
    case 50: P1.character = "❆" + DEFAULT; break;
    case 51: P1.character = "✦" + DEFAULT; break;
    case 52: P1.character = "♡" + DEFAULT; break;
    case 53: P1.character = "♫" + DEFAULT; break;
    case 54: P1.character = "☽" + DEFAULT; break;
    case 55: P1.character = "✿" + DEFAULT; break; 
  }

  P1.mark = P1.color + P1.character;

  /////// PLAYER 2 SELECTION ///////
  do
  {
    displayTop();
    cout << right << setw(50) <<"Available Icons:\n\n";
     cout << setw(41) << "\t1. ★\n";
     cout << setw(41) << "\t2. ❆\n";
     cout << setw(41) << "\t3. ✦\n";
     cout << setw(41) <<  "\t4. ♡\n";
     cout << setw(41) << "\t5. ♫\n";
     cout << setw(41) << "\t6. ☽\n";
     cout << setw(42) << "\t7. ✿\n\n";
     cout << setw(62) <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << setw(51) << "Player 1 Selection: [" << P1.mark << "]\n";
    cout << setw(51) << "Player 2 Selection: ";
    displayBottom(12);
    
    cin >> option;
    if(option > 55 || option < 49)
      clrln();
  }
  while(option > 55 || option < 49);

  // Switch for Predefined icons
  switch(option){
    case 49: P2.character = "★" + DEFAULT; break;
    case 50: P2.character = "❆" + DEFAULT; break;
    case 51: P2.character = "✦" + DEFAULT; break;
    case 52: P2.character = "♡" + DEFAULT; break;
    case 53: P2.character = "♫" + DEFAULT; break;
    case 54: P2.character = "☽" + DEFAULT; break;
    case 55: P2.character = "✿" + DEFAULT; break;
  }

  P2.mark = P2.color + P2.character;

  // Deletes line and writes mark
  clrln(); 
  cout << setw(51) << "Player 2 Selection: [" << P2.mark << "]";

  // Stop Gap
  cout << setw(62) << endl << endl << "(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get();
}
