#include <stdio.h>

int isprime(int x)
{
    for (int i = 2; i <= x / i; ++i)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int number;

    printf("Please enter a number (<= 0 to quit): ");
    while (scanf("%d", &number) == 1 && number > 0)
    {
        if (number == 1)
        {
            printf("1 isn't a prime!\n");
        }
        else
        {
            printf("Here are the prime (<= %d):\n", number);
            for (int i = 2; i <= number; i++)
            {
                if (isprime(i))
                {
                    printf("%d ", i);
                }
            }
        }
        printf("\nYou can enter again (<= 0 to quit): ");
    }
    printf("Done.\n");

    return 0;
}
