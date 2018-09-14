#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>


template<typename T>
class Queue {
    //static_assert(std::is_base_of<Command, T>::value, "T must extend command");
public:
    void enqueue(T &&item);
    T dequeue();

protected:
    std::queue<T> queue;
    std::mutex lock;
    std::condition_variable cv;
}; // Queue


#endif  // QUEUE_H
