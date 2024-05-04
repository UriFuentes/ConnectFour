#ifndef MARK_H
#define MARK_H
#include <iostream>
#include <string>

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

inline void saveCursor() // saves cursor position
{cout << "\x1b[s";}

/* returns to last saved cursor position + moves cursor up N spaces,
   where N = width of the arcade machine screen*/
inline void returnCursor() 
{cout << "\x1b[u" << "\x1b[18A";}

#endif
