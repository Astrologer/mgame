#include <iostream>
#include "module.h"


Module::Module(std::shared_ptr<Queue<std::unique_ptr<Command>>> &queue): Module() {
    output = queue;
} // Module::Module


Module::Module() {
    input = std::make_shared<Queue<std::unique_ptr<Command>>>();
} // Module::Module


Module::~Module() {
    worker.join();
} // Module::Module


std::shared_ptr<Queue<std::unique_ptr<Command>>> Module::get_queue() {
    return input;
} // Module::get_queue


int Module::get_type() {
    return type;
} // Module::get_type


void Module::start() {
    worker = std::thread(&Module::main_loop, this);
} // Module::start


void Module::main_loop() {
    while (true) {
        std::unique_ptr<Command> cmd = input.get()->dequeue();
        if (cmd.get()->dst == type and cmd.get()->command == TERM)
            return;

        run(std::move(cmd));
    }
} // Module::start
