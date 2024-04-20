#include <stdio.h>
#define STOP '#'

int main(void)
{
    int ch, n = 0;

    printf("Enter some characters('#' to quit):\n");
    while ((ch = getchar()) != STOP)
    {
        if (ch == '.')
        {
            putchar('!');
            n++;
        }
        else if (ch == '!')
        {
            printf("!!");
            n++;
        }
        else
        {
            putchar(ch);
        }
    }
    printf("\nTotal replace %d times.\n", n);
    printf("('.'->'!') or ('!'->'!!').\n");

    return 0;
}
