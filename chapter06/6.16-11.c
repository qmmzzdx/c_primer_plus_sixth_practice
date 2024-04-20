#include <stdio.h>

int main(void)
{
    int a[8];

    printf("Please enter 8 numbers:\n");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Reverse order printing 8 numbers:\n");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
