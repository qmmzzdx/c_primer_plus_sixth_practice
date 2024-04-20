#include <stdio.h>
#define DAYS_PER_WEEK 7

int main(void)
{
    int n, week, days;

    printf("Please enter days (<=0 to quit): ");
    while ((scanf("%d", &n) == 1) && (n > 0))
    {
        week = n / DAYS_PER_WEEK;
        days = n % DAYS_PER_WEEK;
        printf("%d days are %d weeks, %d days.\n", n, week, days);
        printf("You can enter again (<=0 to quit): ");
    }

    return 0;
}
