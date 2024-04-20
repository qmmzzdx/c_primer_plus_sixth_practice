#include <stdio.h>

void test(double *a, double *b, double *c);

int main(void)
{
    double x, y, z;

    printf("Please enter three numbers (q to quit): ");
    while (scanf("%lf %lf %lf", &x, &y, &z) == 3)
    {
        test(&x, &y, &z);
        printf("Min: %g\n", x);
        printf("Middle: %g\n", y);
        printf("Max: %g\n", z);
        printf("You can enter three numbers again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void test(double *a, double *b, double *c)
{
    double tp;

    if (*a > *b)
    {
        tp = *a;
        *a = *b;
        *b = tp;
    }
    if (*a > *c)
    {
        tp = *a;
        *a = *c;
        *c = tp;
    }
    if (*b > *c)
    {
        tp = *b;
        *b = *c;
        *c = tp;
    }
    return;
}
