#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 
#include "headers/game.h"
#include "headers/mark.h"
#include "headers/4InARowScan.h"
using namespace std;

//Ansi codes for Colors 
const string BLUE = "\u001b[38;5;21m";
const string GREY = "\u001b[38;5;99m";
const string PURPLE = "\x1b[38;5;57m";
const string DEFAULT = "\x1b[0m";
const string BOLD = "\x1b[1m";

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

  int ROWS = board.size();
  
  // Colors
  string boardColor = BLUE; 
  string floorColor = GREY; 
  string resetColor = DEFAULT;

  // Board UI components
  string boardFloor = "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n\n";
  string boardFrame = boardColor + "█" + DEFAULT;
  string LcornerFrame  = boardColor + " ▟" + DEFAULT;
  string RcornerFrame  = boardColor + " ▙" + DEFAULT;
  string legFrame = boardColor + "▟█▙" + DEFAULT;
  string line = "▔▔▔";

  // setw distances for output formatting
  int distLcorner = 50;
  int distRcorner = 19; 
  int distBoardframe = 33;
  int distLegframeL= 55;
  int distLegframeR = 23; 
  
  displayTop(); 
  
  // Prints numbers on top to identify columns
  cout << right << setw(distLcorner-COLS) << LcornerFrame; 
  for(int c = 0 ; c < COLS ; c++){ //Iterates over each column
    cout << "  " << c << "";
  }
  cout << setw(distRcorner) << RcornerFrame << endl; 

  // Prints game board
  for(int r = 0; r < ROWS ; r++){ 
    // left board frame
    cout << setw(distBoardframe-COLS) << " " << boardFrame << " "; 
    
    for(int c = 0 ; c < COLS ; c++){
      cout << board[r][c]; 
    }
    // right board frame
    cout << " " << boardFrame; 

    // Prints row numbers to identify rows
    if (AbilityModeON){
      cout << " " << r;
    }
    
    cout << endl;
  } 

  // Prints "legs" of board
  cout << setw(distLegframeL-COLS) << legFrame;
  for(int c = 0 ; c < COLS ; c++){
    cout << BLUE << line;
  }
  cout << setw(distLegframeR) << legFrame << "\n";

  // Prints board floor
  int distBoardfloor = 21; 
  cout << right  << setw(distBoardfloor) << "" << boardFloor;

  displayBottom(ROWS+4); // Accomodates board size + Adittional UI space
}

int RUN_GAME(bool isPractice, mark P1, mark P2){

  short ROWS, COLS; // Rows and columns for the board matrix
  bool abilityModeON = false; // Checks if player selected ability gamemode

  //OUTPUT RULES
   
  displayTop();
  cout << setw(42) << BOLD << "RULES" << DEFAULT << "\n\n"
       << setw(52) << "1. Choose the column # to place your mark.\n"
       << setw(75) << "2. Marks can be connected diagonally, vertcally, or horizontally.\n"
       << setw(72) << "3. First player to connect four marks in a row wins the game.\n ";

  cout<< setw(55) << endl << "(Press ENTER to continue)\n";
  displayBottom(7);
  
  cin.ignore(); cin.get();

//Display Board Size Options

  char option;
  do 
  {
    displayTop();
    cout << setw(37) << BOLD << "Choose a Board Size: " << DEFAULT << "\n\n"
         << setw(51) <<  "\t1. Classic (7x6)\n"
         << setw(51) << "\t2. Large (9x8)\n"
         << setw(54) << "\t3. Larger (12x9)\n\n";
    cout << setw(47) << "Selection: ";
    displayBottom(6);
    
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
    displayTop();
    cout << setw(37) << BOLD << "Choose a Game Mode: " << DEFAULT << "\n\n"
         << setw(46) << "\t1. Classic\n"
         << setw(46) <<"\t2. Blinded\n"
         << setw(50) << "\t3. Abilities\n\n";
    cout << setw(47) << "Selection: ";
    displayBottom(6);
    
    cin >> option;

    if(option < 49 || option > 51)
      clrln();
  }
  while(option < 49 || option > 51);

  // Switch for pre-defined options
  switch(option){
    case 50: // Blinded

      /* Sets both marks to purple "X", adds an additional ANSI code 
        to P2 so program can Differentiate whilst appearing the same */
      P1 = {PURPLE, "X" + DEFAULT}; 
      P2 = {PURPLE, "X" + DEFAULT + DEFAULT}; 
      break;

    case 51: // Abilities
      
      abilityModeON = true; 
      break;
  }

  // Cycle to fill and display blank gameboard (2d Vector)
  vector<vector<string>> board(ROWS);

  for (short r = 0; r < ROWS; r++) 
    for (short c = 0; c < COLS; c++)
      board[r] = vector<string>(COLS, "[ ]");

  displayBoard(board, COLS, abilityModeON);

  /// Declaration of game variables ///

  // bool isWinner = false; // Determines if the game has a winner or not
  int activePlayer = 1; // determines which player is playing
  int inputCol; // specified column index by player
  int inputRow; // specified column index by player 

  // Column and row delete abilities (these will determine the # of ability uses)
  const int abilityUses = 1;
  
  int colDel_P1 = abilityUses, 
      rowDel_P1 = abilityUses;
  
  int colDel_P2 = abilityUses, 
      rowDel_P2 = abilityUses;

  // Alternating Variables (these alternate with each iteration of while cycle)
  string player_mark; // writes the designated players mark
  int *colDel; // # of ability uses for designated player 
  int *rowDel; // # of ability uses for designated player 


///// GAME BEGINS HERE /////

  
  while (true){
    
    /* The following condition alternates between players each iteration.
       This is done so the same code doesn't have to be written twice.*/
    if (activePlayer == 1){
      player_mark = P1.mark;
      colDel = &colDel_P1;
      rowDel = &rowDel_P1;
    }
    else{ 
      player_mark = P2.mark;
      colDel = &colDel_P2;
      rowDel = &rowDel_P2;
    }

    short row = ROWS - 1 ; //bottom row index
    
    // Check if 4 in a row
    // counter de cuantas jugadas has hecho
    if (isFourInARow(board, COLS, player_mark)){
      displayBoard(board, COLS, false); 
      break;
    }

    // Check if board is full
    bool boardisFull = true;
    for (int c = 0 ; c < COLS; c++){
      if(board[0][c] == "[ ]")
        boardisFull = false;
    }

    if (boardisFull){
      cout << setw(55) <<  "Board is full, game is a tie.\n\n";
      cout << setw(58) << "(Press ENTER to return to MAIN MENU)" << endl;
      cin.ignore(); cin.get(); 

      return 0;
    }
    
    // Ability Mode input
    bool usedAbility = false; // Will prevent writing a mark if ability is used
    
    if (abilityModeON){ 

      do
      {
        cout << right << setw(31) << "Player " << activePlayer << " (" << player_mark 
            << ") , choose an action: \n\n";

        cout << setw(41) << "\t1. Place mark\n"
             << setw(45) << "\t2. Delete Column (" << *colDel << " Remaining)\n"
             << setw(46) << "\t3. Delete Row    (" << *rowDel << " Remaining)\n\n\n";
        // displayBottom(ROWS+7); // (Takes into account board)

        do
        {
          clrln();
          cout << setw(45) << "Selection: ";
          cin >> option;

          // Input validation if abilities are used up
          if(*colDel == 0 && option == 50 || *rowDel == 0 && option == 51)
            option = -1;   
        } 
        while (option > 51 || option < 49);

        switch(option){
        // Place Mark in Column
          case 49: 
            cout << setw(45) << "Choose a column: "; 
            cin >> inputCol;

            break;

        // Delete Column
          case 50: 
            usedAbility = true;
            *colDel -= 1;

            cout << setw(53) << "Choose a column to delete: "; 
            cin >> inputCol;

            deleteColumn(board, COLS, inputCol);
            displayBoard(board, COLS, abilityModeON);
      
            break;

        // Delete Row
          case 51: 
            usedAbility = true;
            *rowDel -= 1;

            cout << setw(53) << "Choose a row to delete: "; 
            cin >> inputRow;

            deleteRow(board, COLS, inputRow);
            displayBoard(board, COLS, abilityModeON);
            
            break;
        }
        clrln();
      }
      while (inputCol < 0 || inputCol >= COLS);      
    }
    // Classic mode and Blind Mode Input

    if (not abilityModeON ){
      do{
      cout << setw(32) <<  "Player " << activePlayer << " (" << player_mark 
          << ") enter a column #: ";
      cin >> inputCol;
      clrln();
      }
      while (inputCol < 0 || inputCol >= COLS);
    }

    
    //If element isnt empty at highest row, then the column must be full
    if (board[0][inputCol] != "[ ]" )
    {
      do{
      clrln();
      cout << setw(20) << "Selected column is full, choose another: ";
      cin >> inputCol;
      }
      while(board[0][inputCol] != "[ ]");
    }

    /* If element at index is occupied, change row to one level higher
       until empty element is found */
    if (board[row][inputCol] != "[ ]" )
      do row--; while(board[row][inputCol] != "[ ]");

    // If element at index is empty and ability was NOT used, write mark
    if (board[row][inputCol] == "[ ]" && !usedAbility){
      
      board[row][inputCol] = "[" + player_mark + "]";
      displayBoard(board, COLS, abilityModeON);
    }

    // Display winner 
    if (isFourInARow(board, COLS, player_mark)){
      displayBoard(board, COLS, false);
      break;
    }

    // End of player turn, switch to other player 
     if (activePlayer == 1)
       activePlayer = 2; 
     else 
       activePlayer = 1; 
  }

  if (not isPractice){
    // Add Point to winning player
    int winnerPoints = 0;
    
    ifstream getPoints("records/P" + to_string(activePlayer) + "points.txt");
    getPoints >> winnerPoints; // take existing points
    getPoints.close();
    
    winnerPoints += 1; // Add 1
  
    ofstream writePoints("records/P" + to_string(activePlayer) + "points.txt");
    writePoints << winnerPoints; // write to txt file
    writePoints.close();
  }

  // Display total points
  int P1points, P2points;
  
  ifstream getP1Points("records/P1points.txt");
  getP1Points >> P1points;
  ifstream getP2Points("records/P2points.txt");
  getP2Points >> P2points;


  // distance for the setw
  int dist = 37;
  int dist2 = 58;
  
  // Display Winner
  cout << setw(dist) << BOLD << "Player " << activePlayer << " WINS!" << DEFAULT << "\n\n";

  cout << setw(dist) << "Total P1 Pts: " << P1points << endl;
  cout << setw(dist) << "Total P2 Pts: " << P2points << endl;
  
  cout << "\n" << setw(dist2) << "(Press ENTER to return to MAIN MENU)" << endl;
  cin.ignore(); cin.get(); 
  
  return 0;
}
