// reverse all array element

#include <stdio.h>
#include <stdlib.h>
void reverseArrayElement(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter %d array elements: ", size); // Corrected typo from "arraya"
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Reverse array element and print
    printf("\nReversed array: ");
    for (int i = size - 1; i >= 0; i--) // Start from the last element
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    reverseArrayElement(size);

    return 0;
}
