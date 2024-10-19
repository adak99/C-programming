#include <stdio.h>

void conqure(int arr[], int strIdx, int endIdx)
{
    int mid = strIdx + (endIdx - strIdx) / 2;
    int newArr[endIdx - strIdx + 1];

    int i = strIdx;  // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = 0;       // Index for newArr

    while (i <= mid && j <= endIdx)
    {
        if (arr[i] < arr[j])
        {
            newArr[k++] = arr[i++];
        }
        else
        {
            newArr[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        newArr[k++] = arr[i++];
    }

    while (j <= endIdx)
    {
        newArr[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++)
    {
        arr[strIdx + i] = newArr[i];
    }
}

void divided(int arr[], int strIdx, int endIdx)
{
    if (strIdx >= endIdx)
    {
        return;
    }

    int mid = strIdx + (endIdx - strIdx) / 2;

    divided(arr, strIdx, mid);
    divided(arr, mid + 1, endIdx);

    conqure(arr, strIdx, endIdx);
}

int main()
{
    int arr[] = {4, 5, 3, 1, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    divided(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
