#ifndef MODULE_H
#define MODULE_H

#include <memory>
#include <thread>
#include "queue.h"
#include "command.h"
#include "const.h"


class Module {
public:
    Module(std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue);
    Module();
    virtual ~Module();
    void start();

    std::shared_ptr<Queue<std::unique_ptr<Command>>> get_queue();
    int get_type();

protected:
    void main_loop();
    virtual void run(std::unique_ptr<Command> &&cmd) = 0;

protected:
    std::shared_ptr<Queue<std::unique_ptr<Command>>> input;
    std::shared_ptr<Queue<std::unique_ptr<Command>>> output;
    std::thread worker;
    ModuleType type;

}; // Module


#endif  // MODULE_H
