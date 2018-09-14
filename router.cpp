#include <iostream>
#include "router.h"


Router::Router(int capacity) {
    queues.resize(capacity);
    type = ROUTE;
} // Router::Router


void Router::registr(int type, std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue) {
    queues[type] = queue;
} // Router::registr


void Router::registr(int type, std::shared_ptr<Queue<std::unique_ptr<Command>>> &&queue) {
    queues[type] = queue;
} // Router::registr


void Router::run(std::unique_ptr<Command> &&cmd) {
    queues[cmd.get()->dst].get()->enqueue(std::move(cmd));
} // Router::run
