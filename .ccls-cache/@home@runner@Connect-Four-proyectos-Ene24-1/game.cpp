#include <iostream>
#include <string>
#include <vector>
#include "headers/game.h"
#include "headers/mark.h"
#include "headers/4InARowScan.h"
using namespace std;

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

  // cout << " ██████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗ ██████╗████████╗    ██╗  ██╗" << endl <<
  //   "██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██╔════╝╚══██╔══╝    ██║  ██║" << endl <<
  //   "██║     ██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║        ██║       ███████║" << endl <<
  //   "██║     ██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║        ██║       ╚════██║" << endl <<
  //   "╚██████╗╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╗   ██║            ██║" << endl <<
  //   " ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═╝            ╚═╝" << endl << endl;


  
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

int RUN_GAME(bool isPractice, mark P1, mark P2){

  //Declare Variables
  short ROWS, COLS; // Rows and columns for the board matrix
  bool abilityModeON = false;

  //OUTPUT RULES
  cout << "\x1b[1mRULES\x1b[22m\n\n"
       << "1. Choose the column # to place your mark.\n"
       << "2. Marks can be connected diagonally, vertcally, or horizontally.\n"
       << "3. First player to connect four marks in a row wins the game.\n ";

  cout << "\n(Press ENTER to continue)" << endl;
  cin.ignore(); cin.get();

  clrscr();

//Display Board Size Options
  char option;
  do 
  {
    clrscr();

    cout << "\x1b[1mChoose a Board Size:\x1b[22m\n\n"
         << "\t1. Classic (7x6)\n"
         << "\t2. Large (9x8)\n"
         << "\t3. Larger (12x9)\n\n";
    cout << "Selection: ";
    cin >> option;

    if(option < 49 || option > 51)
      clrln();

  }
  while(option < 49 || option > 51);

  // Switch for pre-defined options
  switch(option){

    case 49: COLS = 7 , ROWS = 6; break;
    case 50: COLS = 9 , ROWS = 8; break;
    case 51: COLS = 11, ROWS = 9; break; 
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

    if(option < 49 || option > 51)
      clrln();

  }
  while(option < 49 || option > 51);

  // Switch for pre-defined options
  switch(option){

    case 50: // Blinded

      /* Sets both marks to "X", adds an additional ANSI code 
           to P2 so program can Differentiate whilst appearing the same */
      P1 = {"", "X\x1b[0m"}; 
      P2 = {"", "X\x1b[0m\x1b[0m"}; 
      break;

    case 51: // Abilities
      abilityModeON = true; 
      break;
  }

  // Cycle to fill and display blank gameboard (2d Vector)
  clrscr();
  vector<vector<string>> board(ROWS);

  for (short r = 0; r < ROWS; r++) 
    for (short c = 0; c < COLS; c++)
      board[r] = vector<string>(COLS, "[ ]");

  displayBoard(board, COLS, abilityModeON);

  /// Declaration of game variables ///

  bool isWinner = false; // Determines if the game has a winner or not
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
  int *rowDel = &rowDel_P1; // # of ability uses for designated player 


///// GAME BEGINS HERE /////
  while (!isWinner){
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
      clrscr(); displayBoard(board, COLS, false);
      cout << "\nPlayer " << current_player << " WINS!";
      cout << "\n\n(Press ENTER to return to MAIN MENU)" << endl;
      cin.ignore(); cin.get();
      return 0;
    }

  // NOTE !!!!!!: Talvez poner esto en otra funcion??? no se ve demasiado

    bool usedAbility = false; // Will prevent writing a mark if ability is used

    // Ability Mode input
    if (abilityModeON && !isWinner){ 

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
          if(*colDel == 0 && option == 50 || *rowDel == 0 && option == 51)
            option = -1;   
        } 
        while (option > 51 || option < 49);

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
            displayBoard(board, COLS, abilityModeON);

            if (isFourInARow(board, COLS, player_mark))
              isWinner = true;
            break;

        // Delete Row
          case 3: 
            usedAbility = true;
            *rowDel -= 1;

            cout << "Choose a row to delete: "; 
            cin >> inputRow;

            deleteRow(board, COLS, inputRow);
            displayBoard(board, COLS, abilityModeON);
            break;
        }
        clrln();
      }
      while (inputColumn < 0 || inputColumn >= COLS);      
    }
    // Classic mode and Blind Mode Input

    if (!abilityModeON && !isWinner){
      do{
      cout << "Player " << current_player << " (" << player_mark 
          << ") enter a column #: ";
      cin >> inputColumn;
      clrln();
      }
      while (inputColumn < 0 || inputColumn >= COLS);
    }

    // NOTE!!!!!!!!!!!!: create conditition if board is full

    // NOTE!!!!!!!!!!!!: create function to check if board is full. 

    //If element isnt empty at highest row, then the column must be full
    if (board[0][inputColumn] != "[ ]" && !isWinner)
    {
      do{
      cout << "Selected column is full, choose another: ";
      cin >> inputColumn;
      }
      while(board[0][inputColumn] != "[ ]");
    }

    /* If element at index is occupied, change row to one level higher
       until empty element is found */
    if (board[row][inputColumn] != "[ ]" && !isWinner)
      do row--; while(board[row][inputColumn] != "[ ]");

    // If element at index is empty and ability was NOT used, write mark
    if (board[row][inputColumn] == "[ ]" && !usedAbility && !isWinner)
      board[row][inputColumn] = "[" + player_mark + "]";

    // Clear old board and display Modified board
    clrscr(); displayBoard(board, COLS, abilityModeON);

    if (!isWinner && isFourInARow(board, COLS, player_mark)){
      clrscr(); displayBoard(board, COLS, false);
      cout << "\nPlayer " << current_player << " WINS!";
      cout << "\n\n(Press ENTER to return to MAIN MENU)" << endl;
      cin.ignore(); cin.get();
      return 0;
    }

    row = ROWS - 1; // Resets row index

    // End of player turn, switch to other player 
     if (current_player == 1)
       current_player = 2; 
     else 
       current_player = 1; 
  }

  cout << "\n\n(Press ENTER to return to MAIN MENU)" << endl;
  cin.ignore(); cin.get(); 
  return 0;
}
