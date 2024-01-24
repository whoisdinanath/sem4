#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 10

void printMatrix(float *matrix, int m_rows, int m_cols)
{
    for (int i = 0; i < m_rows * m_cols; i++)
    {

        printf("%.2f ", matrix[i]);
        if ((i + 1) % m_cols == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    int m_rows, m_cols, i, j = 1, k = 1;
    float pivot, ratio;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m_rows, &m_cols);

    float *aug_mat = malloc((m_rows * m_cols) * sizeof(float));

    printf("Enter the values of augmented matrix: ");
    for (i = 0; i < m_rows * m_cols; i++)
    {
        printf("Enter the (%d, %d) element: ", j, k);
        scanf("%f", aug_mat + i);
        k++;
        if ((i + 1) % m_cols == 0)
        {
            k = 1;
            j++;
        }
    }
    for (i = 0, j = 0; i < m_rows * m_cols; i += m_cols, j++)
    {
        if (aug_mat[(i % m_cols + j) == 0])
        {
            printf("Pivot element can't be zero.");
            exit(1);
        }
    }

    for (i = 0; i < m_rows; i++)
    {
        pivot = aug_mat[i % m_cols + i];
        for (j = 0; j < m_cols; j++)
        {
            if (i > j)
            {
                ratio = aug_mat[i * m_cols + j] / pivot;
                for (k = i; k < m_cols; k++)
                {
                    aug_mat[j * m_cols + k] -= ratio * aug_mat[i]
                }
            }
        }
    }
    printMatrix(aug_mat, m_rows, m_cols);
    for (i = 0; i < m_rows * m_cols; i++)
    {
    }

    return 0;
}