#include <iostream>
#include <string>
#include <vector>
#include "mark.h"
// #include "sub.cpp"
using namespace std;

// Main Functions
void RUN_GAME(bool); // Game Function 
void OPTIONS_MENU(); // Game Options 

// Options Functions
void COLORS_MENU(); // Allows change in color 
void CHARS_MENU(); // Allows change in character 

// Board functions
void displayBoard (vector<vector<string>>, short, bool); // Displays game board
bool isFourInARow (vector<vector<string>>, short, string); // Checks for 4-in-a-row
void highlightMark (vector<vector<string>>, int, int); // Highlights 4-in-a-row marks
void deleteColumn (vector<vector<string>> &, short, int); // Deletes a col in game board
void deleteRow (vector<vector<string>> &, short, int); // Deletes a row in game board

//Default Variables for player marks
mark P1 = {"\u001b[31m", "O\x1b[0m"}; // RED "O"
mark P2 = {"\u001b[33m", "O\x1b[0m"}; // YELLOW "O"

int main(){

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
      case 1: clrscr(); RUN_GAME(false); break;
      // Practice game
      case 2: clrscr(); RUN_GAME(true); break; 

      case 3: clrscr(); OPTIONS_MENU(); break;

      case 4: return 0; break;
    } 
  }
  while(1);


}



void OPTIONS_MENU(){

  do{
    clrscr();
    
    if (P1.mark == P2.mark)
      warning("Marks are identical!\n\n");

    int option;
    cout << "\x1b[1mCustomization Options\x1b[22m\n\n";

    cout << "\t1. Colors\n"
         << "\t2. Character\n"
         << "\t3. Return to MAIN MENU\n";

    cout << "\nSelection: ";
    cin >> option;

    switch(option){
      case 1: clrscr(); COLORS_MENU(); break;
      
      case 2: clrscr(); CHARS_MENU(); break;
  
      case 3: 
        clrscr(); 

        if (P1.mark == P2.mark){
          error("Marks cannot be identical. Please make a change.\n\n");
          cout << "(Press ENTER to return to OPTIONS menu)";
          cin.ignore(); cin.get();
        }
        else
          main(); 
        
        break;
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
  P1.mark = P1.color + P1.character;
  
  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 1 Selection: [" << P1.mark << "]\n";

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
  P2.mark = P2.color + P2.character;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 2 Selection: [" << P2.mark << "]";

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

  P1.mark = P1.color + P1.character;
  
  // Deletes line and writes mark
  clrln(); 
  cout << "Player 1 Selection: [" << P1.mark << "]\n";

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

  P2.mark = P2.color + P2.character;
  
  // Deletes line and writes mark
  clrln(); 
  cout << "Player 2 Selection: [" << P2.mark << "]";

  // Stop Gap
  cout << "\n\n(Press ENTER to return to OPTIONS MENU)" << endl;
  cin.ignore(); cin.get();
}




void RUN_GAME(bool isPractice){
  
  //Declare Variables
  short ROWS, COLS; // Rows and columns for the board matrix
  bool abilityMode = false;
  
  //OUTPUT RULES
  cout << "\x1b[1mRULES\x1b[22m\n\n"
       << "1. Choose the column # to place your mark.\n"
       << "2. Marks can be connected diagonally, vertcally, or horizontally.\n"
       << "3. First player to connect four marks in a row wins the game.\n ";

  cout << "\n(Press ENTER to continue)" << endl;
  cin.ignore(); cin.get();

  clrscr();
  
//Display Board Size Options
  short option;
  do 
  {
    clrscr();
    
    cout << "\x1b[1mChoose a Board Size:\x1b[22m\n\n"
         << "\t1. Classic (7x6)\n"
         << "\t2. Large (9x8)\n"
         << "\t3. Larger (12x9)\n\n";
    cout << "Selection: ";
    cin >> option;

    if(option < 1 || option > 3)
      clrln();
    
  }
  while(option < 1 || option > 3);
    
  // Switch for pre-defined options
  switch(option){

    case 1: COLS = 7 , ROWS = 6; break;
    case 2: COLS = 9 , ROWS = 8; break;
    case 3: COLS = 11, ROWS = 9; break; 
  }

//Display Game Mode Options
  do 
  {
    clrscr();

    cout << "\x1b[1mChoose a Game Mode:\x1b[22m\n\n"
         << "\t1. Classic\n"
         << "\t2. Blinded\n"
         << "\t3. Abilities [W.I.P]\n\n";
    cout << "Selection: ";
    cin >> option;

    if(option < 1 || option > 3)
      clrln();

  }
  while(option < 1 || option > 3);

  // Switch for pre-defined options
  switch(option){

    case 2: // Blinded
        
      /* Sets both marks to "X", adds an additional ANSI code 
           to P2 so program can Differentiate whilst appearing the same */
      P1 = {"", "X\x1b[0m"}; 
      P2 = {"", "X\x1b[0m\x1b[0m"}; 
      break;
    
    case 3: // Abilities
      abilityMode = true; 
      break;
  }

  // Cycle to fill and display blank gameboard (2d Vector)
  clrscr();
  vector<vector<string>> board(ROWS);

  for (short r = 0; r < ROWS; r++) 
    for (short c = 0; c < COLS; c++)
      board[r] = vector<string>(COLS, "[ ]");

  displayBoard(board, COLS, abilityMode);
  
  /// Declaration of game variables ///

  bool no_winner = true; // Determines if the game has a winner or not
  int current_player = 1; // determines which player is playing
  int inputColumn; // specified column index by player
  int inputRow; // specified column index by player 
  short row = ROWS - 1 ; //bottom row index

  // Column and row delete abilities (these will determine the # of ability uses)
  int colDel_P1 = 1, rowDel_P1 = 1; 
  int colDel_P2 = 1, rowDel_P2 = 1;

  // Alternating Variables (these alternate with each iteration of while cycle)
  string player_mark; // writes the designated players mark
  int *colDel = &colDel_P1; // # of ability uses for designated player 
  int *rowDel = &rowDel_P2; // # of ability uses for designated player 

  
///// GAME BEGINS HERE /////
  while (no_winner){
    /* The following condition alternates between players each iteration.
       This is done so the same code doesn't have to be written twice.*/
    if (current_player == 1){
      player_mark = P1.mark;
      colDel = &colDel_P1;
      rowDel = &rowDel_P1;
    }
    else{ 
      player_mark = P2.mark;
      colDel = &colDel_P2;
      rowDel = &rowDel_P2;
    }

    if (isFourInARow(board, COLS, player_mark)){
      main();
    }

  // NOTE !!!!!!: Talvez poner esto en otra funcion??? no se ve demasiado

    bool usedAbility = false; // Will prevent writing a mark if ability is used
    
    // Ability Mode input
    if (abilityMode){ 
      
      do
      {
        cout << "Player " << current_player << " (" << player_mark 
            << ") , choose an action: \n\n";

        cout << "\t1. Place mark\n"
             << "\t2. Delete Column (" << *colDel << " Remaining)\n"
             << "\t3. Delete Row    (" << *rowDel << " Remaining)\n\n\n";

        do
        {
          clrln();
          cout << "Selection: ";
          cin >> option;

          // Input validation if abilities are used up
          if(*colDel == 0 && option == 2 || *rowDel == 0 && option == 3)
            option = -1;   
        } 
        while (option > 3 || option < 1);

        switch(option){
        // Place Mark in Column
          case 1: 
            cout << "Choose a column: "; 
            cin >> inputColumn;
            
            break;
          
        // Delete Column
          case 2: 
            usedAbility = true;
            *colDel -= 1;
            
            cout << "Choose a column to delete: "; 
            cin >> inputColumn;
            
            deleteColumn(board, COLS, inputColumn);
            displayBoard(board, COLS, abilityMode);
            
            if (isFourInARow(board, COLS, player_mark))
              no_winner = false;
            break;
          
        // Delete Row
          case 3: 
            usedAbility = true;
            *rowDel -= 1;
            
            cout << "Choose a row to delete: "; 
            cin >> inputRow;
            
            deleteRow(board, COLS, inputRow);
            displayBoard(board, COLS, abilityMode);
            break;
        }
        clrln();
      }
      while (inputColumn < 0 || inputColumn >= COLS);      
    }
    // Classic mode and Blind Mode Input
    else{
      do{
      cout << "Player " << current_player << " (" << player_mark 
          << ") enter a column #: ";
      cin >> inputColumn;
      clrln();
      }
      while (inputColumn < 0 || inputColumn >= COLS);
    }
    
    // NOTE!!!!!!!!!!!!: create conditition if board is full
    
    //If element isnt empty at highest row, then the column must be full
    if (board[0][inputColumn] != "[ ]")
    {
      do{
      cout << "Selected column is full, choose another: ";
      cin >> inputColumn;
      }
      while(board[0][inputColumn] != "[ ]");
    }

    /* If element at index is occupied, change row to one level higher
       until empty element is found */
    if (board[row][inputColumn] != "[ ]")
      do row--; while(board[row][inputColumn] != "[ ]");
    
    // If element at index is empty and ability was NOT used, write mark
    if (board[row][inputColumn] == "[ ]" && !usedAbility)
      board[row][inputColumn] = "[" + player_mark + "]";

    // Clear old board and display Modified board
    clrscr(); displayBoard(board, COLS, abilityMode);

    if (isFourInARow(board, COLS, player_mark)){
      cout << "\nPlayer " << current_player << " WINS!";
      no_winner = false;
    }
    
    row = ROWS - 1; // Resets row index
    
    // End of player turn, switch to other player 
     if (current_player == 1)
       current_player = 2; 
     else 
       current_player = 1; 
  }

  // Display options after a player wins
  cout << "\n\n(Press ENTER to return to MAIN MENU)" << endl;
  cin.ignore(); cin.get(); 
  
}
  



bool isFourInARow (vector<vector<string>> board, short COLS, string mark){
  
  short mark_counter = 0; // Keeps track of how many marks in a row
  short ROWS = board.size();

////// SCAN ROWS //////

  for (short c = 0 ; c < ROWS; c++){
    mark_counter = 0 ; // Resets counter at each new row
    
    for (short r = 0 ; r < COLS; r++){
      
      if (board[c][r] == "[" + mark + "]"){
        mark_counter++; // If player's mark is found in specified coord
  
        if (mark_counter >= 4){

          // Highlights all the 4 marks in a row by going backwards in COLS index
          do board[c][r--] = "[\x1b[7m" + mark + "]\x1b[27m"; 
          while(board[c][r] == "[" + mark + "]");

          // Clear screen and display winner board
          clrscr(); displayBoard(board, COLS, false);
        
        return true; // 4 in a row = true
        }
      }
      else
        mark_counter = 0 ; // Resets counter if 
    }
  }
  
  mark_counter = 0 ;
  
////// SCAN COLUMNS //////
  
  for (short c = 0 ; c < COLS; c++){
    mark_counter = 0 ; // Resets counter at each new column
    
    for (short r = 0 ; r < ROWS; r++){
      
      if (board[r][c] == "[" + mark + "]"){
        mark_counter++; // If player's mark is found in specified coord
          
        if (mark_counter >= 4){

          // Highlights all the 4 marks in a row by going backwards in ROWS index
          do board[r--][c] = "[\x1b[7m" + mark + "]\x1b[27m"; 
          while(r >= 0 && board[r][c] == "[" + mark + "]");

          // Clear screen and display winner board
          clrscr(); displayBoard(board, COLS, false);
        
          return true; 
        }
      }
      else 
        mark_counter = 0 ;
    }
  }

  mark_counter = 0 ;
  
////// SCAN DIAGONALS //////

  for (int c = 0 ; c < COLS ; c++){

    int i = 0, j = c;

  // Backward slash diagonal scan
    while ( ROWS > i && i >= 0 && COLS > j && j >= 0 ){// Makes sure index exists

      if (board[i][j] == "[" + mark + "]")
        mark_counter++;
      else
        mark_counter = 0;

      if (mark_counter >= 4){
        
        // Highlights all the 4 marks in a row
        do board[i--][j--] = "[\x1b[7m" + mark + "]\x1b[27m"; 
        while(i >= 0 && board[i][j] == "[" + mark + "]");
        // Clear screen and display winner board
        clrscr(); displayBoard(board, COLS, false);
        return true; 
      }
      else
        i++, j++; // Moves index down and to the left

    }
    
    // Redefine Variables if 4 in a row was not found in backward slash
    i = 0, mark_counter = 0;
    j = COLS - c; // This allows j to start from last column minus current iteration

  // Forward slash diagonal scan
    while ( (ROWS > i && i >= 0) && (COLS > j && j >= 0) ){

      if (board[i][j] == "[" + mark + "]")
        mark_counter++;
      else
        mark_counter = 0;

      if (mark_counter >= 4){
        // Highlights all the 4 marks in a row
        do board[i--][j++] = "[\x1b[7m" + mark + "]\x1b[27m"; 
        while(i >= 0 && board[i][j] == "[" + mark + "]");
        
        // Clear screen and display winner board
        clrscr(); displayBoard(board, COLS, false);
        return true; 
      }
      else
        i++, j--; // Moves index down and to the right

    }
    mark_counter = 0;
  }

  
/* Checks diagonals that are left out in the previous scans, these scans originate
from the rows on either end of the board instead of the top of the board */
  for (int r = 1 ; r < ROWS-3; r++){

    int i = r , j = 0;

  // Backward slash diagonal scan
    while (i < ROWS &&  j < COLS){

      if (board[i][j] == "[" + mark + "]")
        mark_counter++;
      else
        mark_counter = 0;
      
      if (mark_counter >= 4){
        // Highlights all the 4 marks in a row
        do board[i--][j--] = "[\x1b[7m" + mark + "]\x1b[27m"; 
        while(i >= 0 && board[i][j] == "[" + mark + "]");
        
        // Clear screen and display winner board
        clrscr(); displayBoard(board, COLS, false);
        return true; 
      }
      else
      i++, j++;

    }

    // Redefine Variables
    mark_counter = 0;
    j = COLS-1; // This allows scan to originate on the right side of the board
    i = r;
    
  // Forward slash diagonal scan
    while (i < ROWS &&  j < COLS){

      if (board[i][j] == "[" + mark + "]")
        mark_counter++;
      else
        mark_counter = 0;

      if (mark_counter >= 4){
        // Highlights all the 4 marks in a row
        do board[i--][j++] = "[\x1b[7m" + mark + "]\x1b[27m"; 
        while(i >= 0 && board[i][j] == "[" + mark + "]");
        
        // Clear screen and display winner board
        clrscr(); displayBoard(board, COLS, false);
        return true; 
      }
      else
        i++, j--;

    }
    mark_counter = 0;
  }
  return false;
}

void deleteColumn (vector<vector<string>> &board, short COLS, int column){

  int ROWS = board.size();

  for (int r = 0 ; r < ROWS; r++)
    board[r][column] = "[ ]";
}


void deleteRow (vector<vector<string>> &board , short COLS, int row){

  for (int i = 0; i < COLS ; i++)
    board[0][i] = "[ ]"; // Empties top row
  
  for(int i = row; i > 0; i--)
    for(int j = 0; j < COLS; j++)
      board[i][j] = board[i - 1][j]; // Shift elements above down
}

void displayBoard(vector<vector<string>> board, short COLS, bool AbilityModeON){

  string color = "\u001b[38;5;21m"; // (BLUE)
  string boardFrame = color + "█\u001b[0m";
  string LcornerFrame  = color + " ▟ \u001b[0m";
  string RcornerFrame  = color + " ▙\u001b[0m";
  string legFrame = color + "▟█▙\u001b[0m";
  
  int ROWS = board.size();

  // Prints numbers on top to identify columns
  cout << LcornerFrame; 
  for(int c = 0 ; c < COLS ; c++) //Iterates over each column
    cout << " " << c << " ";
  cout << RcornerFrame << endl; 
  
  // Prints game board
  for(int r = 0; r < ROWS ; r++){ 
    cout << " " << boardFrame << " "; // left board frame
    
    for(int c = 0 ; c < COLS ; c++)
      cout << board[r][c]; 
    
    cout << " " << boardFrame; // right board frame
    
    if (AbilityModeON) // prints row numbers when playing in abilities mode
      cout << " " << r << endl;
    else
      cout << endl;
  } 

  // Prints "legs" of board
  cout << legFrame;
  for(int c = 0 ; c < COLS ; c++)
    cout << "\u001b[38;5;21m▔▔▔";
  cout << legFrame;
  
  cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";// Spacer
}