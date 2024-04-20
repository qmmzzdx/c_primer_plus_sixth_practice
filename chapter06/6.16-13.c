#include <stdio.h>

int main(void)
{
    int a[8], val = 2;

    for (int i = 0; i < 8; i++)
    {
        a[i] = val, val *= 2;
    }
    int i = 0;
    printf("Here are the results for array:\n");
    do
    {
        printf("%d ", a[i++]);
    } while (i < 8);
    printf("\nDone.\n");

    return 0;
}
