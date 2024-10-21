#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNode(int new_data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = new_data;
    newNode->next = NULL;
}

node *head = NULL;
int size = 0;

// insert at beginning
void addFirst(int data)
{
    node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        size++;
        return;
    }

    newNode->next = head;
    head = newNode;
    size++;
}

// insert at last
void addLast(int data) // addLast
{
    node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        size++;
        return;
    }

    node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    size++;
}

// insert at position
void addAtpos(int data, int pos)
{
    node *newNode = createNode(data);

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        size++;
        printf("%d will be added at position %d\n", data, pos);
        return;
    }

    if (pos > size + 1 || pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    node *currNode = head;

    for (int i = 1; i < pos - 1; i++)
    {
        currNode = currNode->next;
    }

    newNode->next = currNode->next;
    currNode->next = newNode;
    size++;
    printf("%d will be added at position %d\n", data, pos);
}

// Delete at beginning
void deleteFirst()
{
    if (head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }
    size--;
    head = head->next;
}

// delete at end
void deleteLast()
{
    if (head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }

    size--;
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    node *secondLast = head;
    node *lastNode = head->next;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
        secondLast = secondLast->next;
    }
    secondLast->next = NULL;
}

// delete at pos
void deleteAtpos(int pos)
{
    if (head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }

    if (pos < 1 || pos > size)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        size--;
        printf("Node at position %d has been deleted.\n", pos);
        return;
    }

    node *currNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        currNode = currNode->next;
    }

    node *temp = currNode->next;
    currNode->next = temp->next;
    size--;
    printf("Node at position %d has been deleted.\n", pos);
}

// display list
void printList()
{
    if (head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }

    node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
    printf("Total size of the linked list is: %d", size);
    printf("\n");
}

int main()
{

    addFirst(1);
    addAtpos(30, 1);
    addAtpos(10, 2);
    addAtpos(20, 4);
    addAtpos(9, 3);
    addLast(3);

    printList();
    deleteAtpos(2);

    return 0;
}

/*
output->

30 will be added at position 1
10 will be added at position 2
20 will be added at position 4
9 will be added at position 3
3 will be added at the end
30 10 9 1 20 3
Total size of the linked list is: 6
Node at position 2 has been deleted.
*/