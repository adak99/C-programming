// find the largest elemetn in array

#include <stdio.h>
#include <stdlib.h>

void findLargestElement(int size)
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

    int largestElement = arr[size - 1];
    printf("The smallest element of the array is: %d", largestElement);

    free(arr);
}

int main()
{
    int size;

    printf("Enter the size of the arrya: ");
    scanf("%d", &size);

    findLargestElement(size);
    return 0;
}