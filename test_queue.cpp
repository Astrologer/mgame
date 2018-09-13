#include <iostream>
#include <thread>
#include <chrono>
#include "queue.h"


void enqueue(Queue<int> &q) {
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


int main(int argc, char *argv[]) {

    // int i = 42;
    Queue<int> q;

    std::thread t(enqueue, std::ref(q));

    for (int i = 0; i < 10; i++)
        std::cout << q.dequeue() << "\n";

    t.join();
    /*
    q.enqueue(i);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";
    */
    return 0;
}
