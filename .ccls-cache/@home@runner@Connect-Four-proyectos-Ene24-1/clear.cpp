#include "clear.h"
#include <iostream>

inline void clrscr()
{std::cout << "\033c";}

inline void clrln()
{std::cout << "\x1B[1A\x1B[2K";}