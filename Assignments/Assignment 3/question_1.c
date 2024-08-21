#include <stdio.h>
#include <stdlib.h>
#define max 4

struct stack
{
    int arr[max];
    int top;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == max - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Insertd %d into the stack.\n", value);
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underFlow! no elements to pop.\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

void getStackData(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is emplty.\n");
    }
    else
    {
        printf("Stack elements are: \n");
        int i;
        for (i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}

int main()
{
    struct stack s;
    s.top = -1;

    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert (push):\n");
        printf("2. Delete (pop):\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter teh value to be inserted:");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            value = pop(&s);
            if (value != 1)
            {
                printf("Popped vlaue: %d\n", value);
            }
            break;
        case 3:
            getStackData(&s);
            break;
        default:
            printf("Invlid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
