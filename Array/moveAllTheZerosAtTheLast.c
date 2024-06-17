#include <stdio.h>
void calculateArray(int arr[], int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[n];
            arr[n] = arr[i];
            arr[i] = temp;
            n++;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 0, 3, 4, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    calculateArray(arr, size);

    printf("Move all the zeros at the last: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}