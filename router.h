#ifndef ROUTER_H
#define ROUTER_H

#include <memory>
#include "module.h"
#include "queue.h"
#include "command.h"


class Router: public Module {
public:
    Router(int capacity);
    void registr(int type, std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue);
    void registr(int type, std::shared_ptr<Queue<std::unique_ptr<Command>>> &&queue);

protected:
   virtual void run(std::unique_ptr<Command> &&cmd);

 protected:
    std::vector<std::shared_ptr<Queue<std::unique_ptr<Command>>>> queues;

}; // Router


#endif // ROUTER_H
