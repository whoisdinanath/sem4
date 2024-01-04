#include <iostream>
#include <vector>

class CircularQueue
{
private:
    std::vector<int> queue;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size);
    ~CircularQueue();
    void enqueue(int item);
    int dequeue();
    void display();
    void peek();
    bool isFull();
    bool isEmpty();
    int noOfElements();
};