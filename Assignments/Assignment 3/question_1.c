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

int isEmpty() { return (s->top == -1); }
int isFull() { return (s->top == s->size - 1); }

void push(int val) // push function to add items in a stack
{
    if (isFull())
    {
        printf("Stack is full.\n");
        return;
    }

    s->arr[++s->top] = val;
    printf("Push value-> %d\n", val);
}

int pop() // pop function to delete items in a stack
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }

    int val = s->arr[s->top--];
    return val;
}

int peek() // peek function to use peek a items in a stack
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return s->arr[s->top];
}

void display()
{
    if (isEmpty())
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
    int n, ch, val;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    initStack(n);

    while (1)
    {
        printf("\n1.Push.\n2.Pop.\n3.Peek.\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter push element: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            printf("Pop element: %d\n", pop(&s));
            break;
        case 3:
            for (int i = 1; i <= s->top + 1; i++)
            {
                printf("Position-> %d -> %d\n", s->top - i + 1, peek(&s, i));
            }
            break;
        case 4:
            printf("Exit....\n");
            freeStack();
            return 0;
        default:
            printf("Invalid choice !!!!.");
            break;
        }
    }
}

/*output

Enter the size of the stack: 3

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 10
Push value-> 10

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 20
Push value-> 20

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 30
Push value-> 30

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 3
Peek element: 30

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 2
Pop element: 30

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 3
Peek element: 20

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 4
Exit....

*/