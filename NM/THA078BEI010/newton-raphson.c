#include <stdio.h>
#include <math.h>

#define f(x) (pow(x,3) - 3*pow(x,2) + 2*x + 5)

void line(){
    printf("\n_________________________________________\n");
}

void main(){
    float a, b, c, ERROR;
    int N;

    INPUT:
    printf("Enter the inerval: ");
    scanf("%f %f", &a, &b);
    printf("%lf %lf\n",(double)f(a),(double)f(b));
    printf("%lf\n", (double)f(a)*(double)f(b));
    if(f(a) * f(b) > 0){
        printf("There are no solutions in the interval (%d, %d)\n\n", (int)a, (int)b);
        goto INPUT;
    }
    printf("Enter number of iterations: ");
    scanf("%d", &N);
    printf("Enter maximum error: ");
    scanf("%f", &ERROR);


    int i = 1;

    line();
    printf("a\t\tb\t\tc\t\tf(c)\n");
    line();

    while(i <= N){
        c = (a + b) / 2;
        if(f(c) == 0 || fabs(f(c)) <= ERROR){
            break;
        }
        
        printf("%f\t\t%f\t\t%f\t\t%f\n", a, b, c, f(c));
        
        if(f(c) > 0){
            b = c;
        }
        else{
            a = c;
        }
        i++;
    }

    line();
}

