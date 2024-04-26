#include <iostream>
#include <string>
#include <vector>

using namespace std;

// NOTES: Use cin.ignore to avoid overflow in inputs

void displayBoard (vector<vector<string>>, short); // Displays game board
void RUN_GAME(string &, string &, bool); // Game Functions
void OPTIONS(string &, string &); // Game Options
bool isFourInARow(vector<vector<string>>, short, string); // Checks for 4-in-a-row

inline void clrscr(); // Clear Screen
inline void clrln(); // Clear line

int main(){
  
  // Default Player marks + default color code
  string P1_mk = "X\u001b[0m", P2_mk = "O\u001b[0m";
  string &P1_mark = P1_mk, &P2_mark = P2_mk;

  short option;
  do
  {
    clrscr();
    
    // Output Game Title in BOLD
    cout << "\x1b[1mC O N N E C T  4\x1b[22m\n\n";

    cout << "\t1. Play\n"
         << "\t2. Practice\n"
         << "\t3. Options\n"
         << "\t4. Exit\n";

    cout << "\nSelection: ";
    cin >> option;

    // input validation
    if (option < 1 || option > 4)
      cout << "ERROR, please enter number 1-4\n";

    switch(option){

      // Not Practice
      case 1: clrscr(); RUN_GAME(P1_mark, P2_mark, false); break; 

      // Practice
      case 2: clrscr(); RUN_GAME(P1_mark, P2_mark, true); break; 

      case 3: clrscr(); OPTIONS(P1_mark, P2_mark); break;

      case 4: return 0;
    } 
  }
  while(1);


}

void OPTIONS(string &P1_mark, string &P2_mark){

  // Display List of available colors in with ANSI codes

  cout << "Available colors:\n"
     << "\t1. \u001b[31mRed\u001b[0m\n"
     << "\t2. \u001b[32mGreen\u001b[0m\n"
     << "\t3. \u001b[33mYellow\u001b[0m\n"
     << "\t4. \u001b[34mBlue\u001b[0m\n"
     << "\t5. \u001b[35mMagenta\u001b[0m\n"
     << "\t6. \u001b[36mCyan\u001b[0m\n"
     << "\t7. White (Default)\n"
     << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  
  short option;

  /////// PLAYER 1 SELECTION ///////
  do
  {
    // Reset Value to avoid ANSI code buildup
    P1_mark = "X\u001b[0m";
  
    cout << "Player 1 Selection: "; 
    cin >> option;

    if(option > 7 || option < 1)
      clrln();
  }
  while(option > 7 || option < 1);

  // Take Input and plug into ANSI Code, adding such to P1_mark
  P1_mark = "\u001b[3" + to_string(option) + "m" + P1_mark;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 1 Selection: [" << P1_mark << "]\n";

  /////// PLAYER 2 SELECTION ///////
  do
  {
    // Reset Value to avoid code buildup
    P2_mark = "O\u001b[0m"; 

    cout << "Player 2 Selection: "; 
    cin >> option;

    if(option > 7 || option < 1)
      clrln();
  }
  while(option > 7 || option < 1);
  
  P2_mark = "\u001b[3" + to_string(option) + "m" + P2_mark;

  // Deletes line and writes mark with selected color
  clrln(); 
  cout << "Player 2 Selection: [" << P2_mark << "]";

  // Stop Gap
  cout << "\n\n(Press any key to return to MAIN MENU)" << endl;
  cin.get(); cin.get();

  //NOTE: Make a while cycle to make branch to allow changing characters, have a sentinel value
}

void RUN_GAME(string &P1_mark, string &P2_mark, bool isPractice){

  //Declare Variables
  short option; // Used for menu
  short ROWS, COLS; // Rows and columns for the board matrix
  
  //OUTPUT RULES (MISSING!!!!!!!!!!!!!!!!!!) 

  //Display Board Size Options
  do 
  {
    cout << "Choose a Board Size:\n"
         << "\t1. Classic (7x6)\n"
         << "\t2. Large (9x8)\n"
         << "\t3. Larger (12x9)\n"
         << "\t4. Custom\n";
    cout << "Selection: ";
    cin >> option;

    if(option < 1 || option > 4)
      clrln();
    
  }
  while(option < 1 || option > 4);

  //IF user chooses custom board
  if(option == 4){
    clrscr();
      
    cout << "\nEnter # of desired columns in board: ";
    cin >> COLS;
    cout << "\nEnter # of desired rows in board: ";
    cin >> ROWS;
    
    // NOTE: Talvez ponerle una restriccion? Los numeros de arriba se ponen raros si es demasiado grande
    
  }
  else // Switch for pre-defined options
    switch(option){

      case 1: COLS = 7 , ROWS = 6; break;
      case 2: COLS = 9 , ROWS = 8; break;
      case 3: COLS = 12, ROWS = 9; break;
    
    }

  // Cycle to fill and display blank gameboard (2d array)
  clrscr();
  vector<vector<string>> board(ROWS); // 2d Vector

  for (short r = 0; r < ROWS; r++) //Iterates over each column
      for (short c = 0; c < COLS; c++)  //Iterates over each row
          board[r] = vector<string>(COLS, "[ ]"); //Writes into every element

  displayBoard(board, COLS);
  
  /// Declaration of game variables ///
  bool no_winner = true; // Determines if the game has a winner or not
  short current_player = 1; // determines which player is playing
  short column; // specified column index
  short row = ROWS - 1 ; //bottom row index
  string player_mark; // writes the designated players mark 

  while (no_winner){
    /* The following condition alternates between players each iteration.
       This is done so the same code doesn't have to be written twice.*/
    if (current_player == 1)
      player_mark = P1_mark; 
    else 
      player_mark = P2_mark;

    //Ask for column to drop mark into
    cout << "\nPlayer " << current_player << ", enter a column #: ";

    cin >> column;
    // column--;

    //If element isnt empty at highest row, then the column must be full
    if (board[0][column] != "[ ]")
    {
      do{
      cout << "Selected column is full, choose another: ";
      cin >> column; 
      }
      while(board[0][column] != "[ ]");
    }

    /* If element at index is occupied, change row to one level higher
       until empty element is found */
    if (board[row][column] != "[ ]")
      do row--; while(board[row][column] != "[ ]");
    
    // If element at index is empty, write player mark
    if (board[row][column] == "[ ]")
      board[row][column] = "[" + player_mark + "]";

    // Clear old board
    clrscr();
    
    //Display Modified board
    displayBoard(board, COLS);

    // Verify if 4-in-a-row

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
  cout << "\n\n(Press any key to return to MAIN MENU)" << endl;
  cin.get(); cin.get(); // NOTE: Doesnt work with one for some reason
  


  //NOTE: Anadir opcion para jugar denuevo, regresar al menu, cambiar las opciones

  

  
}
  

bool isFourInARow
(vector<vector<string>> board, short COLS, string mark){
  
  short mark_counter = 0; // Keeps track of how many marks in a row
  short ROWS = board.size();

  cout << "TOTAL ROW: " << ROWS << " TOTAL COLS: "<< COLS;

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
          clrscr(); displayBoard(board, COLS);
        
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
          clrscr(); displayBoard(board, COLS);
        
          return true; 
        }
      }
      else 
        mark_counter = 0 ;
    }
  }

  mark_counter = 0 ;
  
  ////// SCAN DIAGONALS [BROKEN] //////

  for (short c = 0 ; c < COLS; c++){
    mark_counter = 0 ; // Resets counter at each new column

    for (short r = 0 ; r < ROWS; r++){

      if (board[r][c] == "[" + mark + "]"){
        // mark_counter++; // If player's mark is found in specified coord
        cout << "\nTest: " << mark_counter << " ROW: " << r << " COL: " << c;

        cout << endl <<"ROW SPECIFIED: " << ++r << " COL SPECIFIED: " << ++c << endl;
        
        //If Index in within the vector (prevents accessing nonexistent element)
        const bool IndexisInVector = ++r < ROWS && ++c < COLS;

        for (int i = 0; i < 4 ; i++){

          if (mark_counter >= 4)
            return true;
  
          if (IndexisInVector && board[r][c] == "[" + mark + "]"){
            ++mark_counter; 
            cout << "DIAG: " << mark_counter;

          }
          else
            break;

        }
        
        // while (IndexisInVector && board[r][c] == "[" + mark + "]"){
        // //If another mark is found to the right of the first scanned mark
        //   ++mark_counter; 
        //   cout << "DIAG: " << mark_counter;

        //   if (mark_counter >= 4)
        //     return true;
          
        }
        mark_counter = 0;
      }
    }
  }

  mark_counter = 0;
  
  return false;
}


void displayBoard(vector<vector<string>> board, short COLS){

  short ROWS = board.size();

  // Displays numbers on top to identify columns
  for(short c = 0 ; c < COLS ; c++) //Iterates over each column
    cout << " " << c << " ";
  cout << endl;

  // Displays game board
  for(short r = 0; r < ROWS ; r++){ //Iterates over each row
    for(short c = 0 ; c < COLS ; c++) //Iterates over each column
      cout << board[r][c]; // displays element
    cout << endl;
  } 
}

inline void clrscr()
{cout << "\033c";}

inline void clrln()
{cout << "\x1B[1A\x1B[2K";}