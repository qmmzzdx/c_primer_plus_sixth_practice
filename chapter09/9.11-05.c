#include <stdio.h>

void larger_of(double *x, double *y);

int main(void)
{
    double a, b;

    printf("Please enter two numbers (q to quit): ");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        larger_of(&a, &b);
        printf("Results: %g and %g\n", a, b);
        printf("You can enter two numbers again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void larger_of(double *x, double *y)
{
    *x = *y = *x > *y ? *x : *y;
    return;
}
