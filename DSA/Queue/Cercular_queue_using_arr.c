#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *arr;
    int size;
    int front;
    int rear;
} queue;

// Initialize the queue
void initQueue(queue *q, int n)
{
    q->arr = (int *)malloc(n * sizeof(int));
    q->size = n;
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(queue *q) { return q->rear == -1 && q->front == -1; }

bool isFull(queue *q) { return (q->rear + 1) % q->size == q->front; }

void enqueue(queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;
}

// Dequeue operation
int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int result = q->arr[q->front];

    if (q->rear == q->front)
    {
        q->rear = q->front = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return result;
}

int peek(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    return q->arr[q->front];
}

void freeMemory(queue *q)
{
    if (q != NULL && q->arr != NULL)
    {
        free(q->arr);
        q->arr = NULL;
    }
}

int main()
{
    queue q;
    initQueue(&q, 3);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Peek-> %d\n", peek(&q));
    printf("Dequeue-> %d\n", dequeue(&q));
    printf("Display-> \n");
    while (!isEmpty(&q))
    {
        printf("%d\n", peek(&q));
        dequeue(&q);
    }

    freeMemory(&q);

    return 0;
}
