#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int *arr;
    int top;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack overflow: %d can't be pushed.\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Inserted %d into the stack.\n", value);
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow.\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void getData(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: \n");
        for (int i = ptr->top; i >= 0; i--)
        {
            printf("%d\n", ptr->arr[i]);
        }
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int choice, value;

    while (1)
    {
        printf("Menu:\n");
        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Display.\n");
        printf("4. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter your data: ");
            scanf("%d", &value);
            push(s, value);
            break;
        case 2:
            value = pop(s);
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            getData(s);
            break;
        case 4:
            printf("Exiting program.\n");
            free(s->arr);
            free(s);
            return 0;
        default:
            printf("Enter a valid choice.\n");
            break;
        }
    }
    return 0;
}
