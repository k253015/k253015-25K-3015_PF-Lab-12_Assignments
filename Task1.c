#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, o, p;

    printf("Enter dimensions of matrix A (m n): ");
    scanf("%d %d", &m, &n);

    printf("\nEnter dimensions of matrix B (n p): ");
    scanf("%d %d", &o, &p);

    if (n <= 0 || m <= 0 || p <= 0 || o <= 0 || n != o)
    {
        printf("Invalid Input!\n");
        return 1;
    }

    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    int **B = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        B[i] = (int *)malloc(p * sizeof(int));

    int C[m][p];

    printf("\nEnter elements of matrix A:");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of matrix B:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("\n[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix C (A x B):\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
        free(A[i]);
    free(A);

    for (int i = 0; i < n; i++)
        free(B[i]);
    free(B);

    return 0;
}