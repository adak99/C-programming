#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;
    int len = 0;

    printf("Enter a String: ");
    scanf("%s", str);

    while (str[len] != 0)
    {
        len++;
    }

    printf("Reverse string: ");

    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}