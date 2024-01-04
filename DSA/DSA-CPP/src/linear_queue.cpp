#include <linear_queue.hpp>

Queue::Queue(int size)
{
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->queue = std::vector<int>(size);
}

Queue::~Queue()
{
}

void Queue::enqueue(int item)
{
    if (isFull())
    {
        std::cout << "Queue is full" << std::endl;
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}

int Queue::dequeue()
{
    int item = -1;
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
    }

    else
    {
        item = queue[front];
        queue[front] = 0;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    return item;
}

bool Queue::isFull()
{
    return rear == size - 1;
}

bool Queue::isEmpty()
{
    return front == -1 && rear == -1;
}

void Queue::display()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
}

int Queue::noOfElements()
{
    return rear - front + 1;
}

void Queue::displayFront()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << "Front element is: " << queue[front] << std::endl;
    }
}
