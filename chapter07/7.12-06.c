#include <stdio.h>
#define STOP '#'

int main(void)
{
    int cur, pre = '#', n = 0;

    printf("Enter some characters('#' to quit):\n");
    while ((cur = getchar()) != STOP)
    {
        if (pre == 'e' && cur == 'i') ++n;
        pre = cur;
    }
    printf("ei exists %d times totally.\n", n);

    return 0;
}
