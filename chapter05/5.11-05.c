#include <stdio.h>

int main(void)
{
    int count;

    printf("Enter the number of days you work: ");
    scanf("%d", &count);
    int n = count, sum = 0;
    while (count > 0)
    {
        sum += count--;
    }
    printf("You earned $%d in %d days.\n", sum, n);

    return 0;
}
