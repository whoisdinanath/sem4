#include <stdio.h>
#define MAXN 100
#define ORDER 4

void table_header()
{
    printf("-----------------------------------------\n");
}

int main()
{
    // float ax[MAXN + 1], ay[MAXN + 1];
    float diff[MAXN + 1][ORDER + 1], nr = 1.0, dr = 1.0, x, p, h, yp;
    int n = 7, i, j, k;
    // printf("\nEnter the value of n:\n");
    // scanf("%d", &n);

    // printf("\nEnter the values in form x,y:\n");
    // for (i = 0; i < n; i++)
    //     scanf("%f %f", &ax[i], &ay[i]);

    float ax[7] = {100, 150, 200, 250, 300, 350, 400};
    float ay[7] = {10.63, 13.03, 15.04, 16.81, 18.42, 19.90, 21.27};
    printf("\nEnter the value of x for which the value of y is wanted: \n");
    scanf("%f", &x);
    h = ax[1] - ax[0];

    // now making the difference table
    // calculating the 1st order of differences
    for (i = 0; i <= n - 1; i++)
        diff[i][1] = ay[i + 1] - ay[i];

    // now calculating the second and higher order differences
    for (j = 2; j <= ORDER; j++)
        for (i = 0; i <= n - j; i++)
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

    // now finding x0
    i = 0;
    while (!(ax[i] > x))
        i++;

    // now ax[i] is x0 and ay[i] is y0
    i--;
    p = (x - ax[i]) / h;
    yp = ay[i];

    // now carrying out interpolation
    for (k = 1; k <= ORDER; k++)
    {
        nr *= p - k + 1;
        dr *= k;
        yp += (nr / dr) * diff[i][k];
    }
    printf("\nWhen x = %6.1f, corresponding y = %6.2f\n", x, yp);
    return 0;
}