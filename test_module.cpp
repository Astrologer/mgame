#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "queue.h"
#include "module.h"


class Worker: public Module {
public:
    Worker(std::shared_ptr<Queue<int>> &queue): Module(queue) {}

protected:
    void run() {
        int i;
        i = input.get()->dequeue();
        output.get()->enqueue(i);
    }
};


int main(int argc, char *argv[]) {
    std::shared_ptr<Queue<int>> input = std::make_shared<Queue<int>>();
    Worker w(input);
    std::shared_ptr<Queue<int>> output = w.get_queue();
    w.start();
    output.get()->enqueue(42);
    std::cout << input.get()->dequeue() << "\n";

    return 0;
}
