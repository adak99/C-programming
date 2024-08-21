#include <stdio.h>

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if (b != 0)
        return a / b;
    else
        printf("Error");
}

int main()
{
    int a, b;
    printf("Enter the vlaue 1: ");
    scanf("%d", &a);
    printf("Enter the value 2: ");
    scanf("%d", &b);

    printf("Addition of %d + %d =  %d \n", a, b, addition(a, b));
    printf("Subtraction of %d - %d = %d\n", a, b, subtraction(a, b));
    printf("Multiplication of %d * %d = %d\n", a, b, multiplication(a, b));
    printf("Division of %d / %d = %d\n", a, b, division(a, b));

    return 0;
}