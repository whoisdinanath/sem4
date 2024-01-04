#include "lab2.hpp"

void lab2_linear()
{
    // menu driven program
    int choice, item;
    Queue queue(5);
    while (1)
    {
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Display Front" << std::endl;
        std::cout << "5. No of elements" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the element: ";
            std::cin >> item;
            queue.enqueue(item);
            break;
        case 2:
            item = queue.dequeue();
            if (item != -1)
            {
                std::cout << "Dequeued element is: " << item << std::endl;
            }
            break;
        case 3:
            queue.display();
            break;
        case 4:
            queue.displayFront();
            break;
        case 5:
            std::cout << "No of elements in queue is: " << queue.noOfElements() << std::endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
    return;
}

void lab2_circular()
{
    // menu driven program
    int choice, item;
    CircularQueue queue(5);
    while (1)
    {
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Peek" << std::endl;
        std::cout << "5. No of elements" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the element: ";
            std::cin >> item;
            queue.enqueue(item);
            break;
        case 2:
            item = queue.dequeue();
            if (item != -1)
            {
                std::cout << "Dequeued element is: " << item << std::endl;
            }
            break;
        case 3:
            queue.display();
            break;
        case 4:
            queue.peek();
            break;
        case 5:
            std::cout << "No of elements in queue is: " << queue.noOfElements() << std::endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    return;
}