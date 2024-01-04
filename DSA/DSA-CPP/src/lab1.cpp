#include <lab1.hpp>

void lab1_stack()
{
    // Menu driven program for stack operations
    // 1. Push
    // 2. Pop
    // 3. Display
    // 4. No of elements
    // 5. Seek
    // 6. Exit

    int choice, item;
    Stack stack(5);
    while (1)
    {
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. No of elements" << std::endl;
        std::cout << "5. Seek" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the element: ";
            std::cin >> item;
            stack.push(item);
            break;
        case 2:
            item = stack.pop();
            if (item != -1)
            {
                std::cout << "Popped element is: " << item << std::endl;
            }
            break;
        case 3:
            stack.display();
            break;
        case 4:
            std::cout << "No of elements in stack is: " << stack.noOfElements() << std::endl;
            break;
        case 5:
            stack.displayTop();
            break;
        case 6:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
}