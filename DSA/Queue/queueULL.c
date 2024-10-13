#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue()
{
    if (rear == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int frontVal = front->data;
    front = front->next;
    return frontVal;
}

int peek()
{
    if (rear == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    return front->data;
}

void display()
{
    if (rear == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    node *currentNode = front;
    while (currentNode != NULL)
    {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Display->\n");
    display();
    printf("Peek\n");

    while (rear != NULL)
    {
        printf("%d\n", peek());
        dequeue();
    }

    return 0;
}