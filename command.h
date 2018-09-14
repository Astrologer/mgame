#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>
#include "const.h"


class Command {
public:
    static std::unique_ptr<Command> make_term(ModuleType type);

public:
    ModuleType dst;
    ModuleType src;

    std::string raw_command;
    CommandId command;
    std::vector<std::string> args;
    std::string response;
}; // Command


#endif  // COMMAND_H
