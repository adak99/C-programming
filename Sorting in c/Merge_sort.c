#include <stdio.h>
#include <stdlib.h>

int *conqure(int *left, int *right, int leftIdx, int rightIdx)
{
    int *newArr = (int *)malloc((leftIdx + rightIdx) * sizeof(int));

    int i, j, k;
    i = j = k = 0;

    while (i < leftIdx && j < rightIdx)
    {
        if (left[i] < right[j])
            newArr[k++] = left[i++];
        else
            newArr[k++] = right[j++];
    }

    while (i < leftIdx)
        newArr[k++] = left[i++];

    while (j < rightIdx)
        newArr[k++] = right[j++];

    return newArr;
}

int *divided(int *arr, int size)
{
    if (size == 1)
    {
        int *baseArr = (int *)malloc(size * sizeof(int));
        baseArr[0] = arr[0];
        return baseArr;
    }

    int mid = size / 2;

    int *left = divided(arr, mid);
    int *righ = divided(arr + mid, size - mid);

    int *result = conqure(left, righ, mid, size - mid);

    free(left);
    free(righ);

    return result;
}

int main()
{
    int arr[] = {4, 5, 3, 1, 6, 2}; // array
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ans = divided(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", ans[i]);
    }

    free(ans);

    return 0;
}