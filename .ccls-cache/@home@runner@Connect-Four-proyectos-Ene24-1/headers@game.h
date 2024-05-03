#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "mark.h"
using namespace std;

int RUN_GAME(bool, mark, mark);

void displayBoard (vector<vector<string>>, short, bool); 
void deleteRow (vector<vector<string>> &board , short COLS, int row);
void deleteColumn (vector<vector<string>> &board, short COLS, int column);


#endif