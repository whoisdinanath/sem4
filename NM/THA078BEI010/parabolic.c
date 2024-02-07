#include <stdio.h>

#define N 3 // Number of data points

void parabolic_curve_fit(int n, double x[], double y[])
{
    double x_sum = 0, y_sum = 0, x2_sum = 0, x3_sum = 0, x4_sum = 0, xy_sum = 0, x2y_sum = 0;
    double a, b, c, det;

    for (int i = 0; i < n; i++)
    {
        x_sum += x[i];
        y_sum += y[i];
        x2_sum += x[i] * x[i];
        x3_sum += x[i] * x[i] * x[i];
        x4_sum += x[i] * x[i] * x[i] * x[i];
        xy_sum += x[i] * y[i];
        x2y_sum += x[i] * x[i] * y[i];
    }

    double A[3][4] = {
        {n, x_sum, x2_sum, y_sum},
        {x_sum, x2_sum, x3_sum, xy_sum},
        {x2_sum, x3_sum, x4_sum, x2y_sum}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            double ratio = A[j][i] / A[i][i];

            for (int k = 0; k < 4; k++)
            {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    c = A[2][3] / A[2][2];
    b = (A[1][3] - A[1][2] * c) / A[1][1];
    a = (A[0][3] - A[0][2] * c - A[0][1] * b) / A[0][0];

    printf("The fitted parabolic curve is: y = %.2fx^2 + %.2fx + %.2f\n", c, b, a);
}

int main()
{
    double x[N] = {0, 1, 2};
    double y[N] = {1, 6, 17};

    // print the data points
    printf("The data points are:\n");

    for (int i = 0; i < N; i++)
    {
        printf("(%.2f, %.2f)\n", x[i], y[i]);
    }

    parabolic_curve_fit(N, x, y);

    return 0;
}