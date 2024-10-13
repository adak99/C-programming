#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int match(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow.\n");
        return;
    }
    ptr->arr[++ptr->top] = val;
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow.\n");
        return '\0';
    }
    return ptr->arr[ptr->top--];
}

int perenthisiMatching(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                printf("Stack underflow.\n");
                free(sp->arr);
                free(sp);
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                free(sp->arr);
                free(sp);
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        free(sp->arr);
        free(sp);
        return 1;
    }
    else
    {
        free(sp->arr);
        free(sp);
        return 0;
    }
}

int main()
{
    char *exp = "{a+b}*[(8-1)+(8-1)]";

    if (perenthisiMatching(exp))
    {
        printf("Parentheses are matching.\n");
    }
    else
    {
        printf("Parentheses are not matching.\n");
    }

    return 0;
}
