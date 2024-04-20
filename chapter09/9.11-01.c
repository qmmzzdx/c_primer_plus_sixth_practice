#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double a, b;

    printf("Please enter two numbers (q to quit): ");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("Minimum: %g\n", min(a, b));
        printf("You can enter again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

double min(double x, double y)
{
    return x < y ? x : y;
}
