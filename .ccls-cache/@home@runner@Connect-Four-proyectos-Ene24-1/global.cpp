#include <iostream>
#include <string>
#include <vector>
#include "global.h"
using namespace std;


inline void clrscr()
{cout << "\033c";}

inline void clrln()
{cout << "\x1B[1A\x1B[2K";}