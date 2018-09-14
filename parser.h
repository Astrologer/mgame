#ifndef PARSER_H
#define PARSER_H

#include "module.h"


class Parser: public Module {
public:
    Parser(std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue);

protected:
    virtual void run(std::unique_ptr<Command> &&cmd);

};  // Parser


#endif  // PARSER_H
