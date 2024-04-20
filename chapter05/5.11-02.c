#include <stdio.h>
#define LEN 10

int main(void)
{
    int n;
    int i = 0;

    printf("Please enter a number: ");
    scanf("%d", &n);

    printf("Print %d to %d:\n", n, n + 10);
    while (i <= LEN)
    {
        printf("%d ", n + i++);
    }
    printf("\nDone.\n");

    return 0;
}
