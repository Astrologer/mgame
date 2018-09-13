#include <memory>
#include <thread>
#include "queue.h"
#include "module.h"


Module::Module(std::shared_ptr<Queue<int>> &queue): output(queue) {
    input = std::make_shared<Queue<int>>();
} // Module::Module


Module::~Module() {
    worker.join();
} // Module::Module



std::shared_ptr<Queue<int>> Module::get_queue() {
    return input;
} // Module::get_queue


int Module::get_type() {
    return type;
} // Module::get_type


void Module::start() {
    worker = std::thread(&Module::run, this);
} // Module::start
