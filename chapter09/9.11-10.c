#include <stdio.h>

void to_base_n(int x, int base);

int main(void)
{
    int b;
    long int n;

    printf("Please enter a number (q to quit): ");
    while (scanf("%ld", &n) == 1)
    {
        if (n <= 0)
        {
            printf("Illegal data! Please enter again: ");
            continue;
        }
        printf("Please enter a base system number (2 - 10): ");
        while (scanf("%d", &b) != 1 || b < 2 || b > 10)
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter again (2 - 10): ");
        }
        printf("%d in %d base system is: ", n, b);
        to_base_n(n, b);
        printf("\nYou can enter a number again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(int x, int base)
{
    int r;

    r = x % base;
    if (x >= base)
    {
        to_base_n(x / base, base);
    }
    printf("%d", r);
    return;
}
