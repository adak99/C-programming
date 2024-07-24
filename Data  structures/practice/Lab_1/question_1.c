// C program to display array elements with addresses

#include <stdio.h>
#include <stdlib.h>

void printArrayWithAddresses(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Error! Memory allocation failed.\n");
        exit(0);
    }

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray Elements and Their Addresses:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Value: %d Address: %p\n", arr[i], &arr[i]);
    }

    free(arr);
}

int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    printArrayWithAddresses(size);

    return 0;
}
