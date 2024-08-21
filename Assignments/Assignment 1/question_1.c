#include <stdio.h>

void printArr(int *a, int *b, int size_a, int size_b)
{
    int i;

    // print first array
    printf("\nFirst array elements: ");
    for (i = 0; i < size_a; i++)
    {
        printf("%d ", a[i]);
    }

    // print second array
    printf("\nSecond array elements: ");
    for (i = 0; i < size_b; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main()
{
    int size_a, size_b, i;

    printf("Enter the size of the first array: ");
    scanf("%d", &size_a);
    printf("Enter the size of the second array: ");
    scanf("%d", &size_b);

    int a[size_a];
    int b[size_b];

    // insert elements into the first array
    printf("\nEnter elements of the first array: ");
    for (i = 0; i < size_a; i++)
    {
        scanf("%d", &a[i]);
    }

    // insert elements into the second array
    printf("\nEnter elements of the second array: ");
    for (i = 0; i < size_b; i++)
    {
        scanf("%d", &b[i]);
    }

    printArr(a, b, size_a, size_b);

    return 0;
}
