#include <stdio.h>

int main()
{
    int arr[] = {4, 5, 3, 1, 6, 2};          // array
    int size = sizeof(arr) / sizeof(arr[0]); // size of the array

    // Bubble sort
    for (int i = 0; i < size; i++) // outer loop
    {
        for (int j = 0; j < size - i - 1; j++) // iner loop
        {
            if (arr[j] < arr[j + 1]) // arr j element is less then arr j + 1 element
            {
                // swaping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); // use for clear output

    return 0;
}