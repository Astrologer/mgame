#include <iostream>
#include <string>

#include "parser.h"


Parser::Parser(std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue): Module(queue) {
    type = PARSE;
} // Parser::Parser


void Parser::run(std::unique_ptr<Command> &&cmd) {
    cmd.get()->dst = TERMINAL;
    cmd.get()->src = PARSE;
    cmd.get()->response = "<" + cmd.get()->raw_command + ">\n";

    output.get()->enqueue(std::move(cmd));
}  // Parser::run
