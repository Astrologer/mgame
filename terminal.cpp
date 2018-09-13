#include <iostream>
#include <string>

#include "terminal.h"


void Terminal::run() {
    while (true) {
        std::string cmd;
        std::getline(std::cin, cmd);
        std::cout << cmd;
    }
}  // Terminal::run
