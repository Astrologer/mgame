#include <iostream>
#include "queue.h"
#include "command.h"


template<typename T>
void Queue<T>::enqueue(T &&item) {
    {
        std::lock_guard<std::mutex> guard(lock);
        queue.push(std::move(item));
    }
    cv.notify_one();
} // Queue::enqueue


template<typename T>
T Queue<T>::dequeue() {
    std::unique_lock<std::mutex> guard(lock);
    cv.wait(guard, [&](){return !queue.empty();});
    T item = std::move(queue.front());
    queue.pop();
    return item;
} // Queue::dequeue


template class Queue<std::unique_ptr<Command>>;
