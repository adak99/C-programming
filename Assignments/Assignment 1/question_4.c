#include <stdio.h>

// Function to demonstrate Call by Value
void callByValue(int a)
{
    a = a + 10;
    printf("Inside callByValue, value of a: %d\n", a);
}

// Function to demonstrate Call by Reference
void callByReference(int *b)
{
    *b = *b + 10;
    printf("Inside callByReference, value of b: %d\n", *b);
}

int main()
{
    int x = 5;
    int y = 5;

    printf("Before callByValue, value of x: %d\n", x);
    callByValue(x);
    printf("After callByValue, value of x: %d\n\n", x);

    printf("Before callByReference, value of y: %d\n", y);
    callByReference(&y);
    printf("After callByReference, value of y: %d\n", y);

    return 0;
}
