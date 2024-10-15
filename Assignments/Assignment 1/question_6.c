#include <stdio.h>

void add_matrix(int row, int col, int matrix1[][col], int matrix2[][col])
{
    int addMatrix[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            addMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Add matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", addMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row = 4;
    int col = 4;

    int matrix1[row][col];
    int matrix2[row][col];

    printf("Enter the elements of matrix 1: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    add_matrix(row, col, matrix1, matrix2);

    return 0;
}
