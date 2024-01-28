#include <stdio.h>

#define MAX_SIZE 10 // Adjust this value based on your maximum size

void swapRows(double matrix[MAX_SIZE][MAX_SIZE + 1], int row1, int row2, int n)
{
    for (int i = 0; i <= n; i++)
    {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void gaussJordan(double matrix[MAX_SIZE][MAX_SIZE + 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0)
        {
            int rowToSwap = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (matrix[j][i] != 0)
                {
                    rowToSwap = j;
                    break;
                }
            }
            if (rowToSwap == -1)
            {
                printf("No unique solution exists.\n");
                return;
            }
            swapRows(matrix, i, rowToSwap, n);
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k <= n; k++)
                {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        double a = matrix[i][i];
        for (int j = 0; j <= n; j++)
        {
            matrix[i][j] /= a;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double matrix[MAX_SIZE][MAX_SIZE + 1];
    printf("Enter the augmented matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    gaussJordan(matrix, n);

    printf("The solutions are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}