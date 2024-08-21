#include <stdio.h>

void towDarray(int M, int N)
{
    int matrix[M][N];

    // Input elements for the matrix
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("Matrix elements:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int M, N;

    printf("Enter the number of rows (M): ");
    scanf("%d", &M);

    printf("Enter the number of columns (N): ");
    scanf("%d", &N);

    towDarray(M, N);

    return 0;
}
