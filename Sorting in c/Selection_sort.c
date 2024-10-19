#include <stdio.h>

int main()
{
    int arr[] = {4, 5, 3, 1, 6, 2};          // array
    int size = sizeof(arr) / sizeof(arr[0]); // size of the array

    for (int i = 0; i < size - 1; i++) // outer loop
    {
        int smallest = i; // set a smallest element

        for (int j = i + 1; j < size; j++) // iner loop
        {
            // check if the smallest element gretter then arr[j]-th element then the smallest element
            // convert to the j-th element ->(smallest = j)
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }

        // after finding the smallest element then swaping the elements
        // swaping
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }

    // print array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); // use for clear output
}