// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// void deleteColumn (vector<vector<string>> &board, short COLS, int column){

//   int ROWS = board.size();

//   for (int r = 0 ; r < ROWS; r++)
//     board[r][column] = "[ ]";
// }


// void deleteRow (vector<vector<string>> &board , short COLS, int row){

//   for (int i = 0; i < COLS ; i++)
//     board[0][i] = "[ ]"; // Empties top row

//   for(int i = row; i > 0; i--)
//     for(int j = 0; j < COLS; j++)
//       board[i][j] = board[i - 1][j]; // Shift elements above down
// }

// void displayBoard(vector<vector<string>> board, short COLS, bool AbilityModeON){

//   string color = "\u001b[38;5;21m"; // (BLUE)
//   string boardFrame = color + "█\u001b[0m";
//   string LcornerFrame  = color + " ▟ \u001b[0m";
//   string RcornerFrame  = color + " ▙\u001b[0m";
//   string legFrame = color + "▟█▙\u001b[0m";

//   int ROWS = board.size();

//   // Prints numbers on top to identify columns
//   cout << LcornerFrame; 
//   for(int c = 0 ; c < COLS ; c++) //Iterates over each column
//     cout << " " << c << " ";
//   cout << RcornerFrame << endl; 

//   // Prints game board
//   for(int r = 0; r < ROWS ; r++){ 
//     cout << " " << boardFrame << " "; // left board frame

//     for(int c = 0 ; c < COLS ; c++)
//       cout << board[r][c]; 

//     cout << " " << boardFrame; // right board frame

//     if (AbilityModeON) // prints row numbers when playing in abilities mode
//       cout << " " << r << endl;
//     else
//       cout << endl;
//   } 

//   // Prints "legs" of board
//   cout << legFrame;
//   for(int c = 0 ; c < COLS ; c++)
//     cout << "\u001b[38;5;21m▔▔▔";
//   cout << legFrame;

//   cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";// Spacer
// }