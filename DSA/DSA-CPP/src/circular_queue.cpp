#include <circular_queue.hpp>

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->queue = std::vector<int>(size);
}
CircularQueue::~CircularQueue()
{
}

void CircularQueue::enqueue(int item)
{
    if (isFull())
    {
        std::cout << "The queue is full" << std::endl;
    }
    else if (isEmpty())
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = (rear + 1) % size;
        queue[rear] = item;
    }
    else
    {
        queue[++rear] = item;
    }
    std::cout << std::endl;
    std::cout << "Front -> " << front << std::endl;
    std::cout << "Rear -> " << rear << std::endl;
    display();
    std::cout << std::endl;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty!";
    }
    int data = queue[front];
    queue[front] = -1;
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    std::cout << std::endl;
    std::cout << "Front -> " << front << std::endl;
    std::cout << "Rear -> " << rear << std::endl;
    display();
    std::cout << std::endl;
    return data;
}

bool CircularQueue::isEmpty()
{
    return front == -1;
}

bool CircularQueue::isFull()
{
    std::cout << "True" << std::endl;
    return ((front == 0 && rear == size - 1) || (front == rear + 1));
}

void CircularQueue::display()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        // display only the elements that are not -1 starting from front and ending at rear
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                std::cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                std::cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                std::cout << queue[i] << " ";
            }
        }

        std::cout << std::endl;
    }
}

int CircularQueue::noOfElements()
{
    // calcualte the number of elements in the circular queue
    if (isEmpty())
    {
        return 0;
    }
    else if (front <= rear)
    {
        return rear - front + 1;
    }
    else
    {
        return size - front + rear + 1;
    }
}

void CircularQueue::peek()
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
