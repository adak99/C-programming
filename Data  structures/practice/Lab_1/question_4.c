// find the smallest element of the array

#include <stdio.h>
#include <stdlib.h>

void findSmallestElement(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("ERROR ! memory is empty");
        exit(0);
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // sort the array
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int smallestElement = arr[0];
    printf("The smallest element of the array is: %d", smallestElement);

    free(arr);
}

int main()
{
    int size, sallestElement;

    printf("Enter the size of the arrya: ");
    scanf("%d", &size);

    findSmallestElement(size);
    return 0;
}