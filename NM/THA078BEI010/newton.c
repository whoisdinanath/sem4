#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x)
{
    return x * log10(x) - 1.2;
}

float func_der(float x)
{
    return log10(2.71) * (1 + log(x));
}

void newton_raphson(float *initial)
{
    *initial = *initial - (func(*initial) / func_der(*initial));
}

int main()
{
    int i = 1, MAXITR;
    float initial, x_0, f_0, EPSILON;
    printf("Enter the initial guess: ");
    scanf("%f", &initial);
    printf("Enter the maximum allowable error: ");
    scanf("%f", &EPSILON);
    printf("Enter the maximun iteration: ");
    scanf("%d", &MAXITR);
    printf("____________________________________________________________________________________\n");
    printf("\tIteration\tX_0\t\tfX_0\t\tX_1\t\tfX_1\n");
    printf("____________________________________________________________________________________\n");
    // newton_raphson(&initial);
    while (fabs(func(initial)) > EPSILON)
    {

        f_0 = func(initial);

        x_0 = initial;
        if (func_der(initial) == 0)
        {
            printf("Mathematical error!\n");
        }
        newton_raphson(&initial);

        if (i > MAXITR)
        {
            printf("Solution doesnot converge\n");
            return 0;
        }
        // printf("Current value: %.4f", initial);
        printf("\t   %d \t\t%f  \t%f  \t%f  \t%f\n", i, x_0, f_0, initial, func(initial));
        i++;
    }
    printf("____________________________________________________________________________________\n");
    printf("The approximate solution is: %.8f\n", initial);
    return 0;
}
