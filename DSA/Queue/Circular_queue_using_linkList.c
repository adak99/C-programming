#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNode(int newData)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

node *front = NULL;
node *rear = NULL;

int isEmpty() { return rear == NULL && front == NULL; }

void enqueue(int data)
{
    node *newNode = createNode(data);
    if (isEmpty())
    {
        front = rear = newNode;
        rear->next = front;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty.");
        return -1;
    }

    int result = front->data;

    if (rear == front)
    {
        rear = front = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    return result;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty.");
        return -1;
    }

    return front->data;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.");
        return;
    }

    node *currentNode = front;
    do
    {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != front);
}

void freeMemory()
{
    if (isEmpty())
        return;

    node *currNode = front;
    do
    {
        node *temp = currNode;
        currNode = currNode->next;
        free(temp);
    } while (currNode != front);
    front = rear = NULL;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("Peek-> %d\n", peek());
    printf("Dequeue-> %d\n", dequeue());
    printf("Display-> \n");
    display();
    freeMemory();
    return 0;
}