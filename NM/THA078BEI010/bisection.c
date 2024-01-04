#include <stdio.h>
#include <math.h>

void table_separator()
{
    printf("_________________________________________________________________________\n");
}

void table_header()
{
    printf("Iterations\tX_0\t\tX_1\t\tX_2\t\tf(x_2)\n");
}

void iteration(int i, double x_0, double x_1, double x_2, double f2)
{
    printf("  %d\t\t%f\t%f\t%f\t%f\n", i, x_0, x_1, x_2, f2);
}

double func(double x)
{
    return x * sin(x) - 1;
}

double bisection(double a, double b, double epsilon)
{
    if (func(a) * func(b) >= 0)
    {
        printf("Invalid input: Function values at endpoints must have opposite signs\n");
        return -1;
    }

    int i;
    double c;
    while ((b - a) >= epsilon)
    {
        iteration(i, a, b, c, func(c));

        c = (a + b) / 2;

        if (func(c) == 0.0)
        {
            printf("Root found at %.8lf\n", c);
            return c;
        }
        else if (func(c) * func(a) < 0)
        {

            b = c;
        }
        else
        {
            a = c;
        }
    }

    printf("Approximate root found at %lf\n", c);
    return c;
}

int main()
{
    double x_0, x_1, x_2, e;
    printf("Enter the initial guesses, x_0 and x_2: ");
    scanf("%lf%lf", &x_0, &x_1);
    printf("Enter the predefined error, e: ");
    scanf("%lf", &e);
    table_separator();
    table_header();
    table_separator();
    x_2 = bisection(x_0, x_1, e);

    return 0;
}