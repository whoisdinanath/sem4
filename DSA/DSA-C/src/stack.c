#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int data)
{
    if (top >= MAX - 1)
    {
        printf("stack overflow! can't push more than the #MAX size. \n");
    }
    else
    {
        stack[++top] = data;
    }
}

int pop()
{
    if (top <= -1)
    {
        printf("stack underflow! can't pop on the empty stack. \n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void display()
{
    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
    else
    {
        printf("stack is empty\n");
    }
}

int total_no_of_element()
{
    return top + 1;
}

int peek()
{
    if (top <= -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("Options:\n(1) to push\n(2) to pop\n(3) to display\n(4) total number of elements\n(5) to peek\n(6) to exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int data;
            printf("element to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            if (data != -1)
                printf("popped element is: %d\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("total number of elements: %d\n", total_no_of_element());
            break;
        case 5:
            data = peek();
            if (data != -1)
            {
                printf("top index is %d\n", top);
                printf("top element: %d\n", data);
            }
            break;
        case 6:
            return 0;
        default:
            printf("invalid choice...\n");
        }
    }
    return 0;
} // Roll no: THA078BEI010(Dinanath Padhya)