#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int size;
    int top;
} stack;

stack *s; // set as a global

void initStack(int n) // init stack
{
    s = (stack *)malloc(sizeof(stack));
    s->arr = (int *)malloc(n * sizeof(int));
    s->size = n;
    s->top = -1;
}

void push(int val) // push function to add items in a stack
{
    if (s->top == s->size - 1)
    {
        printf("Stack is full.\n");
        return;
    }

    s->arr[++s->top] = val;
    printf("Push value-> %d\n", val);
}

int pop() // pop function to delete items in a stack
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    int val = s->arr[s->top--];
    return val;
}

int peek() // peek function to use peek a items in a stack
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return s->arr[s->top];
}

void display()
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}

void freeStack() // free memory allocations
{
    if (s != NULL)
    {
        free(s->arr);
        free(s);
    }
}

int main()
{
    initStack(3);

    push(10);
    push(20);
    push(30);
    push(40);

    printf("Pop element-> %d\n", pop());

    printf("Display->\n");
    display();

    printf("Peek-> %d\n", peek());

    freeStack();

    return 0;
}