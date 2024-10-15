#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    char str[20];
};

void push(struct stack *ptr, char ch)
{
    if (ptr->top == sizeof(ptr->str) - 1)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        ptr->str[++ptr->top] = ch;
    }
}

char pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack underflow.\n");
        return '\0';
    }
    else
    {
        return ptr->str[ptr->top--];
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    char str[100];
    char ch;

    printf("Enter a String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; i < strlen(str); i++)
    {
        push(&s, str[i]);
    }

    printf("Reversed string: ");
    while (s.top != -1)
    {
        ch = pop(&s);
        if (ch != '\0')
        {
            printf("%c", ch);
        }
    }

    printf("\n");
    return 0;
}
