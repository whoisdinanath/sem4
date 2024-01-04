#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list
{
    int data;
    struct list *next;
} node;

node *head = NULL;

void insert_beg(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int size()
{
    int max_size = 0;
    node *temp = head;
    if (head != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            max_size++;
        }
    }
    return max_size;
}
void insert_spec(int data, int pos)
{
    int size_of_list = size();
    if (pos > size_of_list)
    {
        printf("Index out of range..\n");
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_end(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_end()
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(int data)
{
    node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("not found\n");
}

// insert_beg
// insert_spec
// delete_end
// display
// search
// exit

int main()
{
    int data, choice, pos;
    while (1)
    {
        printf("1. Insert at beginning.\n2. Insert at spcified position.\n3. Delete at end.\n4. Display all elements.\n5. Search a data\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data that you're inserting: ");
            scanf("%d", &data);
            insert_beg(data);
            break;

        case 2:
            printf("Enter the data and position where you're inserting: ");
            scanf("%d%d", &data, &pos);
            insert_spec(data, pos);
            break;

        case 3:
            delete_end();
            printf("Data at the end was successfully deleted\n");
            break;

        case 4:
            display();
            break;
        case 5:
            printf("Enter the data that you want to find: ");
            scanf("%d", &data);
            search(data);
            break;
        case 6:
            printf("Program exitting successfully...");
            exit(0);
        default:
            printf("It is a invalid choice, please choose the option correctly!\n");
        }
    }
    return 0;
}