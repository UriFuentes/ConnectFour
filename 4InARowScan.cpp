#include <string>
#include <vector>
#include "headers/mark.h"
#include "headers/4InARowScan.h"
using namespace std;

bool isFourInARow (vector<vector<string>> &board, short COLS, string mark){

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

        return true; 
      }
      else
        i++, j--;

    }
    mark_counter = 0;
  }
  return false;
}