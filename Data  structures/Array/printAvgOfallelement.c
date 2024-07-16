// print avg of total array element
#include <stdio.h>
#include <stdlib.h>

void clacualte(int size, int *ptr, int *sum, float *avg)
{
    ptr = (int *)malloc(size * sizeof(int)); // memeory allocation

    if (ptr == NULL)
    {
        printf("ERROR! memory allocation is empty.");
        exit(0);
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    // calculate sum
    for (int i = 0; i < size; i++)
    {
        *sum += ptr[i];
    }

    *avg = (float)(*sum) / size;

    printf("Avarage: %f", *avg);

    free(ptr);
}

int main()
{
    int size, *ptr, sum = 0;
    float avg = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid array size.");
        exit(0);
    }

    clacualte(size, ptr, &sum, &avg);

    return 0;
}