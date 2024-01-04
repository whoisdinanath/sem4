#include <iostream>
#include <vector>

class Stack
{
private:
    std::vector<int> stack;
    int top;
    int size;

public:
    Stack(int size);
    ~Stack();
    void push(int item);
    int pop();
    bool isFull();
    bool isEmpty();
    void display();
    void seek();
    int noOfElements();
    void displayTop();
};
