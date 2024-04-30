#ifndef MARK_H
#define MARK_H
#include <string>
#include <iostream>
using namespace std;

struct mark{
  string color;
  string character;
  string mark = color + character;
};

inline void clrscr() // clears console screen
{cout << "\033c";}

inline void clrln() // clears line
{cout << "\x1B[1A\x1B[2K";}

inline void warning(string msg) // displays warning message 
{cout << "\u001b[41mWarning\x1b[0m: " << msg;}

inline void error(string msg) // displays error message
{cout << "\u001b[41mERROR!\x1b[0m: " << msg;}

#endif
