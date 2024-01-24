#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Adjust this value based on your maximum size

void printMatrix(int n, double matrix[MAX_SIZE][MAX_SIZE + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void forwardElimination(int n, double matrix[MAX_SIZE][MAX_SIZE + 1])
{
    for (int k = 0; k < n; k++)
    {
        // Pivot element
        double pivot = matrix[k][k];

        // Check if pivot is zero
        if (pivot == 0)
        {
            // Find a row with non-zero element in the same column
            int swapRow = -1;
            for (int i = k + 1; i < n; i++)
            {
                if (matrix[i][k] != 0)
                {
                    swapRow = i;
                    break;
                }
            }

            // If no such row exists, the matrix is singular
            if (swapRow == -1)
            {
                printf("The system has no unique solution.\n");
                return;
            }

            // Swap rows
            for (int j = 0; j < n + 1; j++)
            {
                double temp = matrix[k][j];
                matrix[k][j] = matrix[swapRow][j];
                matrix[swapRow][j] = temp;
            }

            // Update pivot
            pivot = matrix[k][k];
        }

        // Elimination
        for (int i = k + 1; i < n; i++)
        {
            double factor = matrix[i][k] / pivot;
            for (int j = k; j < n + 1; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }
}

// void backSubstitution(int n, double matrix[MAX_SIZE][MAX_SIZE + 1], double solution[MAX_SIZE]) {
//     for (int i = n - 1; i >= 0; i--) {
//         solution[i] = matrix[i][n];
//         for (int j = i + 1; j < n; j++) {
//             solution[i] -= matrix[i][j] * solution[j];
//         }
//         solution[i] /= matrix[i][i];
//     }
// }

void backSubstitution(int n, double matrix[MAX_SIZE][MAX_SIZE + 1], double solution[MAX_SIZE])
{
    for (int i = n - 1; i >= 0; i--)
    {
        // Check if the row is all zeros
        bool allZeros = true;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                allZeros = false;
                break;
            }
        }

        // If the row is all zeros
        if (allZeros)
        {
            // If the last element is also zero, then there are infinite solutions
            if (matrix[i][n] == 0)
            {
                printf("The system has infinite solutions.\n");
                return;
            }
            // If the last element is not zero, then there is no solution
            else
            {
                printf("The system has no solution.\n");
                return;
            }
        }

        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // If we reach here, then the system has a unique solution
    printf("The system has a unique solution.\n");
}

int main()
{
    int n;

    // Uncomment one of the following blocks based on your input method

    // Manual input of coefficients

    // printf("Enter the number of variables : ");
    // scanf("%d", &n);

    // double matrix[MAX_SIZE][MAX_SIZE + 1];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter coefficients for equation %d (separated by space) : ", i + 1);
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         scanf("%lf", &matrix[i][j]);
    //     }
    // }

    // Hard-coded coefficients
    n = 3; // Change this to the desired number of variables
    double matrix[MAX_SIZE][MAX_SIZE + 1] = {
        {-5, 9, 0, 3},
        {1, 0, 1, 1},
        {0, 2, 1, 2}};

    printf("Original augmented matrix:\n");
    printMatrix(n, matrix);

    forwardElimination(n, matrix);

    printf("Augmented matrix after forward elimination:\n");
    printMatrix(n, matrix);

    double solution[MAX_SIZE];
    backSubstitution(n, matrix, solution);

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }

    return 0;
}
