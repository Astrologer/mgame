#include <iostream>
#include <string>

#include "terminal.h"


Terminal::Terminal(std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue): Module(queue) {
    type = TERMINAL;
} // Terminal::Terminal


void Terminal::run(std::unique_ptr<Command> &&cmd) {
    std::cout << cmd.get()->response << std::flush;
}  // Terminal::run


void Terminal::listen() {
    while (true) {
        std::string raw;
        std::getline(std::cin, raw);
        if (!raw.compare("exit"))
            return;
        std::unique_ptr<Command> cmd(new Command());
        cmd.get()->dst = PARSE;
        cmd.get()->src = TERMINAL;
        cmd.get()->raw_command = raw;

        output.get()->enqueue(std::move(cmd));
    }
}  // Terminal::listen
