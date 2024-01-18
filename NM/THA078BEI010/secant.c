#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define f(x) (x * x * x - 2 * x - 5);

void printHeader()
{
    printf("_______________________________________________________________________________\n");
}

void main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;
    printf("Enter initial guesses x1 and x2: ");
    scanf("%f%f", &x1, &x2);
    printf("Enter the maximum tolerance: ");
    scanf("%f", &e);
    printf("Enter the maximum number of iteration: ");
    scanf("%d", &N);

    printHeader();
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf{x2}\n");
    printHeader();
    do
    {
        f0 = f(x0);
        f1 = f(x1);

        if (f0 == f1)
        {
            printf("Math Error!\n");
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);
        printf("\t%d\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step++;
        if (step > N)
        {
            printf("Not convergent.\n");
            exit(0);
        }

    } while (fabs(f2) > e);
    printHeader();
    printf("\nRoot is: %.8f\n", x2);
}