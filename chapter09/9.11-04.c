#include <stdio.h>

double harmean(double x, double y);

int main(void)
{
    double a, b;

    printf("Please enter two numbers (q to quit): ");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("The harmonic mean of %g and %g is %g\n", a, b, harmean(a, b));
        printf("You can enter two numbers again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

double harmean(double x, double y)
{
    return 2 / (1 / x + 1 / y);
}
