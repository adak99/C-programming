#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int *arr;
    int top;
    int size;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

bool isEmpty(Stack *s) { return s->top == -1; }

bool isFull(Stack *s) { return s->top == s->size - 1; }

void push(Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack overflow.\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top--];
}

typedef struct Queue
{
    Stack *s1;
    Stack *s2;
} Queue;

Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->s1 = createStack(size);
    queue->s2 = createStack(size);
    return queue;
}

bool isQueueEmpty(Queue *q) { return isEmpty(q->s1); }

void add(Queue *q, int data)
{
    if (isFull(q->s1))
    {
        printf("Queue overflow.\n");
        return;
    }

    while (!isEmpty(q->s1)) // Move all elements from s1 to s2
        push(q->s2, pop(q->s1));

    push(q->s1, data); // Push the new element into s1

    while (!isEmpty(q->s2)) // Move everything back to s1 from s2
        push(q->s1, pop(q->s2));
}

int removeQueue(Queue *q)
{
    if (isEmpty(q->s1))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return pop(q->s1);
}

int peekQueue(Queue *q)
{
    if (isEmpty(q->s1))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->s1->arr[q->s1->top];
}

void queueDisplay(Queue *q)
{
    if (isEmpty(q->s1))
    {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = q->s1->top; i >= 0; i--)
        printf("%d ", q->s1->arr[i]);

    printf("\n");
}

int main()
{
    Queue *q = createQueue(3);

    add(q, 10);
    add(q, 20);
    add(q, 30);
    add(q, 40);

    printf("Peek-> %d\n", peekQueue(q));

    printf("Remove-> %d\n", removeQueue(q));

    printf("Display->\n");
    queueDisplay(q);

    printf("Peek after remove-> %d\n", peekQueue(q));

    return 0;
}
