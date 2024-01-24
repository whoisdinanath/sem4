#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        printf("The tree is empty!\n");
    }
    if (root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = searchNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = searchNode(root->right, data);
    }
    return root;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printInOrder(Node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

void printPreOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
void printPostOrder(Node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->right);
        printPostOrder(root->left);
        printf("%d ", root->data);
    }
}

Node *findMin(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}

Node *findMax(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL)
    {
        return root;
    }
    else
    {
        return findMax(root->right);
    }
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *main = createNode(100);
    // write a menu based program for BST
    // 1. Insert
    // 2. Search
    // 3. Delete
    // 4. Print Inorder, Preorder, Postorder
    // 5. Exit

    int choice, data;
    Node *temp;

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Print Inorder, Preorder, Postorder\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            temp = insertNode(main, data);
            printf("\nInorder: ");
            printInOrder(main);
            printf("\nPostorder: ");
            printPostOrder(main);
            printf("\nPreorder: ");
            printPreOrder(main);
            break;
        case 2:
            printf("\nEnter the data to be searched: ");
            scanf("%d", &data);
            temp = searchNode(main, data);
            if (temp != NULL)
            {
                printf("\n%d found in the tree.\n", data);
            }
            else
            {
                printf("\n%d not found in the tree.\n", data);
            }

            break;
        case 3:
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &data);
            temp = deleteNode(main, data);
            printf("\nDeleted %d from the tree.\n", data);
            printf("\nInorder: ");
            printInOrder(main);
            printf("\nPostorder: ");
            printPostOrder(main);
            printf("\nPreorder: ");
            printPreOrder(main);
            break;
        case 4:
            printf("\nInorder: ");
            printInOrder(main);
            printf("\nPreorder: ");
            printPreOrder(main);
            printf("\nPostorder: ");
            printPostOrder(main);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
}
