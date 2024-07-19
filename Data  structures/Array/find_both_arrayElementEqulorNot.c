#include <stdio.h>
#include <stdbool.h>

void calcaulte(int *a, int *b, bool *arrayEquals)
{
    int length = sizeof(a) / sizeof(a[0]);

    if (length != sizeof(b) / sizeof(b[0]))
    {
        arrayEquals = false;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (a[i] != b[i])
            {
                *arrayEquals = false;
                break;
            }
        }
    }

    if (*arrayEquals)
    {
        printf("Equl\n");
    }
    else
    {
        printf("NOT EQUAL\n");
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    bool arrayEquals = true;

    calcaulte(a, b, &arrayEquals);
    return 0;
}