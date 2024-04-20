#include <stdio.h>

int main(void)
{
    int upp, low;

    printf("Enter lower and upper integer limits: ");
    while (scanf("%d %d", &low, &upp) == 2 && upp > low)
    {
        int sum = 0;
        for (int i = low; i <= upp; i++)
        {
            sum += i * i;
        }
        printf("The sums of the squares ");
        printf("from %d to %d is %d\n", low * low, upp * upp, sum);
        printf("Enter next set of limits: ");
    }
    printf("Done\n");

    return 0;
}
