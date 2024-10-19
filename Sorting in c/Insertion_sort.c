#include <stdio.h>

int main()
{
    int arr[] = {4, 5, 3, 1, 6, 2};          // array
    int size = sizeof(arr) / sizeof(arr[0]); // size of the array

    for (int i = 1; i < size; i++)
    {
        int currentElement = arr[i]; // set a current element
        int j = i - 1;               // set a j-th pointer to making the spaces

        // if j is 0 or j greeter then 0 and our current element is smaller then arr[j]-th element
        //  then the loop is running
        while (j >= 0 && currentElement < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = currentElement;
    }

    // print array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); // use for clear output
}