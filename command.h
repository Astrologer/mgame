#ifndef COMMAND_H
#define COMMAND_H

#include <vector>

using std::vector;


class Command {
public:
    Comand(vector<char>);
    vector<char> pack();
}; // Command


#endif  // COMMAND_H
