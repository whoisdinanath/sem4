#include <queue.hpp>

Queue::Queue(int size)
{
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->queue = std::vector<int>(size);
}