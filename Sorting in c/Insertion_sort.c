#include <stdio.h>

int main()
{
    int arr[] = {4, 5, 3, 1, 6, 2};          // array
    int size = sizeof(arr) / sizeof(arr[0]); // size of the array
    // print array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); // use for clear output
}