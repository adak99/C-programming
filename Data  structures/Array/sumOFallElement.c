// sum of all array element using malloc function
#include <stdio.h>
#include <stdlib.h>

void calcualte(int size_Of_array, int *ptr, int sum)
{
    ptr = (int *)malloc(size_Of_array * sizeof(int)); // memory allocation

    if (ptr == NULL)
    {
        printf("ERROR! memory is empty");
    }

    printf("Enter the element of the array: ");
    for (int i = 0; i < size_Of_array; i++)
    {
        scanf("%d", &ptr[i]);
    }

    // sum all element
    for (int i = 0; i < size_Of_array; i++)
    {
        sum += ptr[i];
    }

    print("Sum = %d", sum);

    free(ptr);
}

int main()
{
    int size_Of_array, *ptr, sum = 0;

    print("Enter the size of the array: ");
    scanf("%d", &size_Of_array);

    if (size_Of_array != 1 || size_Of_array <= 0)
    {
        printf("Invalid array size.");
        exit(0);
    }

    calcualte(size_Of_array, ptr, sum);

    return 0;
}