#ifndef MODULE_H
#define MODULE_H

#include <memory>
#include <thread>
#include "queue.h"


class Module {
public:
    Module(std::shared_ptr<Queue<int>> &queue);
    virtual ~Module();
    void start();

    std::shared_ptr<Queue<int>> get_queue();
    int get_type();

protected:
    virtual void run() = 0;

 protected:
    std::shared_ptr<Queue<int>> input;
    std::shared_ptr<Queue<int>> output;
    std::thread worker;
    int type;

}; // Module


#endif  // MODULE_H
