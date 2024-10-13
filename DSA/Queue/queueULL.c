#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int data) // endqueue
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

int dequeue() // dequeue
{
    if (rear == NULL)
    {
        printf("This queue is empty.\n");
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
        printf("This queue is empty.\n");
        return -1;
    }

    return front->data;
}

void display() // display
{
    if (rear == NULL)
    {
        printf("This queue is empty.\n");
        return;
    }

    node *currentNode = front;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Delete data-> %d\n", dequeue());

    printf("Display data.\n");
    display();

    while (rear != NULL && front != NULL)
    {
        printf("\n%d", peek());
        dequeue();
    }

    return 0;
}