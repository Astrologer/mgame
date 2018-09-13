#include <mutex>
#include "queue.h"


template<typename T>
void Queue<T>::enqueue(const T &item) {
    {
        std::lock_guard<std::mutex> guard(lock);
        queue.push(item);
    }
    cv.notify_one();
} // Queue::enqueue


template<typename T>
T Queue<T>::dequeue() {
    std::unique_lock<std::mutex> guard(lock);
    cv.wait(guard, [&](){return !queue.empty();});
    T item = queue.front();
    queue.pop();
    return item;
} // Queue::dequeue


template class Queue<int>;
