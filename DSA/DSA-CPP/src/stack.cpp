#include <stack.hpp>

Stack::Stack(int size)
{
    this->size = size;
    this->top = -1;
    this->stack = std::vector<int>(size);
}

Stack::~Stack()
{
}

void Stack::push(int item)
{
    if (isFull())
    {
        std::cout << "Stack is full" << std::endl;
    }
    else
    {
        stack[++top] = item;
    }
}

int Stack::pop()
{
    int item = -1;
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        item = stack[top];
        stack[top--] = 0;
    }
    return item;
}

bool Stack::isFull()
{
    return top == size - 1;
}

bool Stack::isEmpty()
{
    return top == -1;
}

void Stack::display()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::seek()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "The top element is " << stack[top] << std::endl;
    }
}

int Stack::noOfElements()
{
    return top + 1;
}

void Stack::displayTop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "The top element is " << stack[top] << std::endl;
    }
}
