#include <stdio.h>

int main(void)
{
    int n;

    printf("Please enter a number (<= 0 to quit): ");
    while ((scanf("%d", &n) == 1) && (n > 0))
    {
        double res1 = 0.0;
        double res2 = 0.0;
        for (int i = 1, flag = 1; i <= n; i++, flag *= -1)
        {
            res1 += 1.0 / i;
            res2 += (1.0 / i) * flag;
        }
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...");
        printf("sum are %g\n", res1);
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...");
        printf("sum are %g\n", res2);
        printf("The sum of the first %d items of the two sequences is %g\n", n, res1 + res2);
        printf("You can enter again (<= 0 to quit): ");
    }
    printf("Done.\n");

    return 0;
}
