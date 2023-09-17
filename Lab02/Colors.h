#ifndef COLORS_H
#define COLORS_H
//colors.h - A lightweight replacement for NCURSES that does 24 bit color, cursor movement, and nonblocking I/O
//It uses standard ANSI escape codes to set the foreground and background text colors for a terminal
//Prerequisite: Use with a modern terminal emulator, such as iterm2 for Mac or PuTTY for PC
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <unistd.h>
#include <utility>
#include <cassert>
#include <functional>
#include <queue>

//Usage:
//Echo RED as part of a cout to turn the following text red
//Echo RESET after you are done and it will go back to normal
//Example: cout << RED << "Hello World" << RESET << endl;
const std::string RESET   = "\033[0m";
const std::string BLACK   = "\033[30m";      /* Black */
const std::string RED     = "\033[31m";      /* Red */
const std::string GREEN   = "\033[32m";      /* Green */
const std::string YELLOW  = "\033[33m";      /* Yellow */
const std::string BLUE    = "\033[34m";      /* Blue */
const std::string MAGENTA = "\033[35m";      /* Magenta */
const std::string CYAN    = "\033[36m";      /* Cyan */
const std::string WHITE   = "\033[37m";      /* White */
const std::string BOLDBLACK   = "\033[1m\033[30m";      /* Bold Black */
const std::string BOLDRED     = "\033[1m\033[31m";      /* Bold Red */
const std::string BOLDGREEN   = "\033[1m\033[32m";      /* Bold Green */
const std::string BOLDYELLOW  = "\033[1m\033[33m";      /* Bold Yellow */
const std::string BOLDBLUE    = "\033[1m\033[34m";      /* Bold Blue */
const std::string BOLDMAGENTA = "\033[1m\033[35m";      /* Bold Magenta */
const std::string BOLDCYAN    = "\033[1m\033[36m";      /* Bold Cyan */
const std::string BOLDWHITE   = "\033[1m\033[37m";      /* Bold White */


//24-bit color support.
//NCURSES refuses to implement it since implementation is nonstandard -
//https://invisible-island.net/ncurses/ncurses.faq.html#xterm_16MegaColors

//Sets the background color for all text printed from this point on
//Values range from 0 to 255 in each color channel
//Example: setbgcolor(255,0,255) will set the background color to purple
inline void setbgcolor(uint8_t R, uint8_t G, uint8_t B) {
    std::cerr << "\033[48;2;" << (int)R << ";" << (int)G << ";" << (int)B << "m";
}

//Sets the foreground color for all text printed from this point on
//Example: setcolor(128,128,128) will set the foreground color to 50% grey
inline void setcolor(uint8_t R, uint8_t G, uint8_t B) {
    std::cerr << "\033[38;2;" << (int)R << ";" << (int)G << ";" << (int)B << "m";
}

//Sets the foreground and background colors back to the default
//Example: resetcolor();
inline void resetcolor() {
    std::cerr << "\033[0m";
}

#endif

