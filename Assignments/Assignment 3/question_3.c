#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct stack
{
    int top;
    char arr[max];
};

void push(struct stack *s, char ch)
{
    if (s->top == max - 1)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = ch;
    }
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow.\n");
        return '\0';
    }
    else
    {
        return s->arr[s->top--];
    }
}

void reverseString(char str[])
{
    struct stack s;

    for (int i = 0; i < strlen(str); i++)
    {
        push(&s, str[i]);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = pop(&s);
    }
}

int main()
{
    char str[max];

    printf("Enter a string: ");
    fgets(str, max, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Original String: %s\n", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
