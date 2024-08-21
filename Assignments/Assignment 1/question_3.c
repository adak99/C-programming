#include <stdio.h>

void printPrimeNumbers(int start, int end)
{
    int temp = 0;

    printf("Prime numbers: ");
    for (int i = start; i < end; i++)
    {
        temp = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                temp += 1;
                break;
            }
        }

        if (temp == 0)
        {
            if (i != 1)
                printf("%d ", i);
        }
    }
}

int main()
{
    int start = 1, end = 20;

    printPrimeNumbers(start, end);

    return 0;
}