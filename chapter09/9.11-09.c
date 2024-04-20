#include <stdio.h>

double power(double n, int p);

int main(void)
{
    double x, xpow;
    int exp;

    printf("Enter a number and the integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g.\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double power(double n, int p)
{
    double pow = 1.0;

    if ((0 == p) && (0 == n))
    {
        printf("0 to the 0 undefined, using 1 as the value.\n");
        return pow;
    }
    if (0 == n)
    {
        pow = 0.0;
        return pow;
    }
    if (0 == p)
    {
        return pow;
    }
    if (p > 0)
    {
        return n * power(n, p - 1);
    }
    else
    {
        return power(n, p + 1) / n;
    }
}
