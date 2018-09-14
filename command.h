#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>
#include "const.h"


class Command {
public:
    ModuleType dst;
    ModuleType src;

    std::string raw_command;
    CommandId command;
    std::vector<std::string> args;

}; // Command


#endif  // COMMAND_H
