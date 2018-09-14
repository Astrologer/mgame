#ifndef TERMINAL_H
#define TERMINAL_H

#include "module.h"


class Terminal: public Module {
public:
    Terminal(std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue);
    void listen();

protected:
    virtual void run(std::unique_ptr<Command> &&cmd);

};  // Terminal


#endif  // TERMINAL_H
