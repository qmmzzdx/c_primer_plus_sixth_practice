#include <stdio.h>

void Fibonacci(int len);

int main(void)
{
    int n;

    printf("Please enter a integer (<= 0 or q to quit): ");
    while (scanf("%d", &n) == 1)
    {
        printf("Top %d items of Fibonacci sequence:\n", n);
        Fibonacci(n);
        printf("You can enter again (<= 0 or q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void Fibonacci(int len)
{
    int i;
    unsigned long t, x = 1, y = 1;

    for (i = 0; i < len; i++)
    {
        printf("%lu\n", x);
        t = x + y, x = y, y = t;
    }
    return;
}
