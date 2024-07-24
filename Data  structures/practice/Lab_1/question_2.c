// C program for Reading and printing Array Elements

#include <stdio.h>
#include <stdlib.h>

void printArrayElements(int size)
{
    int *arr = (int *)malloc(size * sizeof(int)); // allocated memory address

    if (arr == NULL)
    {
        printf("ERROR! array is null");
        exit(0);
    }

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray Elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printArrayElements(size);

    return 0;
}