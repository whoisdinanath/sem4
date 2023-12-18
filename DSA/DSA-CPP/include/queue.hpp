#include <iostream>
#include <vector>

class Queue
{
private:
    std::vector<int> queue;
    int front;
    int rear;
    int size;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int item);
    int dequeue();
    bool isFull();
    bool isEmpty();
    void display();
};