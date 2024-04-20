#include <stdio.h>
#include <time.h>

void delay(const double second);

int main(void)
{
    double n;

    printf("please enter a number (<0 or q to quit): ");
    while (scanf("%lf", &n) == 1)
    {
        delay(n);
        printf("You can enter again (<0 or q to quit): ");
    }
    puts("Done.");

    return 0;
}

void delay(const double second)
{
    clock_t start = clock();
    clock_t end = clock();

    while (((double)(end - start) / CLOCKS_PER_SEC) < second)
    {
        end = clock();
    }
    printf("Delay %g seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    return;
}
