#include <stdio.h>

int main(void)
{
    int n, odd = 0, even = 0;
    int e_sum = 0, o_sum = 0;

    printf("Please enter a integer (0 to quit): ");
    while (scanf("%d", &n) == 1 && n > 0)
    {
        (n % 2 ? (++odd, o_sum += n) : (++even, e_sum += n));
        printf("You can enter again (0 to quit): ");
    }
    printf("Even numbers: %d\n", even);
    printf("The average of even numbers: %g\n", even > 0 ? (double)e_sum / even : 0);
    printf("Odd numbers: %d\n", odd);
    printf("The average of odd numbers: %g\n", odd > 0 ? (double)o_sum / odd : 0);
    printf("Done.\n");

    return 0;
}
